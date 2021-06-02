// Copyright 2021 Lebedev Andrew

#ifndef MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLE_APPLICATION_H_
#define MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLE_APPLICATION_H_

#include <string>

#include "include/TrianglePoint.h"

class TriangleApplication {
 public:
    std::string operator()(int argc, const char** argv);

 private:
     std::string getHelp(const std::string& appname);
     double parseDouble(const char* arg);
};

#endif  // MODULES_TRIANGLE_POINT_INCLUDE_TRIANGLE_APPLICATION_H_
