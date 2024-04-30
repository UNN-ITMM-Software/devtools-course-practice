// Copyright 2024 Vanushkin Dmitry

#include <cstdio>
#include <string>

#include "../include/long_number_calculator.h"

int main(int argc, const char** argv) {
    LongNumberCalculator app;
    auto output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
