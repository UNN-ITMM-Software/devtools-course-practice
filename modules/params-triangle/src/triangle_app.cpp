// Copyright 2021 Molotkova Svetlana

#include <stdlib.h>

#include <iostream>
#include <string>
#include <sstream>
#include <utility>

#include "include/triangle_app.h"
#include "include/triangle.h"

TriangleApp::TriangleApp() : message_("") {}

void TriangleApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a triangle parameters calculator application.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "x1, y1, x2, y2, x3, y3 \n\n"  \

        "Where all arguments are numbers. \n" \
        "Example: " + appname + " 1, 3, 2, 4, 6, 7.\n\n";
}

bool TriangleApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 7) {
        help(argv[0], "Should be 6 arguments.\n\n");
        return false;
    }
    return true;
}

bool TriangleApp::validateArguments(const char** argv, std::pair <double,
    double> a, std::pair <double, double> b, std::pair <double, double> c) {
    if ((a == b) || (a == c) || (b == c)) {
        help(argv[0], "Points must be different.\n\n");
        return true;
    }
    return false;
}

bool TriangleApp::validateTriangle(const char** argv, double area) {
    if (area == 0) {
        help(argv[0], "It is not a triangle.\n\n");
        return true;
    }
    return false;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string TriangleApp::operator()(int argc, const char** argv) {
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
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;
    std::pair <double, double> a(args.x1, args.y1);
    std::pair <double, double> b(args.x2, args.y2);
    std::pair <double, double> c(args.x3, args.y3);
    if (validateArguments(argv, a, b, c)) {
        return message_;
    }
    Triangle triangle(a, b, c);
    double AB = triangle.SideAB();
    double BC = triangle. SideBC();
    double AC = triangle.SideAC();
    stream << AB << ",  "<< BC << ", " << AC << " ";
    double p = triangle.Perimeter();
    double s = triangle.Area();
    if (validateTriangle(argv, s)) {
        return message_;
    }
    stream << "Perimeter = " << p << ", Area = "
        << s << ".";
    message_ = stream.str();
    return message_;
}
