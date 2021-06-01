// Copyright 2021 Novozhilova Ekaterina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/matrix_operations_app.h"

int main(int argc, const char** argv) {
    MyApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
