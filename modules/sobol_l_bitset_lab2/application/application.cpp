// Copyright 2024 Kistrimova Ekaterina

#include <iostream>

#include "include/tbitfield_app.h"

int main(int argc, char** argv) {
    TBitFieldApp app(argc, argv);
    std::string result = app.Run();
    std::cout << result << std::endl;
    return 0;
}
