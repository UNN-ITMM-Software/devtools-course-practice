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
    // Преобразование аргументов командной строки в целые числа и использование их для установки битов в битовом поле
    for (const auto& arg : args) {
        if (arg[0] == '-') {  // Если аргумент начинается с '-', очистите этот бит
            int bit = std::stoi(arg.substr(1));
            bitField.ClrBit(bit);
        } else {  // Иначе установите этот бит
            int bit = std::stoi(arg);
            bitField.SetBit(bit);
        }
    }
}

void TBitFieldApp::PerformBitFieldOperations() {
    // Инвертирование битового поля
    bitField = ~bitField;
    // Дополнительная операция: выполнение операции "И" с другим битовым полем
    TBitField otherBitField = CreateBitField(10);
    bitField = bitField & otherBitField;
}

std::string TBitFieldApp::Run() {
    ProcessArguments();
    PerformBitFieldOperations();

    std::stringstream ss;
    ss << bitField;
    return ss.str();
}
