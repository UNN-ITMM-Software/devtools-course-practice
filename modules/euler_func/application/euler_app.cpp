// Copyright 2021 Kudriavtsev Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/euler_application.h"

int main(int argc, const char** argv) {
    EulerApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
