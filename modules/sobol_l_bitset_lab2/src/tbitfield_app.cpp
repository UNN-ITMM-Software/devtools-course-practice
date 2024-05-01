// Copyright 2024 Kistrimova Ekaterina

#include "tbitfield_app.h"
#include <cstring>
#include <sstream>

TBitFieldApp::TBitFieldApp(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
}

void TBitFieldApp::ProcessArguments() {
    // Здесь вы можете обработать аргументы командной строки
    // Например, вы можете преобразовать их в целые числа и использовать для установки битов в битовом поле
    for (const auto& arg : args) {
        int bit = std::stoi(arg);
        bitField.SetBit(bit);
    }
}

void TBitFieldApp::PerformBitFieldOperations() {
    // Здесь вы можете выполнить любые операции с битовым полем, которые вам нужны
    // Например, вы можете инвертировать битовое поле или выполнить операцию "И" с другим битовым полем
    bitField = ~bitField;
}

std::string TBitFieldApp::Run() {
    ProcessArguments();
    PerformBitFieldOperations();

    std::stringstream ss;
    ss << bitField;
    return ss.str();
}
