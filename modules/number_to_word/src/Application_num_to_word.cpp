// Copyright 2021 Romanuyk Sergey
#include <stdlib.h>

#include <iostream>
#include <string>
#include <sstream>
#include <utility>

#include "include/Application_num_to_word.h"
#include "include/number_to_word.h"

NumToWord::NumToWord() : message_("") {}

void NumToWord::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a number-to-string translation app.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "x \n\n"  \
    "Where the argument is a number. \n" \
        "Example: " + appname + " 1.\n\n";
}

bool NumToWord::validateNumberOfArguments(int argc, const char** argv) {
    if (argc != 2) {
        help(argv[0], "Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    double value = strtol(arg, &end, 0);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    if (value <= 0) {
        throw std::string("Number must be positive!");
    }

    return value;
}

std::string NumToWord::operator()(int argc, const char** argv) {
    int x;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        x = parseInt(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    num_to_word n(x);
    n.num2word();

    stream << "x = " << n.get_word();

    message_ = stream.str();
    return message_;
}
