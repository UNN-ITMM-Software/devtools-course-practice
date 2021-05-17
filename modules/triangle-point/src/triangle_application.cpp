// Copyright 2021 Lebedev Andrew

#include <algorithm>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <string>
#include <cstring>

#include "include/triangle_application.h"

std::string TriangleApplication::operator()(int argc, const char ** argv) {
    try {
        if (argc == 1) {
            return getHelp(argv[0]);
        }
        if (argc != 9) {
            throw std::runtime_error("ERROR: must be 8 arguments.\n");
        }
        std::pair<double, double> a
            (parseDouble(argv[1]), parseDouble(argv[2]));
        std::pair<double, double> b
            (parseDouble(argv[3]), parseDouble(argv[4]));
        std::pair<double, double> c
            (parseDouble(argv[5]), parseDouble(argv[6]));
        std::pair<double, double> p
            (parseDouble(argv[7]), parseDouble(argv[8]));
        Triangle tr(a, b, c);
        if (tr.isInside(p)) {
            return "Point is inside.\n";
        } else {
            return "Point is outside.\n";
        }
    }

    catch(std::exception& ex) {
        return ex.what();
    }
}

std::string TriangleApplication::getHelp(const std::string& appname) {
        return "\nThis is a triangle-point application.\n" \
        "Please provide arguments in the following format:\n\n"
        "$ " + appname + " <x1> <y1> ... <x4> <y4> \n\n"
        "First three pairs are coordinates of triangle's vertices\n"
        "Last two arguments are point coordinates\n"
        "All arguments are real numbers.\n";
}


double TriangleApplication::parseDouble(const char* arg) {
    std::string str(arg);
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != '.' && str[i] != '-' && (str[i] < '0'
            || str[i] > '9')) {
            throw std::runtime_error("ERROR: Wrong format.\n");
        }
    }
    return std::strtod(arg, nullptr);
}
