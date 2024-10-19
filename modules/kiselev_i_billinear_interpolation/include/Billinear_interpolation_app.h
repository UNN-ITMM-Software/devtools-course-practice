// Copyright 2024 Bodrov Daniil
#ifndef MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_APP_H_
#define MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_APP_H_

#include <string>

class BillinearInterpolationApp {
 public:
  BillinearInterpolationApp();

  std::string operator()(int argc, char* argv[]);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, char* argv[]);
  std::string message_;
};

#endif  // MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_APP_H_
