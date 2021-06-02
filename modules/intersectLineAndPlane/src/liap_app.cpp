// Copyright 2021 Skripal Andrey
#include <stdlib.h>

#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <limits>

#include "include/liap_app.h"
#include "include/ilap.h"

PointApp::PointApp() : message_("") {}

void PointApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a intersection line and plane application.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "x1, y1, z1, ... x5, y5, z5 \n\n"
        + "The first two coordinates - line, the rest define the plane \n\n" \

        "Where all arguments are numbers. \n" \
        "Example: " + appname + " 1, 2, 3, ... 13, 14, 15 .\n\n";
}

bool PointApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 16) {
        help(argv[0], "Should be 16 arguments.\n\n");
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

std::string PointApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x1 = parseDouble(argv[1]);
        args.y1 = parseDouble(argv[2]);
        args.z1 = parseDouble(argv[3]);
        args.x2 = parseDouble(argv[4]);
        args.y2 = parseDouble(argv[5]);
        args.z2 = parseDouble(argv[6]);
        args.x3 = parseDouble(argv[7]);
        args.y3 = parseDouble(argv[8]);
        args.z3 = parseDouble(argv[9]);
        args.x4 = parseDouble(argv[10]);
        args.y4 = parseDouble(argv[11]);
        args.z4 = parseDouble(argv[12]);
        args.x5 = parseDouble(argv[13]);
        args.y5 = parseDouble(argv[14]);
        args.z5 = parseDouble(argv[15]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    double max = std::numeric_limits<double>::max();
    Point A, B, C, D, E, F;
    A.x = args.x1;
    A.y = args.y1;
    A.z = args.z1;
    B.x = args.x2;
    B.y = args.y2;
    B.z = args.z2;
    C.x = args.x3;
    C.y = args.y3;
    C.z = args.z3;
    D.x = args.x4;
    D.y = args.y4;
    D.z = args.z4;
    E.x = args.x5;
    E.y = args.y5;
    E.z = args.z5;
    F.PlaneIntersectLine(A, B, C, D, E);
    stream << "x = " << F.x << ", y = "
        << F.y << ", z = " << F.z;
    if ((F.x == max) && (F.y == max) && (F.z == max)) {
        stream.str("");
        stream << "No intersection";
    }
    message_ = stream.str();
    return message_;
}
