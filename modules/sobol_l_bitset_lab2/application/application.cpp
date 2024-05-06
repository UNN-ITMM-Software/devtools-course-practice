// Copyright 2024 Kistrimova Ekaterina

#include <iostream>

#include "include/tbitfield_app.h"

// int main(int argc, char** argv) {
//     TBitFieldApp app(argc, argv);
//     std::string result = app.Run();
//     std::cout << result << std::endl;
//     return 0;
// }

int main(int argc, const char** argv) {
    TBitFieldApp app;
    auto output = app.runApp(argc, argv);
    for (auto str : output) {
        std::cout << str << std::endl;
    }
    return 0;
}
