// Copyright 2024 Martynov Aleksandr

#include <sstream>
#include "include/NumSysApplication.hpp"
#include "include/CustomNSNumber.hpp"


#define REQ_ARGC 6

std::string NumSysApplication::Parse(int argc, char *argv[]) {
  if (Validate(argc, argv)) {
    std::string string1;
    std::string string2;
    std::string string3;
    std::string string4;
    std::string string5;

    string1 = argv[1];  // num_1
    string2 = argv[2];  // base_1
    CustomNSNumber num_1;
    CustomNSNumber num_2;
    try {
      num_1 = CustomNSNumber(string1, std::stoul(string2));
    } catch (...) {
      Help(argv[0], "Incorrect string element in first number");
      return message_;
    }

    string4 = argv[4];  // num_2_
    string5 = argv[5];  // base_2
    try {
      num_2 = CustomNSNumber(string4, std::stoul(string5));
    } catch (...) {
      Help(argv[0], "Incorrect string element in second number.");
      return message_;
    }

    string3 = argv[3];  // base_2
    CustomNSNumber num_res;
    bool op_res;
    switch (string3[0]) {
    case '+':
      num_res = num_1 + num_2;
      std::cout << num_res << std::endl;
      break;
    case '-':
      num_res = num_1 - num_2;
      std::cout << num_1 << " - " << num_2 << " = " << num_res << std::endl;
      break;
    case '=':
      op_res = (num_1 == num_2);
      std::cout << num_1 << " == " << num_2 << " : " << op_res << std::endl;
      break;
    case '<':
      op_res = (num_1 < num_2);
      std::cout << num_1 << " < " << num_2 << " : " << op_res << std::endl;
      break;
    case '>':
      op_res = (num_1 > num_2);
      std::cout << num_1 << " > " << num_2 << " : " << op_res << std::endl;
      break;
    default:
      Help(argv[0], "Unknown operation.");
      return message_;
    }
  }

  return message_;
}

bool NumSysApplication::Validate(int argc, char *argv[]) {
  std::string help_str("--help");
  if (argc == 1) {
    Help(argv[0]);
    return false;
  } else if (help_str.compare(argv[1]) == 0) {
    Help(argv[0]);
    return false;
  } else if (argc != REQ_ARGC) {
    Help(argv[0], "Invalid number of arguments.");
    return false;
  }
  return true;
}

void NumSysApplication::Help(const char *application, const char *message) {
  std::stringstream _message;

  if (message) {
    _message << "Error: " << message << '\n';
  } else {
    _message << "This is a numeric system calculator.\n";
  }

  _message << "Usage:\n";
  _message << '\t' << application
           << " <first number> <first base> <operation> <second number> "
              "<second base> \n";
  _message << "Where:\n";
  _message
      << '\t'
      << "<first base>, <second base> are input numbers' numeric systems.\n";
  _message << '\t'
           << "<first number>, <second number> are input numbers (all digits "
              "should be separated by spaces) (negative number should have '- "
              "' in front of it).\n";
  _message
      << '\t'
      << "<operation> is operation over numbers (+ (sum), - (sub), * "
         "(mult), = (check equality), < (check lesser), > (check greater)).\n";
  message_ = _message.str();
}

