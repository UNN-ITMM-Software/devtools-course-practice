// Copyright 2021 Vodeneev Mikhail

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/modify_stack_app.h"

int main(int argc, const char** argv) {
    StackApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
