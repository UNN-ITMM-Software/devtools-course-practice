// Copyright 2024 Platonova Maria

#include "include/bisymmetricApp.h"

std::vector<std::string> BisymmetricApp::runApp(int argc,
 const char** argv) {
    std::vector<std::string> output;
    auto args = parse(argc, argv);
    int argsSize = args.size();
    for (size_t i = 0; i < argsSize; i++) {
        auto arg = args[i];
        if (arg == "--help") {
            help(output);
        } else if (arg == "--convert_size") {
            convertSize(output, std::stoi(args[i+1]));
            i++;
        } else if (arg == "--print") {
            print(output);
        } else if (arg == "--is_inside") {
            if (i + 3 > argsSize) {
                output.push_back("Error: insufficient arguments");
            } else {
                isInside(output, std::stoi(args[i+1]), std::stoi(args[i+2]), std::stoi(args[i+3]));
                i+=3;
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

std::vector<std::string> BisymmetricApp::parse(int argc,
 const char** argv) {
    std::vector<std::string> input;
    for (int i = 1; i < argc; i++) {
        const char* ptr = argv[i];
        std::string str(ptr);
        input.push_back(str);
    }
    return input;
}

void BisymmetricApp::help(std::vector<std::string>& output) {
    output.push_back("Usage: ./target [options]");
    output.push_back("Optinos:");
    output.push_back("    --print");
    output.push_back("    --initialize");
    output.push_back("    --convert_size");
    output.push_back("    --is_inside");
    output.push_back("    --help");
    output.push_back("Notion: you can use the same option several times");
}

void BisymmetricApp::print(std::vector<std::string>& output) {
    output.push_back("1,2,3\n4,5,6\n7,8,9");
}

void BisymmetricApp::isInside(std::vector<std::string>& output,
                              int elem1, int elem2, int elem3) {
    bool res = matrix.isInside(elem1, elem2, elem3);
    output.push_back((res ? "true" : "false"));
}

void BisymmetricApp::convertSize(std::vector<std::string>& output, int elem1) {
    int res = matrix.convertSize(elem1);
    output.push_back(std::to_string(res));
}

void BisymmetricApp::initialize(std::vector<std::string>&output) {
    matrix = BisymmetricMatrix<int>({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    output.push_back("initialized");
}
