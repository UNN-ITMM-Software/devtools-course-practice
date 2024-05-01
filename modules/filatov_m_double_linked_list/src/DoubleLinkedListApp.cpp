// Copyright 2024 Ivanchenko Aleksei

#include "include/DoubleLinkedListApp.h"
#include "stdio.h"

std::string DoubleLinkedListApp::runApp(int argc, const char** argv) {
    if(argc > 1) {
        auto args = parse(argc, argv);
        if(args.size() == 1 && args[0] == "--help") {
            return "help! i need somebodey help! not just anybody help!";
        } else {
            return UNRECOGNIZED_OPTIONS_ERROR;
        }
    }
    std::string res;
    
    return "sh-boom!";
} 

std::vector<std::string> DoubleLinkedListApp::parse(int argc, const char** argv) {
    std::vector<std::string> input;
    for(int i = 1; i < argc; i++) {
        const char* ptr = argv[i];
        std::string str(ptr);
        input.push_back(str);
    }
    return input;
}
std::vector<std::string> DoubleLinkedListApp::parseString(const std::string& s) {
    std::vector<std::string> input;
    std::string delimiter = " ";
    int begin = 0;
    int end;
    while(end = s.find(delimiter)) {
        input.add(s.substr(begin, end));
        begin = end + 1;
    }
    return input;
}