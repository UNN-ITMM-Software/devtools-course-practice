// Copyright 2021 Pronkin Dmitry

#include <gtest/gtest.h>
#include <vector>

#include "include/wave_algorithm.h"

TEST(WaveAlgorithm, Two_IncorrectMapSizesExc) {
    ASSERT_ANY_THROW(WaveLib::WaveAlgorithm algorithm(-1, -1));
}

TEST(WaveAlgorithm, Two_NoExc) {
    ASSERT_NO_THROW(WaveLib::WaveAlgorithm algorithm(1, 1));
}

TEST(WaveAlgorithm, Three_MapEmptyExc) {
    std::vector<int> map;
    ASSERT_ANY_THROW(WaveLib::WaveAlgorithm algorithm(1, 1, map));
}

TEST(WaveAlgorithm, Three_IncorrectMapSizesExc) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    ASSERT_ANY_THROW(WaveLib::WaveAlgorithm algorithm(-1, -1, map));
}

TEST(WaveAlgorithm, Three_IncorrectMapDimensionExc) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    ASSERT_ANY_THROW(WaveLib::WaveAlgorithm algorithm(1, 1, map));
}

TEST(WaveAlgorithm, Start_PointOutOfMapExc) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(-1, -1);
    WaveLib::Point finish(0, 0);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, Finish_PointOutOfMapExc) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(0, 0);
    WaveLib::Point finish(4, 4);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, Both_PointOutOfMapExc) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(-1, 1);
    WaveLib::Point finish(4, 4);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, Start_PointOnWall) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(0, 1);
    WaveLib::Point finish(0, 0);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, Finish_PointOnWall) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(0, 0);
    WaveLib::Point finish(1, 0);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, Both_PointOnWall) {
    std::vector<int> map = {
        FREE, WALL,
        WALL, FREE
    };
    WaveLib::WaveAlgorithm algorithm(2, 2, map);
    WaveLib::Point start(0, 1);
    WaveLib::Point finish(1, 0);
    std::vector<WaveLib::Point> path;
    ASSERT_ANY_THROW(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, PathNotFound) {
    std::vector<int> map = {
        FREE, FREE, FREE,
        WALL, WALL, WALL,
        WALL, FREE, FREE
    };
    WaveLib::WaveAlgorithm algorithm(3, 3, map);
    WaveLib::Point start(0, 0);
    WaveLib::Point finish(2, 2);
    std::vector<WaveLib::Point> path;
    ASSERT_FALSE(algorithm.findPath(start, finish, &path));
}

TEST(WaveAlgorithm, SquareMap_PathFound) {
    std::vector<int> map = {
        WALL, FREE, FREE, WALL, WALL,
        FREE, WALL, WALL, WALL, FREE,
        WALL, FREE, FREE, WALL, FREE,
        WALL, WALL, FREE, WALL, FREE,
        WALL, WALL, FREE, FREE, WALL
    };
    WaveLib::WaveAlgorithm algorithm(5, 5, map);
    WaveLib::Point start(1, 0);
    WaveLib::Point finish(4, 2);
    std::vector<WaveLib::Point> path;
    std::vector<WaveLib::Point> testPath = {
        WaveLib::Point(1, 0),
        WaveLib::Point(0, 1),
        WaveLib::Point(1, 2),
        WaveLib::Point(2, 3),
        WaveLib::Point(3, 4),
        WaveLib::Point(4, 3),
        WaveLib::Point(4, 2)
    };
    algorithm.findPath(start, finish, &path);
    ASSERT_EQ(testPath, path);
}

TEST(WaveAlgorithm, RectangularMap_PathFound) {
    std::vector<int> map = {
        WALL, WALL, WALL, FREE, FREE, WALL,
        WALL, WALL, WALL, WALL, FREE, WALL,
        FREE, WALL, FREE, FREE, WALL, FREE,
        FREE, FREE, WALL, WALL, FREE, WALL
    };
    WaveLib::WaveAlgorithm algorithm(4, 6, map);
    WaveLib::Point start(3, 0);
    WaveLib::Point finish(0, 3);
    std::vector<WaveLib::Point> path;
    std::vector<WaveLib::Point> testPath = {
        WaveLib::Point(3, 0),
        WaveLib::Point(4, 1),
        WaveLib::Point(3, 2),
        WaveLib::Point(2, 2),
        WaveLib::Point(1, 3),
        WaveLib::Point(0, 3)
    };
    algorithm.findPath(start, finish, &path);
    ASSERT_EQ(testPath, path);
}
