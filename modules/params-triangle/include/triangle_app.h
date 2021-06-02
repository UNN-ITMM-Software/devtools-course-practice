// Copyright 2021 Molotkova Svetlana

#ifndef MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_APP_H_
#define MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_APP_H_

#include <string>
#include <utility>
#include "include/triangle.h"

class TriangleApp {
 public:
    TriangleApp();

    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     bool validateArguments(const char** argv,  std::pair <double, double> a,
        std::pair <double, double> b, std::pair <double, double> c);
     bool validateTriangle(const char** argv, double area);
     std::string message_;
     using Arguments = struct {
         double x1;
         double y1;
         double x2;
         double y2;
         double x3;
         double y3;
     };
};

#endif  // MODULES_PARAMS_TRIANGLE_INCLUDE_TRIANGLE_APP_H_
