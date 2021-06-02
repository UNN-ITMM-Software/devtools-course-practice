// Copyright 2021 Vlasov Maksim

#include <iostream>
#include <string>

#include "include/qsorter.h"

int main(int argc, const char* argv[]) {
    QSort::Sorter app;
    int retcode = 0;
    std::cout << app(argc, argv, &retcode);
    return retcode;
}
