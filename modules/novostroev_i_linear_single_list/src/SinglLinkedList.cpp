// Copyright 2024 Kutarin Alexandr
#include "include/SingleLinkedList.h"

std::vector<std::string> SingleLinkedList::runApp(int argc,
 const char** argv) {
    std::vector<std::string> output;
    auto args = parse(argc, argv);
    for (size_t i = 0; i < args.size(); i++) {
        if (args[i] == "--help") {
            help(output);
        } else if (args[i] == "--print") {
            print(output);
        } else if (args[i] == "--push_back") {
            if (i + 1 < args.size()) {
                push_back(output, args[i + 1]);
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--push_back option must have one argument.");
                output.push_back("Run --help for all supported options");
            }
        } else if (args[i] == "--push_front") {
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

std::vector<std::string> SingleLinkedList::parse(int argc,
 const char** argv) {
    std::vector<std::string> input;
    for (int i = 1; i < argc; i++) {
        const char* ptr = argv[i];
        std::string str(ptr);
        input.push_back(str);
    }
    return input;
}

void SingleLinkedList::help(std::vector<std::string>& output) {
    output.push_back("Usage: ./target [options]");
    output.push_back("Optinos:");
    output.push_back("    --print");
    output.push_back("    --push_back");
    output.push_back("    --push_front");
    output.push_back("    --help");
    output.push_back("Notion: you can use the same option several times");
}

void SingleLinkedList::print(std::vector<std::string>& output) {
    for (size_t i = 0; i < list.size(); i++) {
        output.push_back(list[i]->get_data());
    }
}

void SingleLinkedList::push_back(std::vector<std::string>& output,
 std::string elem) {
    list.push_back(elem);
}

void SingleLinkedList::push_front(std::vector<std::string>& output,
 std::string elem) {
    list.push_front(elem);
}
