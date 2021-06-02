// Copyright 2021 Tsvetkov Maxim

#include <iostream>
#include <string>

#include "include/string_calculator_app.h"

int main(int argc, const char** argv) {
    StringCalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
