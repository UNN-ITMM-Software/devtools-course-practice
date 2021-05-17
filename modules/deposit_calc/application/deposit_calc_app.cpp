// Copyright 2021 Belik Julia

#include <iostream>
#include <string>

#include "include/DepositCalc_app.h"

int main(int argc, const char** argv) {
    DepositCalc_app app;
    std::string out = app(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
