// Copyright 2021 Nikolaev Denis

#include <iostream>
#include <string>

#include "include/permutation_app.h"

int main(int argc, const char** argv) {
    Permutation_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
