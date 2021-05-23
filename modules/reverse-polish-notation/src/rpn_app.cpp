// Copyright 2021 Aleksandrychev Andrey
#include <iostream>
#include <string>
#include <sstream>

#include "include/rpn_app.h"
#include "include/rpn.h"

RPN_App::RPN_App() : message_("") {}

void RPN_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application, that create reverse polish notation.\n\n" +
        "Please provide arguments in the following format:\n"
        + "1+(2-3)*4/5^6..... 7 \n\n"
        + "Where second digit is length of source string\n\n";
}

bool RPN_App::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "Should be 3 arguments.\n\n");
        return false;
    }

    return true;
}

std::string RPN_App::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) { return message_; }

    std::ostringstream stream;

    std::string arg_string;
    int count = std::strtol(argv[2], nullptr, 10);

    for (int i = 0; i < count; i++) {
        arg_string += argv[1][i];
    }

    RPN rpn(arg_string);
    std::string rpn_line = rpn.getLine();

    stream << rpn_line;
    message_ = stream.str();
    return message_;
}
