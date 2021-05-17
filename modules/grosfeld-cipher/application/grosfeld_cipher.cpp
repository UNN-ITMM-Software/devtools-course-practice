// Copyright 2021 Pronkin Dmitry

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "include/grosfeld_cipher_app.h"

int main(int argc, const char** argv) {
    GronsfeldCipherApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
