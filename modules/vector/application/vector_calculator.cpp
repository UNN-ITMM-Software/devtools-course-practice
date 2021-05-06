// Copyright 2021 Shagov Maksim

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/vector_calculator.h"

int main(int argc, const char** argv) {
    VectorCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
