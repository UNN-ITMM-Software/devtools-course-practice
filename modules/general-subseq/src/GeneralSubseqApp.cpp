// Copyright 2021 Kirillov Konstantin

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include "include/GeneralSubseqApp.h"
#include "include/GeneralSubseq.h"

GeneralSubseqApp::GeneralSubseqApp() : message_("") {}

void GeneralSubseqApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a check of the longest general subsequential search," \
        "among a randomly given sequence.\n\n" \
        "Please provide arguments in the following format:\n$"
        + appname + "count . \n\n"
        + "The argument is the length of the generated sequence\n\n" \

        "Where argument is number. \n" \
        "Example: " + appname + " 1.\n\n";
}

bool GeneralSubseqApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 11) {
        help(argv[0], "Should be 11 arguments.\n\n");
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

    return value;
}

std::string GeneralSubseqApp::operator()(int argc, const char** argv) {
    std::vector<int> firstSeq(5);
    std::vector<int> secondSeq(5);
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        firstSeq[0] = parseInt(argv[1]);
        firstSeq[1] = parseInt(argv[2]);
        firstSeq[2] = parseInt(argv[3]);
        firstSeq[3] = parseInt(argv[4]);
        firstSeq[4] = parseInt(argv[5]);
        secondSeq[0] = parseInt(argv[6]);
        secondSeq[1] = parseInt(argv[7]);
        secondSeq[2] = parseInt(argv[8]);
        secondSeq[3] = parseInt(argv[9]);
        secondSeq[4] = parseInt(argv[10]);
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;

    GeneralSubseq m_seq(firstSeq, secondSeq);
    std::vector<int> ans;
    ans = m_seq.getLargSubseq();
    stream.str("");
    int size = ans.size();
    for (int i=0; i < size; i++) stream << ans[i] << " ";
    message_ = stream.str();
    return message_;
}
