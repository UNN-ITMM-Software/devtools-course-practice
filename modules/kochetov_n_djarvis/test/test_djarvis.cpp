// Copyright 2024 Kochetov Nikolay

#include <gtest/gtest.h>

#include "include/djarvis.h"

// Тест для поиска выпуклой оболочки для пустого набора точек
TEST(Kochetov_n_djarvis, EmptySet) {
    std::vector<Point> points;
    ConvexHull convexHull(points);
    std::vector<Point> hull = convexHull.findConvexHull();

    // Ожидаем, что выпуклая оболочка пуста для пустого набора точек
    ASSERT_TRUE(hull.empty());
}

// Тест для поиска выпуклой оболочки для набора точек,
// образующих выпуклый многоугольник
TEST(Kochetov_n_djarvis, ConvexPolygon) {
    std::vector<Point> points = {{0, 0}, {1, 2}, {2, 3}, {3, 1}, {1, 0}};
    ConvexHull convexHull(points);
    std::vector<Point> hull = convexHull.findConvexHull();

    // Ожидаем, что выпуклая оболочка содержит 5 точек
    ASSERT_EQ(hull.size(), (size_t)5);

    // Ожидаем, что выпуклая оболочка содержит угловые точки многоугольника
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[1].x, 1);
    EXPECT_EQ(hull[1].y, 2);
    EXPECT_EQ(hull[2].x, 2);
    EXPECT_EQ(hull[2].y, 3);
    EXPECT_EQ(hull[3].x, 3);
    EXPECT_EQ(hull[3].y, 1);
}

// Тест для поиска выпуклой оболочки для набора точек,
// образующих невыпуклый многоугольник
TEST(Kochetov_n_djarvis, ConcavePolygon) {
    std::vector<Point> points = {{0, 0}, {1, 1}, {2, 3}, {3, 1}, {1, 0}};
    ConvexHull convexHull(points);
    std::vector<Point> hull = convexHull.findConvexHull();

    // Ожидаем, что выпуклая оболочка содержит 5 точек
    ASSERT_EQ(hull.size(), (size_t)5);

    // Ожидаем, что выпуклая оболочка содержит вершины выпуклой оболочки
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[1].x, 1);
    EXPECT_EQ(hull[1].y, 1);
    EXPECT_EQ(hull[2].x, 2);
    EXPECT_EQ(hull[2].y, 3);
    EXPECT_EQ(hull[3].x, 3);
    EXPECT_EQ(hull[3].y, 1);
}

// Тест для поиска выпуклой оболочки для набора точек,
// все из которых находятся на одной прямой
TEST(Kochetov_n_djarvis, CollinearPoints) {
    std::vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    ConvexHull convexHull(points);
    std::vector<Point> hull = convexHull.findConvexHull();

    // Ожидаем, что выпуклая оболочка содержит 4 точки
    ASSERT_EQ(hull.size(), (size_t)4);
    // Ожидаем, что выпуклая оболочка содержит крайние точки
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[3].x, 3);
    EXPECT_EQ(hull[3].y, 3);
}

// Тест для поиска выпуклой оболочки для набора точек с повторяющимися точками
TEST(Kochetov_n_djarvis, DuplicatePoints) {
    std::vector<Point> points =
    {{0, 0}, {1, 1}, {2, 2}, {0, 0}, {1, 1}, {2, 2}};
    ConvexHull convexHull(points);
    std::vector<Point> hull = convexHull.findConvexHull();

    // Ожидаем, что выпуклая оболочка содержит 6 различных точек
    ASSERT_EQ(hull.size(), (size_t)6);
    // Ожидаем, что выпуклая оболочка содержит различные угловые точки
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[1].x, 1);
    EXPECT_EQ(hull[1].y, 1);
    EXPECT_EQ(hull[2].x, 2);
    EXPECT_EQ(hull[2].y, 2);
}
