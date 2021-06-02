// Copyright 2021 LoganovAndrei
#include <string>
#ifndef MODULES_INTERSECTION_LINE_INCLUDE_INTERSECT_APP_H_
#define MODULES_INTERSECTION_LINE_INCLUDE_INTERSECT_APP_H_
class LineApp {
 public:
    LineApp();

    std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     using Arguments = struct {
        double x1;
        double y1;
        double x2;
        double y2;
        double x3;
        double y3;
        double x4;
        double y4;
     };
};
#endif  // MODULES_INTERSECTION_LINE_INCLUDE_INTERSECT_APP_H_
