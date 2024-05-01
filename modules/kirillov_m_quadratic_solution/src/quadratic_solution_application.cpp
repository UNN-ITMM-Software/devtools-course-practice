// Copyright 2024 Smirnov Leonid

#include "include/quadratic_solution_application.h"

#include <cstring>
#include <exception>
#include <sstream>

void QuadraticSolverApplication::Help
(const char *appName, const char *errorMsg) {
    std::stringstream message;
    if (errorMsg) {
        message << "Error: " << errorMsg << '\n';
    }

    message << "This is an application for solving "
               "quadratic equations of the form ax^2 + bx + c = 0; \n";

    message << "Usage: \n";
    message << '\t' << appName << " <a> <b> <c>; \n";

    message << "Where: \n";
    message << '\t' << " <a>, <b>, <c> - "
                       "are coefficients of the quadratic equation; \n";

    msg = message.str();
}

bool QuadraticSolverApplication::Validate(int argc, char *argv[]) {
    int required_arguments = 4;

    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (std::strcmp(argv[1], "--help") == 0) {
        Help(argv[0]);
        return false;
    } else if (argc != required_arguments) {
        Help(argv[0], "Incorrect number of arguments.");
        return false;
    } else {
        try {
            double a = std::stod(argv[1]);
            double b = std::stod(argv[2]);
            double c = std::stod(argv[3]);

            solver = QuadraticSolver(a, b, c);
        } catch(const std::exception& e) {
            Help(argv[0], "Invalid arguments.");
            return false;
        }
    }

    return true;
}

std::string QuadraticSolverApplication::SolveQuadraticEquation
(int argc, char *argv[]) {
    if (Validate(argc, argv)) {
        try {
            std::stringstream output;

            if (solver.getDiscriminant() >= 0) {
                RealResult real_result = solver.solveRealRoots();
                output << "Real Roots: ";
                for (auto root : real_result.second) {
                    output << root << " ";
                }
            } else {
                ComplexResult complexResult = solver.solveComplexRoots();
                output << "Complex Roots: ";
                for (auto root : complexResult.second) {
                    output << root.real() << "+" << root.imag() << "i ";
                }
            }

            return output.str();
        } catch(const std::exception& e) {
            return "Error: Invalid input.";
        }
    }
    return msg;
}
