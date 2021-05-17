// Copyright 2021 Kolesnikov Gleb

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/prime_numbers_application.h"

int main(int argc, const char** argv) {
    PrimeNumbersApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
