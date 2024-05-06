// Copyright 2024 Kistrimova Ekaterina

#include "include/tbitfield_app.h"
#include <cstring>
#include <sstream>

TBitFieldApp::TBitFieldApp(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
}

void TBitFieldApp::ProcessArguments() {
    for (const auto& arg : args) {
        if (arg[0] == '-') {
            int bit = std::stoi(arg.substr(1));
            bitField.ClrBit(bit);
        } else {  // Иначе установите этот бит
            int bit = std::stoi(arg);
            bitField.SetBit(bit);
        }
    }
}

void TBitFieldApp::PerformBitFieldOperations() {
    bitField = ~bitField;
    TBitField otherBitField = bitField.CreateBitField(10);
    bitField = bitField & otherBitField;
}

std::string TBitFieldApp::Run() {
    ProcessArguments();
    PerformBitFieldOperations();

    std::stringstream ss;
    ss << bitField;
    return ss.str();
}
