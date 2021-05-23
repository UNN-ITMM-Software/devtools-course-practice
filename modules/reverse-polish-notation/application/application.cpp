// Copyright 2021 Aleksandrychev Andrey

#include <iostream>
#include <string>

#include "include/rpn_app.h"

int main(int argc, const char** argv) {
    RPN_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
