// Copyright 2024 Sokolova Daria

#include <cstring>
#include <exception>
#include <sstream>

#include "include/pol_not_app.h"

void PolNotApp::help(const char* appName, const char* errorMessage) {
    std::stringstream message;

    if (errorMessage) {
        message << "Error: " << errorMessage << '\n';
    }

    message << "Reverse Polish Notation Calculator\n"
            << "Usage: " << appName << " \"<math_expression>\"\n\n"
            << "Enter an expression in postfix notation to evaluate it.\n"
            << "Make sure to enclose the expression in double quotes.\n\n"
            << "Examples:\n"
            << appName << " \"5+6\" -> This will calculate 5 6 +\n"
            << appName << " \"(3*4)/2\" -> This will calculate 3 4 * 2 /\n";

    helpMessage = message.str();
}

bool PolNotApp::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }

    if (argc != 2) {
        help(argv[0], "You have to enter two arguments");
        return false;
    }

    try {
        input = argv[1];
    }
    catch (const std::exception&) {
        help(argv[0], "Invalid string");
        return false;
    }

    return true;
}

std::string PolNotApp::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        PolNot l1;

        auto* lex = l1.sEOL(input);

        helpMessage += "Result of revers polish notation: ";
        helpMessage += l1.revPolNot(lex);
    }
    return helpMessage;
}
