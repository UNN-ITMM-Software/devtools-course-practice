// Copyright 2024 Kachalov Mikhail

#include <gtest/gtest.h>

#include <cmath>

#include "include/polygon_area_calculator.h"

TEST(Kachalov_PolygonAreaCalculator, CalculatesTriangleArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(4.0, 0.0);
    areaCalculator.addVertex(0.0, 3.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 6.0;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesRectangleArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(4.0, 0.0);
    areaCalculator.addVertex(4.0, 3.0);
    areaCalculator.addVertex(0.0, 3.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 12.0;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesPentagonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(4.0, 0.0);
    areaCalculator.addVertex(5.0, 2.0);
    areaCalculator.addVertex(2.0, 4.0);
    areaCalculator.addVertex(-1.0, 2.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 16;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesHexagonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(2.0, 0.0);
    areaCalculator.addVertex(1.0, std::sqrt(3.0));
    areaCalculator.addVertex(-1.0, std::sqrt(3.0));
    areaCalculator.addVertex(-2.0, 0.0);
    areaCalculator.addVertex(-1.0, -std::sqrt(3.0));
    areaCalculator.addVertex(1.0, -std::sqrt(3.0));

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 10.3923;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-4);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesOctagonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(2.0, 0.0);
    areaCalculator.addVertex(std::sqrt(2.0), std::sqrt(2.0));
    areaCalculator.addVertex(0.0, 2.0);
    areaCalculator.addVertex(-std::sqrt(2.0), std::sqrt(2.0));
    areaCalculator.addVertex(-2.0, 0.0);
    areaCalculator.addVertex(-std::sqrt(2.0), -std::sqrt(2.0));
    areaCalculator.addVertex(0.0, -2.0);
    areaCalculator.addVertex(std::sqrt(2.0), -std::sqrt(2.0));

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 11.3137;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-4);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesArbitraryPolygonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(1.0, 1.0);
    areaCalculator.addVertex(4.0, 0.0);
    areaCalculator.addVertex(5.0, 3.0);
    areaCalculator.addVertex(3.0, 4.0);
    areaCalculator.addVertex(0.0, 4.0);
    areaCalculator.addVertex(0.0, 2.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 14.5;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-4);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesDegeneratePolygonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(0.0, 0.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 0.0;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);
}

TEST(Kachalov_PolygonAreaCalculator, CalculatesNonConvexPolygonArea) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(2.0, 2.0);
    areaCalculator.addVertex(1.0, 1.0);
    areaCalculator.addVertex(2.0, 0.0);
    areaCalculator.addVertex(0.0, 2.0);

    double calculatedArea = areaCalculator.calculateArea();

    double expectedArea = 1.0;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-4);
}

TEST(Kachalov_PolygonAreaCalculator, ThrowsExceptionForInsufficientVertices) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(1.0, 1.0);

    EXPECT_THROW(areaCalculator.calculateArea(), std::logic_error);
}

TEST(Kachalov_PolygonAreaCalculator, ClearsVertices) {
    PolygonAreaCalculator areaCalculator;
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(4.0, 0.0);
    areaCalculator.addVertex(0.0, 3.0);

    double calculatedArea = areaCalculator.calculateArea();
    double expectedArea = 6.0;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);

    areaCalculator.clearVertices();
    areaCalculator.addVertex(0.0, 0.0);
    areaCalculator.addVertex(1.0, 0.0);
    areaCalculator.addVertex(0.0, 1.0);

    calculatedArea = areaCalculator.calculateArea();
    expectedArea = 0.5;
    EXPECT_NEAR(calculatedArea, expectedArea, 1e-5);
}
