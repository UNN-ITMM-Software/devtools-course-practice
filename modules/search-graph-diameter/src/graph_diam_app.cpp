// Copyright 2021 Panova Olga

#include "include/search_graph_diam.h"
#include "include/graph_diam_app.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is application for graph diameter searching.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <n> <l> ... (n * n numbers)\n\n " +

        "Where all arguments are double-precision numbers or list.\n";
}

int parseInt(const char* arg) {
    char* end;
    int val = strtol(arg, &end, 5);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!\n");
    }

    return val;
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        int n = parseInt(argv[1]);
        help(argv[0], "ERROR: Should be n * n + 2 arguments.\n\n");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;

    std::ostringstream stream;
    stream << "Result: [";
    for (auto res : result) {
        stream << res << " ";
    }
    stream << "]\n";
    message_ = stream.str();
    return message_;
    }