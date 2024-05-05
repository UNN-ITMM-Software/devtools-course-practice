// Copyright 2024 Shmelev Ivan

#include <iostream>

#include "include/tower_of_hanoi_app.h"

int main(int argc, char* argv[]) {
    TowerOfHanoiApplication application;
    std::cout << application.TowerOfHanoiCount(argc, argv) << std::endl;
    return 0;
}
