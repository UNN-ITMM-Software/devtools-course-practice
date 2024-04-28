// Copyright 2024 Videneva Ekaterina

#include "include/konovalov_i_euler_f_app.h"

#include <cstring>
#include <sstream>

bool EulerFunctionApplication::validate(int argc, char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc > 3) {
    help(argv[0], "the maximum number 1");
    return false;
  } else if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }

  if (std::strcmp(argv[1], "-naive") == 0) {
    mOption = Option::Naive;
  } else if (std::strcmp(argv[1], "-notnaive") == 0) {
    mOption = Option::NotNaive;
  }

  std::stringstream ss(argv[2]);
  if (ss.str() < "1") {
    help(argv[0],
        "Wrong number format n < 1, write --help to see how it is needed");
  }

  n = std::stoi(ss.str());
  return true;
}

void EulerFunctionApplication::help(const char* appName, const char* msg) {
  std::stringstream message;

  if (msg) message << "Error: " << msg << '\n';

  message << "This program calculates the Euler function";
  message << "in order for it to work";
  message << "you need to enter [option key]";
  message <<  " $ " + std::string(appName) +
      "which function you want, there are";
  message << "two flags [-notnaive] or [-naive]\n\n";
  message <<  "and after that we enter the value n, it has the type int\n\n";

  message_ = message.str();
}

std::string EulerFunctionApplication::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        std::stringstream ss;

        if (mOption == Option::NotNaive) {
          result = EulerFunction::euler(n);
        } else {
          result = EulerFunction::euler_naive(n);
        }

        ss << result;
        message_ = ss.str();
    }
    return message_;
}
