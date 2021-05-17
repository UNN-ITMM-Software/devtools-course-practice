// Copyright 2021 LoganovAndrei

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include "include/intersect_app.h"
#include "include/intersection_line.h"

LineApp::LineApp() : message_("") {}

void LineApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a check of the intersection of two line segments.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "x1, y1, ... x4, y4. \n\n"
        + "The first two coordinates are the first segment \n\n" \

        "Where all arguments are numbers. \n" \
        "Example: " + appname + " 1, 2, 3, ... 8.\n\n";
}

bool LineApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 9) {
        help(argv[0], "Should be 9 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string LineApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
       args.x1 = parseDouble(argv[1]);
       args.y1 = parseDouble(argv[2]);
       args.x2 = parseDouble(argv[3]);
       args.y2 = parseDouble(argv[4]);
       args.x3 = parseDouble(argv[5]);
       args.y3 = parseDouble(argv[6]);
       args.x4 = parseDouble(argv[7]);
       args.y4 = parseDouble(argv[8]);
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;
    std::pair <double, double> point1(args.x1, args.y1);
    std::pair <double, double> point2(args.x2, args.y2);
    std::pair <double, double> point3(args.x3, args.y3);
    std::pair <double, double> point4(args.x4, args.y4);
    Line l1(point1, point2);
    Line l2(point3, point4);
    bool tmp = l1.intersection(l2);
    stream.str("");
    if (tmp == true) {
        stream << "Intersect!";
    } else {
        stream << "No Intersect!";
    }
    message_ = stream.str();
    return message_;
}
