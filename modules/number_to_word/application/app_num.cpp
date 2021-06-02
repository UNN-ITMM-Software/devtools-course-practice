// Copyright 2021 Romanuyk Sergey

#include <iostream>
#include <string>

#include "include/Application_num_to_word.h"

int main(int argc, const char** argv) {
    NumToWord app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
