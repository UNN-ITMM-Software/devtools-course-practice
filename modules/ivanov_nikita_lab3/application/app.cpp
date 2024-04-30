// Copyright 2024 Ivanov Nikita
#include <string>

#include "../include/lcs_app.h"

int main(int argc, const char** argv) {
    LCSApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}