// Copyright 2024 Kulikov Artem
#include <stdio.h>

#include <string>

#include "include/lis_app.h"

int main(int argc, const char** argv) {
    LISApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
