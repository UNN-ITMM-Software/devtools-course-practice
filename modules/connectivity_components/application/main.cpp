// Copyright 2021 Tkachev Alexey

#include <string>

#include "include/app_connectivity_components.h"

int main(int argc, const char** argv) {
    AppConnComponents app;
    std::string out = app(argc, argv);
    printf("%s\n", out.c_str());
    return 0;
}
