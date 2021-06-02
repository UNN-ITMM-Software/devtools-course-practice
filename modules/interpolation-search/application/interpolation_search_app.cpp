// Copyright 2021 Pestreev Daniil

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/searchApplication.h"

int main(int argc, const char** argv) {
    searchApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
