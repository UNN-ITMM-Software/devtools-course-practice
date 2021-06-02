// Copyright 2021 Prokofeva Elizaveta

#include "include/stack_app.h"

#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

#include "include/stack.h"

StackApp::StackApp() : message_("") {}

void StackApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a stack application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname  + "<operation>\n\n" +

        "Where <operation> is one of\n" +
        "peek\n" +
        "pop\n" +
        "push <element>, where are element is double\n"
        "isEmpty";
}

bool StackApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string StackApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    std::ostringstream stream;
    try {
        int arg = 1;
        while (arg < argc) {
            std::string op = argv[arg];
            if (op == "peek") {
                stack.peek();
                stream << std::to_string(stack.peek()) << "\n";
            } else if (op == "pop") {
                stack.pop();
            } else if (op == "push") {
                arg++;
                double el = parseDouble(argv[arg]);
                stack.push(el);
            } else if (op == "isEmpty") {
                bool flag = stack.isEmpty();
                stream << flag << "\n";
            } else {
                throw std::string("Wrong operation format!");
            }
            arg++;
        }
    } catch (std::string& str) {
        return str;
    }
    message_ = stream.str();

    return message_;
}
