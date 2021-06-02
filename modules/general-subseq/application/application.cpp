// Copyright 2021 Kirillov Konstantin

#include <iostream>
#include <string>

#include "include/GeneralSubseqApp.h"

int main(int argc, const char** argv) {
    GeneralSubseqApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
