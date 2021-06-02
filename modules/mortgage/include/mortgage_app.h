// Copyright 2021 Ludina Daria

#ifndef MODULES_MORTGAGE_INCLUDE_MORTGAGE_APP_H_
#define MODULES_MORTGAGE_INCLUDE_MORTGAGE_APP_H_

#include <string>

class mortgage_app {
 public:
  mortgage_app();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
  struct Arguments {
    int c_cost;
    int d_downPayment;
    int c_creditTerm;
    double i_interestRate;
  };
};

#endif  // MODULES_MORTGAGE_INCLUDE_MORTGAGE_APP_H_
