// Copyright 2021 Yurin Stanislav

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    WaveLib::Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
