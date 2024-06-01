// Copyright 2024 safronov Mikhail

#include <iostream>
#include <string>

#include "include/kruskalapp.h"

int main(int argc, char* argv[])
{
    KruskalApp app;
    std::cout << app.Parse(argc, argv) << std::endl;
    return 0;
}
