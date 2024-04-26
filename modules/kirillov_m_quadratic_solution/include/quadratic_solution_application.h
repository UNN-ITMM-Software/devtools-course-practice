// Copyright 2024 Smirnov Leonid

#pragma once

#include <string>
#include "quadratic_solution.h"

class QuadraticSolverApplication {
private:
    std::string msg;
    QuadraticSolver solver;
    void Help(const char* appName, const char* errorMsg = nullptr);
    bool Validate(int argc, char* argv[]);

public:
    QuadraticSolverApplication() = default;
    std::string SolveQuadraticEquation(int argc, char* argv[]);
};

