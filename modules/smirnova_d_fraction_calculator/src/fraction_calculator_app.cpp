// Copyright 2024 Saratova Marina

#include "include/fraction_calculator_app.h"

#include <cstring>
#include <exception>
#include <sstream>

bool FractionCalculatorApplication::Validate(int argc, char *argv[]) {
    int required_argc = 6;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[5], "+") != 0
     && std::strcmp(argv[5], "-") != 0
     && std::strcmp(argv[5], "*") != 0
     && std::strcmp(argv[5], "/") != 0) {
        Help(argv[0], "Operation must be either '+' or '-' or '*' or '/'");
        return false;
    } else if (argc != required_argc) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else {
        try {
            int first_num = std::stoi(argv[1]);
            int first_den = std::stoi(argv[2]);
            int second_num = std::stoi(argv[3]);
            int second_den = std::stoi(argv[4]);

            first = FractionCalculator(first_num, first_den);
            second = FractionCalculator(second_num, second_den);
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void FractionCalculatorApplication::Help(const char *application,
                                         const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' << application << " <num1> <den1> <num2> <den2> <op>\n";
    message << "Where:\n";
    message << '\t' << " <num1> and <den1> is first fraction\n";
    message << '\t' << " <num2> and <den2> is second fraction\n";
    message << '\t' << " <op> is the current operation\n";
    msg = message.str();
}

std::string FractionCalculatorApplication::FractionCalculation
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            if (std::strcmp(argv[5], "+") == 0) {
                result = first + second;
                return result.ToString();
            } else if (std::strcmp(argv[5], "-") == 0) {
                result = first - second;
                return result.ToString();
            } else if (std::strcmp(argv[5], "*") == 0) {
                result = first * second;
                return result.ToString();
            } else if (std::strcmp(argv[5], "/") == 0) {
                result = first / second;
                return result.ToString();
            }
        }
        catch(const std::exception& e) {
            return "Error: Invalid input data.";
        }
    }
    return msg;
}
