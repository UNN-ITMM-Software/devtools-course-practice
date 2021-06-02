// Copyright 2021 Makarychev Sergey



#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "include/romanumber_application.h"
#include "include/romanumber.h"

RomaNumberApplication::RomaNumberApplication() : message_("") {}

void RomaNumberApplication::help(const char* appname, const char* message ) {
    message_ =
        std::string(message) +
        "It is a Converter from Arab numbers to Rom numbers and back.\n\n" \
        "Please provide arguments in the following format:\n\n" \

        " $ " + appname + " <type of conversion> " \
        "<your number to convert>\n\n" \

        "Where your number to convert is integer or string argument, \n" \
         "type of conversion is integer number, where \n" \
        "1 - from Arabic to Roman \n2 - from Roman to Arabic ";
}

bool RomaNumberApplication::validateNumberOfArguments(int argc,
const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(arg);
    if (value != 1 && value != 2) {
        throw std::string("Error: Wrong number format.\n\n");
    }
    return value;
}


std::string RomaNumberApplication::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    RomaNumber num;
    std::ostringstream stream;
    int change;
    try {
        change = parseInt(argv[1]);
    } catch(const std::string& str) {
        return str;
    }
    try {
        if (change == 1) {
            num.arabToRoma(std::stoi(argv[2]));
            stream << "Arabic to Roman = " << num.getRoma();
        } else if (change == 2) {
            num.romaToArab(argv[2]);
            stream << "Roman to Arabic = " << num.getArabic();
        }
    } catch(const std::string& str) {
        return str;
    }
    message_ = stream.str();
    return message_;
}
