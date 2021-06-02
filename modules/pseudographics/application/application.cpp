// Copyright 2021 Chistov Vladimir

#include <iostream>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
