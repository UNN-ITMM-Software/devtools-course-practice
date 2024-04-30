// Copyright 2024 Savchuk Anton

#include <cmath>

#include "gtest/gtest.h"
#include "include/savchuk_intersectio.h"

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

TEST(OrientationTest, OrientationCheck) {
    Point p1(1, 1);
    Point q1(3, 3);
    Point p2(2, 2);
    Point q2(4, 4);

    ASSERT_EQ(orientation(p1, q1, p2), 0);
    ASSERT_EQ(orientation(p1, q1, q2), 0);
    ASSERT_EQ(orientation(p2, q2, p1), 0);
    ASSERT_EQ(orientation(p2, q2, q1), 0);
    ASSERT_EQ(orientation(p1, q1, Point(4, 2)), 1);
    ASSERT_EQ(orientation(p1, q1, Point(2, 4)), 2);
}
