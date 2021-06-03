// Copyright 2021 Ostapovich Denis

#include <string>

#include "include/application.h"

#include "include/json-deserializer.h"

using jsonDeserializer::Application;
using simpleDeserializer::JSONDeserializer;
using simpleDeserializer::JSONDocument;

Application::Application() : helpMessage("") {}

void Application::help(const char* appname, const char* message) {
  helpMessage =
      std::string(message) + "This is a json deserialization application.\n\n" +
      "Please provide arguments in the following format:\n\n" + "  $ " +
      appname + " <json data> <field> " + "Where all arguments are strings \n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 3) {
    help(argv[0], "ERROR: Should be 2 arguments.\n\n");
    return false;
  }
  return true;
}

std::string Application::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return helpMessage;
  }

  JSONDeserializer deserializer(argv[1]);
  JSONDocument json;

  try {
    json = deserializer.parse();
  } catch (std::string& str) {
    return str;
  }

  return json[argv[2]].to<std::string>();
}
