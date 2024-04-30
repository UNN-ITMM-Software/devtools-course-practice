// Copyright 2024 Derun Andrey

#include "include/metrics_app.h"

#include <cstring>
#include <sstream>
#include <string>

#include "include/metrics.h"

MetricsApp::MetricsApp() : message_("") {}

void MetricsApp::help(const char* appname, const char* message) {
  std::stringstream ss;
  ss << std::string(message) << "This is a metrics calculator application.\n\n";
  ss << "Please provide arguments in the following format:\n\n";
  ss << "  $ " << appname << " <v1> <v2> "
     << "<operation>\n\n ";
  ss << "Where vectors are in the format of 1,2,3 or 1.0,2.0,3.0 ";
  ss << "and <operation> is one of 'l1', 'l2', 'l3', 'l4' or 'linf'.\n";
  message_ = ss.str();
}

bool MetricsApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }
  return true;
}

std::vector<float> parseVector(const char* input) {
  std::vector<float> result;
  std::stringstream ss(input);
  std::string token;

  while (std::getline(ss, token, ',')) {
    try {
      float number = std::stof(token);
      result.push_back(number);
    } catch (const std::invalid_argument& e) {
      throw std::logic_error("Wrong vector format!");
      continue;
    } catch (const std::out_of_range& e) {
      throw std::logic_error("Wrong vector format!");
      continue;
    }
  }

  return result;
}

std::string parseOperation(const char* arg) {
  std::string op;
  if (std::strcmp(arg, "l1") == 0) {
    op = "l1";
  } else if (strcmp(arg, "l2") == 0) {
    op = "l2";
  } else if (strcmp(arg, "l3") == 0) {
    op = "l3";
  } else if (strcmp(arg, "l4") == 0) {
    op = "l4";
  } else if (strcmp(arg, "linf") == 0) {
    op = "linf";
  } else {
    throw std::logic_error("Wrong operation format!");
  }
  return op;
}

std::string MetricsApp::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.v1 = parseVector(argv[1]);
    args.v2 = parseVector(argv[2]);
    args.op = parseOperation(argv[3]);
  } catch (const std::exception& e) {
    return e.what();
  }

  std::ostringstream stream;
  try {
    switch (args.op[1]) {
      case '1':
        stream << "Metric = " << metrics::l1(args.v1, args.v2);
        break;
      case '2':
        stream << "Metric = " << metrics::l2(args.v1, args.v2);
        break;
      case '3':
        stream << "Metric = " << metrics::l3(args.v1, args.v2);
        break;
      case '4':
        stream << "Metric = " << metrics::l4(args.v1, args.v2);
        break;
      case 'i':
        stream << "Metric = " << metrics::l4(args.v1, args.v2);
        break;
    }
  } catch (const std::exception& e) {
    return e.what();
  }

  message_ = stream.str();

  return message_;
}
