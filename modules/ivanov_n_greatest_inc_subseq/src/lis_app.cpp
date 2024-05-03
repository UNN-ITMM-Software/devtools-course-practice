// Copyright 2024 Kulikov Artem
#include "include/lis_app.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <string>

#include "include/subseq.h"

LISApp::LISApp() : message_("") {}

void LISApp::help(const char* appname, const char* message) {
    std::ostringstream stream;
    stream << message << "This is LISApp application.\n\n"
                   << "Please provide arguments in the following format:\n\n"
                   << "  " << appname << " <int_1> <int_2> ...\n";
    message_ = stream.str();
}

bool LISApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

std::string LISApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    int i = 1;
    try {
        for (; i < argc; ++i) {
            args.seq.push_back(std::stoi(argv[i]));
        }
    } catch (std::invalid_argument const& ex) {
        return "std::invalid_argument on " + std::string(argv[i]);
    } catch (std::out_of_range const& ex) {
        return "std::out_of_range on " + std::string(argv[i]);
    }

    std::ostringstream stream;

    LIS libOng(args.seq);

    std::vector<int> vec = libOng.run();

    stream << "LIS = ";
    for (auto i : vec) {
        stream << i << " ";
    }

    message_ = stream.str();

    return message_;
}
