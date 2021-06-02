// Copyright 2021 Bulychev Vladislav

#include <iostream>
#include <string>

#include "include/tree_app.h"

int main(int argc, const char* argv[]) {
    TreeApp app;
    const std::string out = app(argc, argv);
    printf("%s\n", out.c_str());
    return 0;
}
