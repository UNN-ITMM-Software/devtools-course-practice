// Copyright 2021 Anastasia Kurnikova

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/avl_application.h"

int main(int argc, const char** argv) {
    CAvlApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
