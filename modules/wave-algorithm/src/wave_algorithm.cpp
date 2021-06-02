// Copyright 2021 Pronkin Dmitry

#include <algorithm>
#include <queue>
#include <vector>

#include "include/wave_algorithm.h"

WaveLib::WaveAlgorithm::WaveAlgorithm(int _mapHeight, int _mapWidth) {
    if (_mapHeight < 1 || _mapWidth < 1) {
        throw std::invalid_argument("Incorrect map sizes");
    }
    mapHeight = _mapHeight;
    mapWidth = _mapWidth;
    map = std::vector<int>(mapHeight * mapWidth, FREE);
}

WaveLib::WaveAlgorithm::WaveAlgorithm(
    int _mapHeight,
    int _mapWidth,
    const std::vector<int>& _map
    ) {
    if (_map.empty()) {
        throw std::invalid_argument("Map is empty");
    }
    if (_mapHeight < 1 || _mapWidth < 1) {
        throw std::invalid_argument("Incorrect map sizes");
    }
    if (_map.size() != static_cast<size_t>(_mapHeight * _mapWidth)) {
        throw std::invalid_argument("Incorrect map dimensions");
    }
    mapHeight = _mapHeight;
    mapWidth = _mapWidth;
    map = _map;
}

bool WaveLib::WaveAlgorithm::findPath(
    const Point& start,
    const Point& finish,
    std::vector<Point>* path
    ) {
    if (start.first < 0 || start.first > mapWidth - 1 ||
        start.second < 0 || start.second > mapHeight - 1 ||
        finish.first < 0 || finish.first > mapWidth - 1 ||
        finish.second < 0 || finish.second > mapHeight - 1) {
        throw std::invalid_argument("Point out of map");
    }
    if (map[start.second * mapWidth + start.first] == WALL ||
        map[finish.second * mapWidth + finish.first] == WALL) {
        throw std::invalid_argument("Point on Wall");
    }
    std::vector<int> tmpMap = map;
    map[start.second * mapWidth + start.first] = 0;
    if (!waveProp(start, finish)) return false;
    buildPath(start, finish, path);
    map = tmpMap;
    std::reverse(path->begin(), path->end());
    return true;
}

bool WaveLib::WaveAlgorithm::waveProp(const Point& start, const Point& finish) {
    std::queue<Point> wavePointQueue({start});
    bool pathFound = false;
    while (!wavePointQueue.empty()) {
        Point currPoint = wavePointQueue.front();
        if (currPoint == finish) { pathFound = true; }
        for (int j = -1; j <= 1; j++) {
            for (int i = -1; i <= 1; i++) {
                Point wavePoint(currPoint.first + i, currPoint.second + j);
                if (currPoint != wavePoint &&
                    checkPoint(wavePoint) &&
                    map[wavePoint.second * mapWidth + wavePoint.first]
                    == FREE) {
                    map[wavePoint.second * mapWidth + wavePoint.first] =
                    map[currPoint.second * mapWidth + currPoint.first] + 1;
                    wavePointQueue.push(wavePoint);
                }
            }
        }
        wavePointQueue.pop();
    }
    return pathFound;
}

void WaveLib::WaveAlgorithm::buildPath(
    const Point& start,
    const Point& finish,
    std::vector<Point>* path
    ) {
    Point currPoint(finish);
    path->push_back(currPoint);
    while (currPoint != start) {
        for (int j = -1; j <= 1; j++) {
            for (int i = -1; i <= 1; i++) {
                Point pathPoint(currPoint.first + i, currPoint.second + j);
                if (currPoint != pathPoint &&
                    checkPoint(pathPoint) &&
                    map[pathPoint.second * mapWidth + pathPoint.first] + 1 ==
                    map[currPoint.second * mapWidth + currPoint.first]) {
                    currPoint = pathPoint;
                    path->push_back(currPoint);
                    break;
                }
            }
        }
    }
}

bool WaveLib::WaveAlgorithm::checkPoint(const Point& currPoint) {
    if (currPoint.first < 0 || currPoint.first > mapWidth - 1 ||
        currPoint.second < 0 || currPoint.second > mapHeight - 1 ||
        map[currPoint.second * mapWidth + currPoint.first] == WALL) {
        return false;
    }
    return true;
}
