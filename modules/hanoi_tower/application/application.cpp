// Copyright 2021 Bezrodnov Dmitry

#include <stdio.h>
#include <string>

#include "include/hanoi_application.h"

int main(int argc, const char** argv) {
    HanoiApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
