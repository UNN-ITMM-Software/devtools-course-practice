// Copyright 2021 ParanichevaAlyona

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUAD_EQUATION_APP_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUAD_EQUATION_APP_H_

#include <string>

class QuadEquationApp {
 public:
    QuadEquationApp();

    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     using Arguments = struct {
         double a;
         double b;
         double c;
     };
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUAD_EQUATION_APP_H_
