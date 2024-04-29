// Copyright 2024 Vinichuk Timofey

#include <stdio.h>
#include <iostream>

#include "../include/base64_converter_app.h"


int main(int argc, char* argv[]) {
    auto output = Base64ConverterApplication()(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
