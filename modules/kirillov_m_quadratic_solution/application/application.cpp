// Copyright 2024 Smirnov Leonid

#include "include/quadratic_solution_application.h"
#include <iostream>

int main(int argc, char* argv[]) {
    QuadraticSolverApplication app;
    std::cout << app.SolveQuadraticEquation(argc, argv) << std::endl;
    return 0;
}
