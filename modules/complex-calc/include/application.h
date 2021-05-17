// Copyright 2021 Chirkov Roman

#ifndef MODULES_COMPLEX_CALC_INCLUDE_APPLICATION_H_
#define MODULES_COMPLEX_CALC_INCLUDE_APPLICATION_H_

#include <string>

#include "include/complex_number.h"

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

  void help(const char* appname, std::string message = "");

  /* function checkMode
   * @return char
   *   1 for help and displaying arguments errors,
   *   2 for calculating an operation on two complex numbers
   */
  char checkMode(int argc, const char** argv);
  std::string getError();

 private:
  Complex leftOperand;
  Complex rightOperand;
  char operation;

  std::string error = "";
  std::string helpMessage = "";
};

#endif  // MODULES_COMPLEX_CALC_INCLUDE_APPLICATION_H_
