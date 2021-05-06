// Copyright 2021 Alibekov Murad

#include <gtest/gtest.h>

#include "include/polygon.h"

TEST(Alibekov_Murad_Polygon_Tests, Throw_If_Polygon_Without_Points) {
    // Arrange
    Points2D polygon = {};

    // Assert
    ASSERT_ANY_THROW(Polygon::PolygonArea(polygon));
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Point_Is_0) {
    // Arrange
    Points2D point = {{1, 1}};

    // Act
    double area = Polygon::PolygonArea(point);

    // Assert
    ASSERT_DOUBLE_EQ(0., area);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Line_Is_0) {
    // Arrange
    Points2D line = {{0, 0}, {1, 2}};

    // Act
    double area = Polygon::PolygonArea(line);

    // Assert
    ASSERT_DOUBLE_EQ(0., area);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Triangle) {
    // Arrange
    Points2D triangle = {{1.5, -0.5}, {1, 1}, {-1, 0.5}};

    // Act
    double area = Polygon::PolygonArea(triangle);

    // Assert
    ASSERT_DOUBLE_EQ(1.625, area);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Square) {
    // Arrange
    Points2D square = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

    // Act
    double area = Polygon::PolygonArea(square);

    // Assert
    ASSERT_DOUBLE_EQ(1., area);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Hexagon) {
    // Arrange
    Points2D hexagon = {{-2, 0}, {-1, 1}, {0.5, 1},
        {1.5, 0}, {0.5, -1}, {-1, -1}};

    // Act
    double area = Polygon::PolygonArea(hexagon);

    // Assert
    ASSERT_DOUBLE_EQ(5., area);
}

TEST(Alibekov_Murad_Polygon_Tests, Area_Of_Non_Convex_Pentagon) {
    // Arrange
    Points2D nonconvex_pentagon = {{3, 4}, {5, 11}, {12, 8}, {9, 5}, {5, 6}};

    // Act
    double area = Polygon::PolygonArea(nonconvex_pentagon);

    // Assert
    ASSERT_DOUBLE_EQ(30., area);
}
