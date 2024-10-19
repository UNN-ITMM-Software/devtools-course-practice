// Copyright 2024 kasimtcev Roman

#ifndef MODULES_VIDENEVA_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_APPLICATION_H_
#define MODULES_VIDENEVA_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_APPLICATION_H_

#include <string>

#include "include/polynomial_calculator.h"

class polynomial_calculator_Application {
 public:
  polynomial_calculator_Application();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validatArgumentsStart(int argc, const char** argv);
  double parsePolynomial(const char* arg);
  int parseOperator(const char* arg);
  std::string message_;
  typedef struct {
    double x1, x2, x3, y1, y2, y3;
    char operation;
  } Arguments;
};

#endif  // MODULES_VIDENEVA_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_APPLICATION_H_
