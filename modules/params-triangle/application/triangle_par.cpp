// Copyright 2021 Molotkova Svetlana

#include <iostream>
#include <string>

#include "include/triangle_app.h"

int main(int argc, const char** argv) {
    TriangleApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
