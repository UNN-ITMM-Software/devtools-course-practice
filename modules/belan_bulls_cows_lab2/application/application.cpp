// Copyright 2024 Novostroev Ivan

#include <iostream>
#include <string>
#include "../include/bulls_cows_app.h"

int main(int argc, const char** argv) {
    BullsCowsApplication app;
    std::string res = app.doWork(argc, argv);
    std::cout << res;
    return 0;
}
