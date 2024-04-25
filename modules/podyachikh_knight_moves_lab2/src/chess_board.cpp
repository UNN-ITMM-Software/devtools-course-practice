// Copyright 2024 Podyachikh Mikhail

#include <map>
#include <queue>
#include <stdexcept>

#include "include/chess_board.h"

#define X first
#define Y second

/**
 * If there is already an obstacle at this point, do nothing
 *
 * @param point The point where should be an obstacle
 */
void ChessBoard::addObstacle(const ChessBoard::Point &point) {
  if (!inside(point)) {
    throw std::invalid_argument(
        "The point of the added obstacle outside the chessboard");
  }
  obstacles.insert(point);
}

bool ChessBoard::inside(const ChessBoard::Point &point) const {
  if (point.X < 0 || point.X >= _size)
    return false;
  if (point.Y < 0 || point.Y >= _size)
    return false;
  return true;
}

bool ChessBoard::available(const ChessBoard::Point &point) {
  if (!inside(point))
    return false;
  // If not obstacle
  return obstacles.find(point) == obstacles.end();
}

std::set<ChessBoard::Point>
ChessBoard::getPossibleMoves(const ChessBoard::Point &point) {
  std::set<Point> possibleMoves;
  for (const auto &move : knightMoves) {
    Point nextPoint = {point.X + move.X, point.Y + move.Y};
    if (available(nextPoint))
      possibleMoves.insert(nextPoint);
  }
  return possibleMoves;
}

/**
 * Calculate the minimum number of moves a knight on a chessboard needs to reach
 * from the start point to the end point using Breadth-First Search (BFS).
 *
 * This function calculates the minimum number of moves required for a knight to
 * reach from the start point to the end point on a chessboard,
 * assuming the cells of the chessboard are described by a pair of co-ordinate
 * numbers. Each coordinate can take values from 0 to n-1 inclusive
 *
 * @param start The starting point (row, column) on the chessboard.
 * @param end The ending point (row, column) on the chessboard.
 * @throws std::invalid_argument Exception with appropriate message if start or
 * end point is not available.
 * @return The minimum number of moves required for the knight to reach from
 * start to end. Returns -1 if the endpoint is unreachable
 */
int ChessBoard::knightDistance(ChessBoard::Point start, ChessBoard::Point end) {
  if (!available(start)) {
    throw std::invalid_argument("Start point is not available");
  }
  if (!available(end)) {
    throw std::invalid_argument("End point is not available");
  }
  return bfs(start, end);
}

int ChessBoard::bfs(ChessBoard::Point start, ChessBoard::Point end) {
  std::map<Point, int> dist;
  dist[start] = 0;

  std::queue<Point> q;
  q.push(start);

  while (!q.empty()) {
    Point current = q.front();
    if (current == end) {
      return dist[end];
    }
    q.pop();
    auto nextPoints = getPossibleMoves(current);
    for (auto next : nextPoints) {
      if (dist.find(next) != dist.end())
        continue;
      dist[next] = dist[current] + 1;
      q.push(next);
    }
  }
  return -1;
}
