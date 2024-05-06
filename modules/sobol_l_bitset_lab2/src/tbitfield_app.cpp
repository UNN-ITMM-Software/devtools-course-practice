// Copyright 2024 Kistrimova Ekaterina

#include "include/tbitfield_app.h"
// #include <cstring>
// #include <sstream>

// TBitFieldApp::TBitFieldApp(int argc, char** argv) {
// //     for (int i = 1; i < argc; ++i) {
// //         args.push_back(argv[i]);
// //     }
// }

// void TBitFieldApp::ProcessArguments() {
//     // for (const auto& arg : args) {
//     //     if (arg[0] == '-') {
//     //         int bit = std::stoi(arg.substr(1));
//     //         bitField.ClrBit(bit);
//     //     } else {  // Иначе установите этот бит
//     //         int bit = std::stoi(arg);
//     //         bitField.SetBit(bit);
//     //     }
//     // }
// }

// void TBitFieldApp::PerformBitFieldOperations() {
//     // bitField = ~bitField;
//     // TBitField otherBitField = bitField.CreateBitField(10);
//     // bitField = bitField & otherBitField;
// }

// std::string TBitFieldApp::Run() {
//     // ProcessArguments();
//     // PerformBitFieldOperations();

//     // std::stringstream ss;
//     // ss << bitField;
//     // return ss.str();
//     return "";
// }

std::vector<std::string> TBitFieldApp::runApp(int argc,
 const char** argv) {
    std::vector<std::string> output;
    auto args = parse(argc, argv);
    for (size_t i = 0; i < args.size(); i++) {
        auto arg = args[i];
        if (arg == "--help") {
            help(output);
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
    output.push_back("Notion: you can use the same option several times");
}


