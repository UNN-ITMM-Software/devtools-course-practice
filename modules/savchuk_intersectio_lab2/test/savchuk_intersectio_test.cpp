// Copyright 2024 Savchuk Anton

#include <gtest/gtest.h>
#include <cmath>

#include "include/savchuk_intersectio.h"

TEST(OrientationTest, Collinear) {
    Point p(1, 1);
    Point q(2, 2);
    Point r(3, 3);
    ASSERT_EQ(orientation(p, q, r), 0);
}

TEST(OrientationTest, Clockwise) {
    Point p(1, 1);
    Point q(2, 3);
    Point r(3, 2);
    ASSERT_EQ(orientation(p, q, r), 1);
}

TEST(OrientationTest, CounterClockwise) {
    Point p(1, 1);
    Point q(3, 2);
    Point r(2, 3);
    ASSERT_EQ(orientation(p, q, r), 2);
}

TEST(PointTest, ConstructorAndGetters) {
    double x = 3.14;
    double y = 2.71;
    Point p(x, y);

    double actualX = p.getX();
    double actualY = p.getY();

    ASSERT_DOUBLE_EQ(x, actualX);
    ASSERT_DOUBLE_EQ(y, actualY);
}

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
