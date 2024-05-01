// Copyright 2024 Sobol Lyubov

#include <cstring>
#include <exception>
#include <sstream>

#include "include/stack_app.h"
bool StackApp::validate(int argc, char* argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
        help(argv[0]);
        return false;
    }
    int count = 0;
    while (count < argc)
    if (
        std::strcmp(argv[1] + count, "pop") != 0
        && std::strcmp(argv[1] + count, "show_top") != 0
        && std::strcmp(argv[1] + count, "isFull") != 0
        && std::strcmp(argv[1] + count, "isEmpty") != 0
        && std::strcmp(argv[1] + count, "current_size") != 0
        && std::strcmp(argv[1] + count, "clear") != 0
        && std::strcmp(argv[1] + count, "push") != 0) {
        help(argv[0], "Incorrect second argument");
        return false;
    } else if (std::strcmp(argv[1] + count, "push") == 0 && count + 1 < argc) {
        count += 2;
    } else {
        count++;
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
        int count = 0;
        std::ostringstream stream;
        while (count < argc) {
            std::string operation = std::string(argv[1] + count);
            if (operation == "pop") {
                    Mystack.pop();
                    stream << "Pop completed\n";
                    count +1;
            } else if (operation == "show_top") {
                    T temp = Mystack.show_top();
                    stream << "Top: " << temp << "\n";
                    count + 1;
            } else if (operation == "isFull") {
                    bool temp = Mystack.isFull();
                    stream << "isFull: " << temp << "\n";
                    count + 1;
            } else if (operation == "isEmpty") {
                bool temp = Mystack.isEmpty();
                stream << "isEmpty: " << temp << "\n";
                count + 1;
            } else if (operation == "current_size") {
                    bool temp = Mystack.current_size();
                    stream << "current_size: " << temp << "\n";
                    count + 1;
            } else if (operation == "clear") {
                    Mystack.clear();
                    stream << "clear completed \n";
                    count + 1;
            } else if (operation == "push") {
                int input_string = std::stoi(argv[2] + count);
                Mystack.push(input_string);
                stream << "push completed \n";
                count + 2;
            }
        }
        message_ = stream.str();
    }
    return message_;
}

