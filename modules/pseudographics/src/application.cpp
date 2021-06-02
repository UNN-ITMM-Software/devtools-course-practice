// Copyright 2021 Chistov Vladimir

#include <sstream>
#include <string>
#include <vector>

#include "include/application.h"
#include "include/Pseudographics.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This app prints numbers with dots and lines.\n\n" \
        "Please provide arguments in the following format:\n" \
        " $" + appname + "  123 or 5435 or 41 etc \n\n"  \
        "Where the argument is a number. \n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc != 2) {
        help(argv[0], "Should be 1 argument.\n\n");
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

    if (value < 0) {
        throw std::string("Number must be positive!");
    }

    return value;
}

std::string Application::operator()(int argc, const char** argv) {
    int num;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        num = parseInt(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    Pseudographics graph(num);
    stream << graph.get_graph();
    message_ = stream.str();
    return message_;
}
