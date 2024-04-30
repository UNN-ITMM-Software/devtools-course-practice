// Copyright 2024 Ivanov Nikita
#include "include/lcs.h"
#include "include/lcs_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>

LCSApp::LCSApp() : message_("") {}

void LCSApp::help(const char* appname, const char* message) {
    message_ =
            std::string(message) +
            "This is LCSApp application.\n\n" +
            "Please provide arguments in the following format:\n\n" +

            "<str1_std::string> <str2_std::string>";
}

bool LCSApp::validateNumberOfArguments(int argc, const char** argv) {
    std::cout << argc << std::endl;
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

std::string LCSApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    args.str1 = argv[1];
    args.str2 = argv[2];

    std::ostringstream stream;

    stream << "LCS = " << LCS::findLCS(args.str1, args.str2);

    message_ = stream.str();

    return message_;
}
