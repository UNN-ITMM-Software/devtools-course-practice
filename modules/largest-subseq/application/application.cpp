// Copyright 2021 Lukyanchenko Ivan

#include <iostream>
#include <string>

#include "include/largest_subseq_app.h"

int main(int argc, const char** argv) {
    Lar_SubseqApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
