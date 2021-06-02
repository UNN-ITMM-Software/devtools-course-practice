// Copyright 2021 Mishin Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/ceasar_application.h"

int main(int argc, const char** argv) {
    CeasarApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
