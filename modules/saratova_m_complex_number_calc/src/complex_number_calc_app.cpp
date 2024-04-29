// Copyright 2024 Smirnova Darya

#include "include/complex_number_calc_app.h"

#include <cstring>
#include <exception>
#include <sstream>

bool ComplexCalculatorApplication::Validate(int argc, char *argv[]) {
    int required_argc = 6;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (argc != required_argc) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else if (std::strcmp(argv[5], "+") != 0
     && std::strcmp(argv[5], "-") != 0
     && std::strcmp(argv[5], "*") != 0
     && std::strcmp(argv[5], "/") != 0) {
        Help(argv[0], "Operation must be either '+' or '-' or '*' or '/'.");
        return false;
    } else {
        try {
            double re1 = std::stod(argv[1]);
            double im1 = std::stod(argv[2]);
            double re2 = std::stod(argv[3]);
            double im2 = std::stod(argv[4]);

            num1 = ComplexCalculator(re1, im1);
            num2 = ComplexCalculator(re2, im2);
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }
    return true;
}

void ComplexCalculatorApplication::Help(const char *application,
                                         const char *errMsg) {
    std::stringstream message;

    if (errMsg) {
        message << "Error: " << errMsg << '\n';
    }

    message << "Usage:\n";
    message << '\t' << application << " <re1> <im1> <re2> <im2> <operation>\n";
    message << "Where:\n";
    message << '\t' << " <re1> and <im1> are components of first number\n";
    message << '\t' << " <re2> and <im2> are components of second number\n";
    message << '\t' << " <operation> is the current operation\n";
    msg = message.str();
}

std::string ComplexCalculatorApplication::ComplexCalculatorCalculation
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            if (std::strcmp(argv[5], "+") == 0) {
                result = num1 + num2;
                return result.toString();
            } else if (std::strcmp(argv[5], "-") == 0) {
                result = num1 - num2;
                return result.toString();
            } else if (std::strcmp(argv[5], "*") == 0) {
                result = num1 * num2;
                return result.toString();
            } else if (std::strcmp(argv[5], "/") == 0) {
                result = num1 / num2;
                return result.toString();
            }
        }
        catch(const std::exception& e) {
            return "Error: Invalid input.";
        }
    }
    return msg;
}
