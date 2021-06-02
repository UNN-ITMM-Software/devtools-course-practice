// Copyright 2021 Skripal Andrey

#ifndef MODULES_INTERSECTLINEANDPLANE_INCLUDE_LIAP_APP_H_
#define MODULES_INTERSECTLINEANDPLANE_INCLUDE_LIAP_APP_H_

#include <string>
#include <utility>
#include "include/ilap.h"

class PointApp {
 public:
    PointApp();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    using Arguments = struct {
        double x1;
        double y1;
        double z1;
        double x2;
        double y2;
        double z2;
        double x3;
        double y3;
        double z3;
        double x4;
        double y4;
        double z4;
        double x5;
        double y5;
        double z5;
    };
};

#endif  // MODULES_INTERSECTLINEANDPLANE_INCLUDE_LIAP_APP_H_
