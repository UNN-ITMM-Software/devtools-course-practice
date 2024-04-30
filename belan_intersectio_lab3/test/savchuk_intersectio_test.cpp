// Copyright 2024 Savchuk Anton

#include <gtest/gtest.h>
#include <cmath>

#include "include/savchuk_intersectio.h"
#include "include/console_application.h"

TEST(TwoSegmentsTest, Intersection) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(2, 2), Point(4, 4));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, NoIntersection) {
    Segment segment1(Point(1, 1), Point(2, 2));
    Segment segment2(Point(3, 3), Point(4, 4));

    ASSERT_FALSE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, Parallel) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(1, 1), Point(4, 4));

    ASSERT_TRUE(TwoSegments::checkParallel(segment1, segment2));
}

TEST(TwoSegmentsTest, NoParallel) {
    Segment segment1(Point(1, 2), Point(2, 3));
    Segment segment2(Point(1, 1), Point(2, 1));

    ASSERT_FALSE(TwoSegments::checkParallel(segment1, segment2));
}

TEST(TwoSegmentsTest, Collinear) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(1, 1), Point(3, 3));
    ASSERT_TRUE(TwoSegments::checkParallel(segment1, segment2));

    Segment segment3(Point(1, 1), Point(3, 3));
    Segment segment4(Point(2, 2), Point(2.5, 2.5));
    ASSERT_TRUE(TwoSegments::checkParallel(segment3, segment4));
}

TEST(TwoSegmentsTest, VerticalSegments) {
    Segment segment1(Point(1, 1), Point(1, 3));
    Segment segment2(Point(2, 2), Point(2, 4));

    ASSERT_TRUE(TwoSegments::checkParallel(segment1, segment2));
}

TEST(TwoSegmentsTest, HorizontalSegments) {
    Segment segment1(Point(1, 1), Point(3, 1));
    Segment segment2(Point(2, 2), Point(4, 2));

    ASSERT_TRUE(TwoSegments::checkParallel(segment1, segment2));
}

TEST(OrientationTest, CounterClockwise) {
    Point p(1, 1);
    Point q(3, 2);
    Point r(2, 3);
    ASSERT_EQ(orientation(p, q, r), 2);
}

TEST(PointTest, GetX) {
    double x = 3.14;
    double y = 2.71;
    Point p(x, y);

    ASSERT_DOUBLE_EQ(x, p.getX());
}

TEST(PointTest, GetY) {
    double x = 3.14;
    double y = 2.71;
    Point p(x, y);

    ASSERT_DOUBLE_EQ(y, p.getY());
}

TEST(TwoSegmentsTest, DifferentOrientationsReturnTrue) {
    int o1 = 1, o2 = 2, o3 = 1, o4 = 2;
    ASSERT_TRUE(o1 != o2 && o3 != o4);
}

TEST(TwoSegmentsTest, SameOrientationsReturnFalse) {
    int o1 = 1, o2 = 1, o3 = 2, o4 = 2;
    ASSERT_FALSE(o1 != o2 && o3 != o4);
}
