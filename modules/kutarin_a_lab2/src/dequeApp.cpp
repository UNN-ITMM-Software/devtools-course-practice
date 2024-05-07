// Copyright 2024 Ivanchenko Aleksei

#include "include/dequeApp.h"

std::vector<std::string> DequeApp::runApp(int argc,
 const char** argv) {
    std::vector<std::string> output;
    auto args = parse(argc, argv);
    for (size_t i = 0; i < args.size(); i++) {
        auto arg = args[i];
        if (arg == "--help") {
            help(output);
        } else if (arg == "--initialize") {
            set_up_default();
        } else if (arg == "--reverse") {
            reverse(output);
        } else if (arg == "--print") {
            print(output);
        } else if (arg == "--pop_back") {
            pop_back(output);
        } else if (arg == "--pop_front") {
            pop_front(output);
        } else if (arg == "--push_back") {
            if (i + 1 < args.size()) {
                push_back(output, args[i + 1]);
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--push_back option must have one argument.");
                output.push_back("Run --help for all supported options");
            }
        } else if (arg == "--push_front") {
            if (i + 1 < args.size()) {
                push_front(output, args[i + 1]);
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--push_front option must have one argument.");
                output.push_back("Run --help for all supported options");
           }
        } else {
            output.push_back("Error:");
            output.push_back("unrecognized command-line option.");
            output.push_back("Run --help for all supported options");
            break;
                    }
    }
    return output;
}

std::vector<std::string> DequeApp::parse(int argc,
 const char** argv) {
    std::vector<std::string> input;
    for (int i = 1; i < argc; i++) {
        const char* ptr = argv[i];
        std::string str(ptr);
        input.push_back(str);
    }
    return input;
}

void DequeApp::help(std::vector<std::string>& output) {
    output.push_back("Usage: ./target [options]");
    output.push_back("Optinos:");
    output.push_back("    --print");
    output.push_back("    --reverse");
    output.push_back("    --pop_back");
    output.push_back("    --pop_front");
    output.push_back("    --push_back");
    output.push_back("    --push_front");
    output.push_back("    --help");
    output.push_back("Notion: you can use the same option several times");
}
void DequeApp::reverse(std::vector<std::string>& output) {
    deque.reverse();
    output.push_back("deque was reversed");
}
void DequeApp::print(std::vector<std::string>& output) {
    for (size_t i = 0; i < deque.size(); i++) {
        output.push_back(deque[i]);
    }
}
void DequeApp::push_back(std::vector<std::string>& output,
 std::string elem) {
    deque.push_back(elem);
}
void DequeApp::push_front(std::vector<std::string>& output,
 std::string elem) {
    deque.push_front(elem);
}
void DequeApp::pop_back(std::vector<std::string>& output) {
    if (deque.empty()) {
        output.push_back("Deque is empty, can't pop_back.");
    } else {
        deque.pop_back();
    }
}
void DequeApp::pop_front(std::vector<std::string>& output) {
    if (deque.empty()) {
        output.push_back("Deque is empty, can't pop_front.");
    } else {
        deque.pop_back();
    }
}

void DequeApp::set_up_default() {
    deque.push_back("never");
    deque.push_back("gonna");
    deque.push_back("give");
    deque.push_back("you");
    deque.push_back("up");
}
