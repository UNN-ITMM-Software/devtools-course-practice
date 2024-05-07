// Copyright 2024 Kiselev Igor

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "../include/game_of_life_app.h"

int main(int argc, const char** argv) {
    ConwaysGameOfLifeApplication app = ConwaysGameOfLifeApplication(argc, argv);
    std::string res = app.doWork();
    std::cout << res;
    return 0;
}
