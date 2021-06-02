// Copyright 2021 Alibekov Murad

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "include/dijkstras_algorithm_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
