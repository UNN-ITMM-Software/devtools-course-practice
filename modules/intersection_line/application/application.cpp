// Copyright 2021 LoganovAndrei

#include <iostream>
#include <string>

#include "include/intersect_app.h"

int main(int argc, const char** argv) {
    LineApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
