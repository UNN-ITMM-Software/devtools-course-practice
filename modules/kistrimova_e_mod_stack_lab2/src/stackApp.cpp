// Copyright 2024 Bakhtiarov Alexander

#include <cstring>
#include <exception>
#include <sstream>

#include "include/stackApp.h"

bool StackApp::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    } else if (argc == 2 &&
        std::strcmp(argv[1], "pop") != 0
        && std::strcmp(argv[1], "show_top") != 0
        && std::strcmp(argv[1], "isFull") != 0
        && std::strcmp(argv[1], "isEmpty") != 0
        && std::strcmp(argv[1], "current_size") != 0
        && std::strcmp(argv[1], "clear") != 0) {
        help(argv[0], "Incorrect second argument");
        return false;
        }
    return true;
}

void StackApp::help(const char* appname,
const char* message) {
    std::ostringstream stream;
    std::string str = message ? "Error: " + std::string(message) + "\n" : "";
    stream << str;
    stream << "This application works with stack.\n";
    stream << "Arguments must come in the following format:\n";
    stream << " <operation> - The action you need: push, pop, ";
    stream << "show_top, isFull, isEmpty, clear, current_size, oversize \n";
    stream << " <input_string> - element to be pushed.\n";

    message_ = stream.str();
}

std::string StackApp::operator()(int argc, char* argv[]) {
    if (validate(argc, argv)) {
        std::ostringstream stream;
            std::string operation = std::string(argv[1]);
            if (operation == "isFull") {
                    bool temp = Mystack.isFull();
                    stream << "isFull: " << temp << "\n";
            } else if (operation == "isEmpty") {
                bool temp = Mystack.isEmpty();
                stream << "isEmpty: " << temp << "\n";
