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

TEST(TwoSegmentsTest, IntersectionAtEndpoint) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(3, 3), Point(5, 5));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, IntersectionAtStartpoint) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(1, 1), Point(2, 2));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, IntersectionAtMiddle) {
    Segment segment1(Point(1, 1), Point(5, 5));
    Segment segment2(Point(3, 3), Point(7, 7));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, OverlappingSegments) {
    Segment segment1(Point(1, 1), Point(5, 5));
    Segment segment2(Point(3, 3), Point(7, 7));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, TouchingSegments) {
    Segment segment1(Point(1, 1), Point(3, 3));
    Segment segment2(Point(3, 3), Point(5, 5));

    ASSERT_TRUE(TwoSegments::checkIntersection(segment1, segment2));
}

TEST(TwoSegmentsTest, VerticalAndHorizontalSegmentsNoIntersection) {
    Segment segment1(Point(1, 1), Point(1, 3));
    Segment segment2(Point(2, 4), Point(4, 4));

    ASSERT_FALSE(TwoSegments::checkIntersection(segment1, segment2));
}
