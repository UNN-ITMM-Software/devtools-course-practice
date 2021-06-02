// Copyright 2021 Taktaev Artem

#include <iostream>
#include <string>

#include "include/dheap_app.h"

int main(int argc, const char* argv[]) {
    DheapApp app;
    int retcode = 0;
    std::cout << app(argc, argv, &retcode);
    return retcode;
}
