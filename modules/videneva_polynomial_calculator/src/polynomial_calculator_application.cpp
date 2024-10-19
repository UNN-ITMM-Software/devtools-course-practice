// Copyright 2024 kasimtcev Roman

#include "include/polynomial_calculator_application.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sstream>
#include <string>
#include <vector>

#include "include/polynomial_calculator.h"

polynomial_calculator_Application::polynomial_calculator_Application()
    : message_("") {}

void polynomial_calculator_Application::help(const char* appname,
                                             const char* message) {
  message_ = std::string(message) +
             "This is a polynomial calculator application.\n\n" +
             "Please provide arguments in the following format:\n\n" +

             "  $ " + appname + " <coeff_x^2> <coeff_x> <coeff_> " +
             "<coeff_x^2> <coeff_x> <coeff_> <operation>\n\n" +

             "Where all arguments are double-precision numbers, " +
             "and <operation> is one of '+', '-', '*'.\n";
}

bool polynomial_calculator_Application::validatArgumentsStart(
    int argc, const char** argv) {
  if (argc != 8) {
    help(argv[0], "ERROR: invalid number of arguments.\n\n");
    return false;
  }
  return true;
}

double polynomial_calculator_Application::parsePolynomial(const char* arg) {
  char* end;
  double value = strtod(arg, &end);

  if (end[0]) {
    throw std::string("ERROR: Wrong value format!");
  }
  return value;
}

int polynomial_calculator_Application::parseOperator(const char* arg) {
  char op;
  if (strcmp(arg, "+") == 0) {
    op = '+';
  } else if (strcmp(arg, "-") == 0) {
    op = '-';
  } else if (strcmp(arg, "*") == 0) {
    op = '*';
  } else {
    throw std::string("ERROR: Wrong operation format!");
  }
  return op;
}

std::string polynomial_calculator_Application::operator()(int argc,
                                                          const char** argv) {
  Arguments args;
  polynomial_calculator result;
  std::ostringstream stream;
  std::vector<double> x;
  std::vector<double> y;
  int i = 1;

  if (!validatArgumentsStart(argc, argv)) {
    return message_;
  }

  try {
    args.x1 = parsePolynomial(argv[i]);
    args.x2 = parsePolynomial(argv[i + 1]);
    args.x3 = parsePolynomial(argv[i + 2]);
    args.y1 = parsePolynomial(argv[i + 3]);
    args.y2 = parsePolynomial(argv[i + 4]);
    args.y3 = parsePolynomial(argv[i + 5]);
    args.operation = parseOperator(argv[i + 6]);
  } catch (std::string& str) {
    return str;
  }

  x.push_back(args.x1);
  x.push_back(args.x2);
  x.push_back(args.x3);
  y.push_back(args.y1);
  y.push_back(args.y2);
  y.push_back(args.y3);
  polynomial_calculator X(x, 3);
  polynomial_calculator Y(y, 3);

  switch (args.operation) {
    case '+':
      result = X + Y;
      std::cout << "Result=" << result;
      break;
    case '-':
      result = X - Y;
      std::cout << "Result=" << result;
      break;
    case '*':
      result = X * Y;
      std::cout << "Result=" << result;
      break;
  }
  return message_;
}
