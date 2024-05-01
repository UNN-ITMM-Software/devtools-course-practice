// Copyright 2024 Vinokurov Ivan

#include <iostream>
#include <string>

#include "include/objvolumes_app.h"

int main(int argc, const char** argv) {
    ObjVolumeApp app;
    std::cout << app(argc, argv);
    return 0;
}
