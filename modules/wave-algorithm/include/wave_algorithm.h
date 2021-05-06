// Copyright 2021 Pronkin Dmitry

#ifndef MODULES_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_H_
#define MODULES_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_H_

constexpr int WALL = -2;
constexpr int FREE = -1;

#include <algorithm>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

namespace WaveLib {
using Point = std::pair<int, int>;
class WaveAlgorithm {
 private:
    int mapHeight;
    int mapWidth;
    std::vector<int> map;
 public:
    WaveAlgorithm(int _mapHeight, int _mapWidth);
    WaveAlgorithm(int _mapHeight, int _mapWidth, const std::vector<int>& _map);

    bool findPath(
        const Point& start,
        const Point& finish,
        std::vector<Point>* path);

 private:
    bool waveProp(const Point& start, const Point& finish);
    void buildPath(
        const Point& start,
        const Point& finish,
        std::vector<Point>* path);
    bool checkPoint(const Point& currPoint);
};
}  // namespace WaveLib

#endif  // MODULES_WAVE_ALGORITHM_INCLUDE_WAVE_ALGORITHM_H_
