// Copyright 2021 Alibekov Murad

#include "include/dijkstras_algorithm.h"
#include "include/dijkstras_algorithm_app.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <limits>
#include <sstream>
#include <string>
#include <vector>

Application::Application() : message_("") {}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!\n");
    }

    return value;
}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a graph's shortest paths finder application.\n\n" \
          "Please provide arguments in the following format:\n\n" \
          "  $ " + appname + " <N> <source vertex> ... (N * N numbers)\n\n " \
          "Where all arguments are double-precision numbers or word 'inf'.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        try {
            int N = parseInt(argv[1]);
            if (argc != N * N + 3) {
                help(argv[0], "ERROR: Should be N * N + 3 arguments.\n");
                return false;
            }
        }
        catch(std::string& str) {
            help(argv[0], "ERROR: Wrong number format!\n");
            return false;
        }
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!\n");
    }

    return value;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    double inf = std::numeric_limits<double>::infinity();
    try {
        args.N = parseInt(argv[1]);
        args.source_vertex = parseInt(argv[2]);
        if (args.source_vertex > args.N) {
            throw std::string("ERROR: Index out of range!\n");
        }
        for (int i = 3; i < args.N * args.N + 3; i++) {
            if (strcmp(argv[i], "inf") == 0)
                args.graph.push_back(inf);
            else
                args.graph.push_back(parseDouble(argv[i]));
        }
    }
    catch(std::string& str) {
        return str;
    }

    std::vector<double> result = GraphAlgorithms::dijkstras_algorithm
        (args.graph, args.N, args.source_vertex);

    std::ostringstream stream;
    stream << "Result: [";
    for (auto res : result) {
        stream << res << " ";
    }
    stream << "]\n";

    message_ = stream.str();

    return message_;
}
