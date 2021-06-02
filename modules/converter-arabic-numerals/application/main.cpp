// Copyright 2021 Makarychev Sergey

#include <iostream>
#include <string>

#include "include/romanumber_application.h"

int main(int argc, const char** argv) {
    RomaNumberApplication app;
    const std::string out = app(argc, argv);
    printf("%s\n", out.c_str());
    return 0;
}
