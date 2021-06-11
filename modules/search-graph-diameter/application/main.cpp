// Copyright 2021 Panova Olga

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "include/graph_diam_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
