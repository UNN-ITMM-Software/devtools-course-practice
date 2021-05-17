// Copyright 2021 Chernyh Daria

#include <string>

#include "include/Application_vigener.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
