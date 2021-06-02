// Copyright 2021 Gurylev Nikita

#include <cstdlib>
#include <string>
#include <cstring>

#include "include/Pqueue.h"
#include "include/Pqueue-application.h"

void PriorityApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a priority queue application.\n\n" \
        "Please provide arguments in the following format:\n\n" \
        " $ " + appname + " <actions> " \
        "Where <actions> are operations (push/pop):\n" \
        "push <priority> <value> - insert in queue\n" \
        "pop - extract from queue\n";
}

std::string PriorityApp::operator()(int argc, const char** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        Help(*argv);
        return message_;
    }
    for (int i = 1; i < argc; ) {
        int offset = ParseOperation(argv + i);
        if (offset == 0) {
            message_ = "Wrong arguments!";
            break;
        }
        i += offset;
    }
    return message_;
}

bool PriorityApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    return true;
}

int PriorityApp::ParseOperation(const char** argv) {
    if (std::strcmp(*argv, "push") == 0) {
        int p = std::stoi(*(argv + 1));
        int v = std::stoi(*(argv + 2));
        PriorityQueueElem a(p, v);
        q.Push(a);
        return 3;
    }
    if (std::strcmp(*argv, "pop") == 0) {
        q.Pop();
        return 1;
    }
    return 0;
}
