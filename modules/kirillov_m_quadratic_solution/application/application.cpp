// Copyright 2024 Smirnov Leonid

#include <iostream>

#include "include/quadratic_solution_application.h"


int main(int argc, char* argv[]) {
    QuadraticSolverApplication app;
    std::cout << app.SolveQuadraticEquation(argc, argv) << std::endl;
    return 0;
}
