// Copyright 2021 Skripal Andrey

#include <iostream>
#include <string>

#include "include/liap_app.h"

int main(int argc, const char** argv) {
    PointApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
