// Copyright 2024 Podyachikh Mikhail
#ifndef MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_H_
#define MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_H_

#include <set>
#include <utility>

class ChessBoard {
  using Point = std::pair<int, int>;
  int _size;
  std::set<Point> obstacles;

 public:
  /**
   * @brief Constructs a ChessBoard object.
   *
   * Initializes a ChessBoard object with the specified size and set of
   * obstacles.
   *
   * @param size The size of the chessboard (default is 8x8).
   * @param obstacles A set of obstacles represented as a set of points (default
   * is empty).
   */
  explicit ChessBoard(int size = 8, const std::set<Point> &obstacles = {})
      : _size(size), obstacles(obstacles) {}
  void addObstacle(const ChessBoard::Point &point);
  int knightDistance(Point start, Point end);

 private:
  bool inside(const ChessBoard::Point &point) const;
  bool available(const ChessBoard::Point &point);
  std::set<Point> getPossibleMoves(const ChessBoard::Point &point);
  int bfs(Point start, Point end);
  std::set<Point> knightMoves = {{1, 2},   {2, 1},   /*I quarter*/
                                 {2, -1},  {1, -2},  /*II quarter*/
                                 {-1, -2}, {-2, -1}, /*III quarter*/
                                 {-2, 1},  {-1, 2}}; /*IV quarter*/
};

#endif  // MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_H_
