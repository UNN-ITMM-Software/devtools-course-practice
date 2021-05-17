// Copyright 2021 Bezrodnov Dmitry

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>


#include "include/hanoi_application.h"

std::string HanoiApplication::help(const std::string& appname) {
        return "This is an application for solving task Hanoi tower\n"\
        "Please provide arguments in the following format:\n"+
        appname + " <number_of_rings> " +
        "Where the argument is a positive integer less than 20.";
}

bool HanoiApplication::CheckArgument(const std::string& str) {
    if (str.size() == 1) {
        int value_symbol = static_cast<int>(str[0]);
        if ((value_symbol >= 48) && (value_symbol <= 57))
            return true;
    } else {
        if (str.size() == 2) {
            if (static_cast<int>(str[0]) == 49) {
                int value_symbol = static_cast<int>(str[1]);
                if ((value_symbol >= 48) && (value_symbol <= 57))
                    return true;
            }
        }
    }
    return false;
}

int HanoiApplication::parseArgument(const char* arg) {
    if (!CheckArgument(arg)) {
        throw std::runtime_error("ERROR: Wrong format\n");
    }
    return std::stoi(arg);
}

std::string HanoiApplication::operator()(int argc, const char** argv) {
    int _size;
    if (argc == 1) {
        return help(argv[0]);
    }
    try {
        if (argc != 2) {
            throw  std::runtime_error("ERROR: Should be 1 arguments\n");
        }
        _size = parseArgument(argv[1]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }

    std::ostringstream stream;

    Hanoi h_t(_size);
    std::stack<int> testA = h_t.GetTowerA(),
        testB = h_t.GetTowerB(), testC = h_t.GetTowerC();

    h_t.ring(_size, &testA, &testB, &testC);
    stream << "Number of permutations of rings = "
            << std::to_string(h_t.get_permutations());
    return stream.str();
}
