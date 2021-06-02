// Copyright 2021 Lebedev Andrew

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/triangle_application.h"

int main(int argc, const char** argv) {
    TriangleApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
