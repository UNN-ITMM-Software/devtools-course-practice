// Copyright 2021 Solovev Aleksandr

#include <iostream>
#include <string>

#include "include/BullsAndCowsApp.h"

int main(int argc, const char* argv[]) {
    BullsAndCowsApp app;
    int retcode = 0;
    std::cout << app(argc, argv, &retcode);
    return retcode;
}
