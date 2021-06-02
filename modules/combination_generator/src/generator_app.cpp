// Copyright 2021 Makarov Alexandr

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/generator.h"
#include "include/generator_app.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) + "This is a combination with repeats from " \
        "N to M generator application.\n\nPlease provide arguments in the " \
        "following format:\n\n  $ " + appname + " <N> + <M> \n\nWhere all " \
        "arguments are integer numbers\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
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

void printSet(std::ostringstream* stream, int* a, int n) {
    static int num = 1;
    *stream << num++ << ": ";
    for (int i = 0; i < n; i++)
    *stream << a[i] << " ";
    *stream << "\n";
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.n = parseInt(argv[1]);
        args.m = parseInt(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;
    int n = args.n;
    int m = args.m;

    stream << "N = " << n << "\n";
    stream << "M = " << m << "\n";
    int *a = new int[m];
    for (int i = 0; i < m; i++)
        a[i] = 1;
    printSet(&stream, a, m);
    generator g;
    while (g.NextSet(a, n, m))
            printSet(&stream, a, m);
    delete[] a;

    message_ = stream.str();

    return message_;
}
