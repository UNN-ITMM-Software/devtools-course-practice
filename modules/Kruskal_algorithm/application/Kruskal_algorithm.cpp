// Copyright 2021 Gushchin Artem

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Kruskal_algorithm_app.h"

int main(int argc, const char** argv) {
    KruskalAlgorithm app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
