// Copyright 2024 Morgachev Stepan

#include <cstring>
#include <exception>
#include <sstream>

#include "include/levenshtein_distance_app.h"

void LevenshteinApp::help(const char *appName, const char *errorMessage) {
    std::stringstream message;

    if (errorMessage) {
        message << "Error: " << errorMessage << '\n';
    }

    message << "This is an application that"
            << " calculates the Levenshtein distance between two strings.\n";
    message << "Usage:\n";
    message << "  " << appName << " <first_string> <second_string>\n";
    message << '\n';
    message << "Parameters:\n";
    message << "  <first_string>    "
            << "The first string for calculating the Levenshtein distance.\n";
    message << "  <second_string>   "
            << "The second string for calculating the Levenshtein distance.\n";
    message << '\n';
    message << "Options:\n";
    message << "  --help    Display this help message.\n";
    message << '\n';
    message << "Example:\n";
    message << "  " << appName << " cat dog\n";
    message << '\n';

    helpMessage = message.str();
}

bool LevenshteinApp::validate(int argc, char *argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }

    if (argc != 3) {
        help(argv[0], "You have to enter three arguments");
        return false;
    }

    try {
        firstString = argv[1];
        secondString = argv[2];
    } catch (const std::exception &) {
        help(argv[0], "Invalid string");
        return false;
    }

    return true;
}

std::string LevenshteinApp::operator()(int argc, char *argv[]) {
    if (validate(argc, argv)) {
        LevenshteinDistance levenshtein(firstString, secondString);
        helpMessage += "The Levenshtein distance between '";
        helpMessage += firstString;
        helpMessage += "' and '";
        helpMessage += secondString;
        helpMessage += "' is: ";
        helpMessage += std::to_string(levenshtein.getResult());
    }
    return helpMessage;
}
