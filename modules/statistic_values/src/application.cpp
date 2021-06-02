// Copyright 2021 Volkova Anastasia

#include "include/application.h"

#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>

#include "include/statistic_values.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a statistic values calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <n> <x> <p> <k>" +
          "<operation>\n\n" +

          "Where the first integer type (size)," +
          "then arrays of double numbers," +
          "then integer type (power)," +
          "and <operation> is one of" +
          "'meanValue', 'variance', 'start', 'centr'.\n";
}

bool isInt(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int parseInt(const char* arg) {
    if (!isInt(arg)) {
        throw std::runtime_error("Wrong number format!");
    }
    return std::stoi(arg);
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    int value = parseInt(argv[1]);
    int count = value * 2 + 3;
    if (argc == count || argc == (count + 1)) {
        return true;
    }
    help(argv[0], "ERROR: wrong number of arguments.\n\n");
    return false;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::runtime_error("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "meanValue") == 0) {
        op = 'm';
    } else if (strcmp(arg, "variance") == 0) {
        op = 'v';
    } else if (strcmp(arg, "start") == 0) {
        op = 's';
    } else if (strcmp(arg, "centr") == 0) {
        op = 'c';
    } else {
        throw std::runtime_error("Wrong operation format!");
    }
    return op;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    args.p.clear();
    args.x.clear();
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.n = parseInt(argv[1]);
        args.x.reserve(args.n);
        args.p.reserve(args.n);
        if (argc == (args.n * 2 + 4)) {
            for (int i = 0; i < args.n; ++i) {
                args.x.emplace_back(parseDouble(argv[i + 2]));
            }
            for (int i = 0; i < args.n; ++i) {
                args.p.emplace_back(parseDouble(argv[args.n + i + 2]));
            }
            args.k = parseInt(argv[args.n * 2 + 2]);
            args.operation = parseOperation(argv[args.n * 2 + 3]);
        } else {
            for (int i = 0; i < args.n; ++i) {
                args.x.emplace_back(parseDouble(argv[i + 2]));
            }
            for (int i = 0; i < args.n; ++i) {
                args.p.emplace_back(parseDouble(argv[args.n + i + 2]));
            }
            args.operation = parseOperation(argv[args.n * 2 + 2]);
        }
    }
    catch(std::exception& str) {
        return str.what();
    }

    vector<double> x = args.x;
    vector<double> p = args.p;
    int n = args.n;

    std::ostringstream stream;
    switch (args.operation) {
    case 'm':
        stream << "Mat. expectation = " << statValues::meanValue(x, p, n);
        break;
    case 'v':
        stream << "Dispersion = " << statValues::variance(x, p, n);
        break;
    case 's':
        stream << "Starting moment = " << statValues::start(x, p, n, args.k);
        break;
    case 'c':
        stream << "Central moment = " << statValues::centr(x, p, n, args.k);
        break;
    }
    message_ = stream.str();

    return message_;
}
