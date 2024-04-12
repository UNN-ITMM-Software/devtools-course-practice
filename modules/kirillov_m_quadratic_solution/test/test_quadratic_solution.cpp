// Copyright 2024 Kirillov Maxim

#include <gtest/gtest.h>
#include <unordered_set>
#include "../include/quadratic_solution.h"

TEST(Kirillov_M_Quadratic_Solution, TestInitCoefficients) {
    double a = 1, b = 2, c = 1;
    QuadraticSolver solver(a, b, c);
    EXPECT_EQ(solver.getA(), a);
    EXPECT_EQ(solver.getB(), b);
    EXPECT_EQ(solver.getC(), c);
}

TEST(Kirillov_M_Quadratic_Solution, TestDiscriminantZero) {
    double a = 1, b = 2, c = 1;
    QuadraticSolver solver(a, b, c);
    EXPECT_EQ(solver.getDiscriminant(), 0);
}

TEST(Kirillov_M_Quadratic_Solution, TestDiscriminantPositive) {
    double a = 2.4, b = 3, c = -1.9;
    QuadraticSolver solver(a, b, c);
    EXPECT_GT(solver.getDiscriminant(), 0);
}

TEST(Kirillov_M_Quadratic_Solution, TestDiscriminantNegative) {
    double a = 2, b = -3.3, c = 5.13;
    QuadraticSolver solver(a, b, c);
    EXPECT_LT(solver.getDiscriminant(), 0);
}

TEST(Kirillov_M_Quadratic_Solution, TestGetRealRoots) {
    double a = 1, b = -5, c = 6;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {2, 3};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestGetOneRealRoot) {
    double a = 1, b = -2, c = 1;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {1};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestFirstCoefficientEqualsZero) {
    double a = 0, b = -2, c = 1;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {0.5};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestSecondCoefficientEqualsZero) {
    double a = 1, b = 0, c = -9;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {3, -3};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestThirdCoefficientEqualsZero) {
    double a = 1, b = 4, c = 0;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {0,  -4};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestSecondThirdCoefficientsEqualsZero) {
    double a = 2, b = 0, c = 0;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {0};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestFirstSecondCoefficientsEqualsZero) {
    double a = 0, b = 0, c = 1;
    QuadraticSolver solver(a, b, c);
    EXPECT_THROW(solver.solve(), std::runtime_error);
}

TEST(Kirillov_M_Quadratic_Solution, TestFirstThirdCoefficientsEqualsZero) {
    double a = 0, b = 15, c = 0;
    QuadraticSolver solver(a, b, c);
    std::vector<double> roots = solver.solve();
    std::unordered_set<double> actualRoots(roots.begin(), roots.end());
    std::unordered_set<double> expectedRoots = {0};
    EXPECT_EQ(expectedRoots, actualRoots);
}

TEST(Kirillov_M_Quadratic_Solution, TestAllCoefficientsEqualsZero) {
    double a = 0, b = 0, c = 0;
    QuadraticSolver solver(a, b, c);
    EXPECT_EQ(solver.solve(), std::vector<double>());
}

TEST(Kirillov_M_Quadratic_Solution, TestGetComplexRoots) {
    double a = 1, b = 2, c = 5;
    QuadraticSolver solver(a, b, c);
    std::vector<std::complex<double>> roots = solver.solveComplex();
    std::complex<double> expectedRoot1(-1, 2);
    std::complex<double> expectedRoot2(-1, -2);
    EXPECT_TRUE(((roots[0] == expectedRoot1 && roots[1] == expectedRoot2) ||
    (roots[1] == expectedRoot1 && roots[0] == expectedRoot2)));
}

