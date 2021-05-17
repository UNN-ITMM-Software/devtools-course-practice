// Copyright 2021 ParanichevaAlyona

#include <stdlib.h>

#include <iostream>
#include <string>
#include <sstream>
#include <utility>

#include "include/quad_equation_app.h"
#include "include/QuadraticEquation.h"

QuadEquationApp::QuadEquationApp() : message_("") {}

void QuadEquationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a quadratic equations calculator application.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "<a> <b> <c> \n\n" \

        "Where all arguments are numbers. \n" \
        "Example: " + appname + " 2 -3 7.\n\n";
}

bool QuadEquationApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "Should be 3 arguments.\n\n");
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

std::string QuadEquationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.a = parseDouble(argv[1]);
        args.b = parseDouble(argv[2]);
        args.c = parseDouble(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    try {
        QuadraticEquation eq(args.a, args.b, args.c);
        std::pair <double, double> res = eq.solver();
        stream << "First root = " << res.first << ", second root = "
            << res.second << ".";
        message_ = stream.str();
    }
    catch (std::string& str) {
        return str;
    }

    return message_;
}
