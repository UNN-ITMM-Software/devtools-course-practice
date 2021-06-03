// Copyright 2021 Ostapovich Denis

#include "include/application.h"

#include <string>

#include "include/json-deserializer.h"

using jsonDeserializer::Application;
using jsonDeserializer::OperationMode;
using simpleDeserializer::JSONDeserializer;
using simpleDeserializer::JSONDocument;
using std::string;

Application::Application() : helpMessage("") {}

void Application::help(const char* appname, const char* message) {
  helpMessage = string(message) +
                "This is a json deserialization application.\n\n" +
                "Please provide arguments in the following format:\n\n" +
                "  $ " + appname + " -o <json data> <field> " +
                "Where <json data> <field> are strings\n\n" + appname +
                " -a <json array> <index> " +
                "Where <json array> is string and <index> is unsigned int "
                "greater than or equal to zero\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }
  return true;
}

OperationMode selectOperationMode(const char* arg) {
  OperationMode mode = OperationMode::Object;

  if (strcmp(arg, "-a") == 0) {
    mode = OperationMode::Array;
  }

  return mode;
}

string Application::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return helpMessage;
  }

  OperationMode mode = selectOperationMode(argv[1]);

  JSONDeserializer deserializer(argv[2]);
  JSONDocument json;

  try {
    json = deserializer.parse();
  } catch (string& e) {
    help(argv[0], e.c_str());
    return helpMessage;
  }

  if (mode == OperationMode::Object) {
    return json[argv[3]].to<string>();
  }

  int index;
  try {
    index = std::stoi(argv[3]);
  } catch (std::invalid_argument& e) {
    return "Can't parse array index";
  } catch (std::out_of_range& e) {
    return "Index is out of range";
  }

  if (index < 0) {
    return "Array index must be equal to or greater than zero";
  }

  return json[index].to<string>();
}
