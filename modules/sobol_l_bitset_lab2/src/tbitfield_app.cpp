// Copyright 2024 Kistrimova Ekaterina

#include "include/tbitfield_app.h"

std::vector<std::string> TBitFieldApp::runApp(int argc,
 const char** argv) {
    std::vector<std::string> output;
    auto args = parse(argc, argv);
    for (size_t i = 0; i < args.size(); i++) {
        auto arg = args[i];
        if (arg == "--help") {
            help(output);
        } else if (arg == "--setbit") {
            if (i + 1 < args.size()) {
                setbit(output, std::stoi(args[i + 1]));
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--setbit option must have one argument");
                output.push_back("Run --help for all supported options");
            }
        } else if (arg == "--clearbit") {
            if (i + 1 < args.size()) {
                clearbit(output, std::stoi(args[i + 1]));
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--clearbit option must have one argument");
                output.push_back("Run --help for all supported options");
            }
        } else if (arg == "--getbit") {
            if (i + 1 < args.size()) {
                getbit(output, std::stoi(args[i + 1]));
                i++;
            } else {
                output.push_back("Error:");
                output.push_back("--getbit option must have one argument");
                output.push_back("Run --help for all supported options");
            }
        } else if (arg == "--print") {
            print(output);
        } else {
            output.push_back("Error:");
            output.push_back("unrecognized command-line option.");
            output.push_back("Run --help for all supported options");
            break;
                    }
    }
    return output;
}

std::vector<std::string> TBitFieldApp::parse(int argc,
 const char** argv) {
    std::vector<std::string> input;
    for (int i = 1; i < argc; i++) {
        const char* ptr = argv[i];
        std::string str(ptr);
        input.push_back(str);
    }
    return input;
}

void TBitFieldApp::help(std::vector<std::string>& output) {
    output.push_back("Usage: ./target [options]");
    output.push_back("Optinos:");
    output.push_back("    --help");
    output.push_back("    --setbit");
    output.push_back("    --clearbit");
    output.push_back("    --getbit");
    output.push_back("    --print");
    output.push_back("Notion: you can use the same option several times");
}

void TBitFieldApp::print(std::vector<std::string>& output) {
    for (size_t i = 0; i < myBitField.GetLength(); i++) {
        output.push_back(myBitField.getbit(i));
    }
}

void TBitFieldApp::setbit(std::vector<std::string>& output, int index) {
    myBitField.SetBit(index);
}

void TBitFieldApp::clearbit(std::vector<std::string>& output, int index) {
    myBitField.ClrBit(index);
}

void TBitFieldApp::getbit(std::vector<std::string>& output, int index) {
    output.push_back(std::to_string(myBitField.GetBit(index)));
}
