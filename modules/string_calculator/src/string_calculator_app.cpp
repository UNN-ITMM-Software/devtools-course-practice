// Copyright 2021 Tsvetkov Maxim

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cassert>

#include "include/string_calculator.h"
#include "include/string_calculator_app.h"

std::string StringCalculatorApp::help(const std::string& filename) {
    return "This is an simple String calculator application. " \
        "It return sum of given arguments. \n\n" \
        "Please provide arguments in the following format:\n$ " +
        filename + " [operation from {+,-,*}]" +
        " \"[delimiter]\\n[numbers...]\"\n" \
        "Example: " + filename + " + \";\\n1;2\" \n\n";
}

std::string StringCalculatorApp::operator()(int argc, const char** argv) {
    if (argc != 3) {
        return help(argv[0]);
    }

    std::ostringstream ss;
    int res;
    try {
        if (argv[1][0] == '+') {
            res = StringCalculator::add(argv[2]);
        } else {
            if (argv[1][0] == '-') {
                res = StringCalculator::subtract(argv[2]);
            } else {
                res = StringCalculator::multiplicate(argv[2]);
            }
        }
    } catch (std::exception& exc) {
        return exc.what() + help(argv[0]);
    }
    ss << res;
    return ss.str();
}
