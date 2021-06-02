// Copyright 2021 Lukyanchenko Ivan

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <sstream>
#include <utility>
#include "include/largest_subseq_app.h"
#include "include/largest_subseq.h"

Lar_SubseqApp::Lar_SubseqApp() : message_("") {}

void Lar_SubseqApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a check of the longest subsequence search," \
        "among a randomly given sequence.\n\n" \
        "Please provide arguments in the following format:\n$"
        + appname + "count . \n\n"
        + "The argument is the length of the generated sequence\n\n" \

        "Where argument is number. \n" \
        "Example: " + appname + " 1.\n\n";
}

bool Lar_SubseqApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc != 2) {
        help(argv[0], "Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    double value = strtol(arg, &end, 0);

    if (value <= 0) {
        throw std::string("Count must be positive!");
    }

    return value;
}
std::vector<int> get_rand_vec(int size) {
    std::mt19937 gen;
    gen.seed(static_cast<int>(time(0)));
    std::vector<int> res(size);
    for (int i = 0; i < size; i++) {
        res[i] = gen() % 100000;
    }
    return res;
}
std::string Lar_SubseqApp::operator()(int argc, const char** argv) {
    int count;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
       count = parseInt(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;
    std::vector<int> first;
    first = get_rand_vec(count);
    Sequential a(first);
    std::vector<int> res = a.getLargSubseq(first);
    stream.str("");
    if ( (res[0] == res[1]) && (count != 1) ) {
        stream << "Correctly";
    } else { stream << "Uncorrectly"; }
    message_ = stream.str();
    return message_;
}
