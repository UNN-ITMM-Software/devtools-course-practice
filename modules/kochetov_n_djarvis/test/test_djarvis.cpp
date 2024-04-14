// Copyright 2024 Kochetov Nikolay

#include <gtest/gtest.h>

#include "include/djarvis.h"

// Тест для поиска выпуклой оболочки для пустого набора точек
TEST(Kochetov_n_djarvis, EmptySet) {
    vector<Point> points;
    ConvexHull convexHull(points);
    vector<Point> hull = convexHull.findConvexHull();

    ASSERT_TRUE(hull.empty()); // Ожидаем, что выпуклая оболочка пуста для пустого набора точек
}

// Тест для поиска выпуклой оболочки для набора точек, образующих выпуклый многоугольник
TEST(Kochetov_n_djarvis, ConvexPolygon) {
    vector<Point> points = {{0, 0}, {1, 2}, {2, 3}, {3, 1}, {1, 0}};
    ConvexHull convexHull(points);
    vector<Point> hull = convexHull.findConvexHull();

    ASSERT_EQ(hull.size(), 5); // Ожидаем, что выпуклая оболочка содержит 5 точек
    // Ожидаем, что выпуклая оболочка содержит угловые точки многоугольника
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[1].x, 1);
    EXPECT_EQ(hull[1].y, 0);
    EXPECT_EQ(hull[2].x, 3);
    EXPECT_EQ(hull[2].y, 1);
    EXPECT_EQ(hull[3].x, 2);
    EXPECT_EQ(hull[3].y, 3);
}

// Тест для поиска выпуклой оболочки для набора точек, образующих невыпуклый многоугольник
TEST(Kochetov_n_djarvis, ConcavePolygon) {
    vector<Point> points = {{0, 0}, {1, 1}, {2, 3}, {3, 1}, {1, 0}};
    ConvexHull convexHull(points);
    vector<Point> hull = convexHull.findConvexHull();

    ASSERT_EQ(hull.size(), 4); // Ожидаем, что выпуклая оболочка содержит 4 точки
    // Ожидаем, что выпуклая оболочка содержит вершины выпуклой оболочки
    EXPECT_EQ(hull[0].x, 0);
    EXPECT_EQ(hull[0].y, 0);
    EXPECT_EQ(hull[1].x, 1);
    EXPECT_EQ(hull[1].y, 0);
    EXPECT_EQ(hull[2].x, 3);
    EXPECT_EQ(hull[2].y, 1);
    EXPECT_EQ(hull[3].x, 2);
    EXPECT_EQ(hull[3].y, 3);
}
