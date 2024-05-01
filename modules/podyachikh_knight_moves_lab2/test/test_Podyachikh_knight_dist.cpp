// Copyright 2024 Podyachikh Mikhail

#include <gtest/gtest.h>

#include "include/chess_board.h"

TEST(testMinKnightMoves, obstacleExceptions) {
  ChessBoard board = ChessBoard(12);
  EXPECT_ANY_THROW(board.addObstacle({-1, 2}));
  EXPECT_ANY_THROW(board.addObstacle({5, 12}));
  EXPECT_NO_THROW(board.addObstacle({0, 11}));
}

TEST(testMinKnightMoves, knightExceptions) {
  ChessBoard board = ChessBoard(12);
  std::pair<int, int> available{2, 5};
  std::pair<int, int> notAvailable{-1, 4};
  std::pair<int, int> obstacle1{1, 2};
  std::pair<int, int> obstacle2{7, 10};
  board.addObstacle(obstacle1);
  board.addObstacle(obstacle2);
  ASSERT_ANY_THROW(board.knightDistance(available, notAvailable));
  ASSERT_ANY_THROW(board.knightDistance(notAvailable, available));
  ASSERT_ANY_THROW(board.knightDistance(available, obstacle1));
  ASSERT_ANY_THROW(board.knightDistance(obstacle2, available));
  ASSERT_ANY_THROW(board.knightDistance(obstacle1, obstacle2));
}

TEST(testMinKnightMoves, emptyBoardOneMove) {
  ChessBoard emptyBoard = ChessBoard();
  std::pair<int, int> start{0, 0};
  std::pair<int, int> end{1, 2};
  int dist = emptyBoard.knightDistance(start, end);
  EXPECT_EQ(dist, 1);
}

TEST(testMinKnightMoves, emptyBoardCorners) {
  ChessBoard emptyBoard = ChessBoard();
  std::pair<int, int> start{0, 0};
  std::pair<int, int> end{7, 7};
  int dist = emptyBoard.knightDistance(start, end);
  EXPECT_EQ(dist, 6);
}

TEST(testMinKnightMoves, zeroDistance) {
  ChessBoard board = ChessBoard();
  std::pair<int, int> start{0, 0};
  std::pair<int, int> end{0, 0};
  int dist = board.knightDistance(start, end);
  EXPECT_EQ(dist, 0);
}

TEST(testMinKnightMoves, unreachable) {
  ChessBoard board = ChessBoard();
  board.addObstacle({1, 2});
  board.addObstacle({2, 1});

  std::pair<int, int> start = {7, 7};
  std::pair<int, int> end = {0, 0};
  int dist = board.knightDistance(start, end);
  EXPECT_EQ(dist, -1);
}

TEST(testMinKnightMoves, smallBoard) {
  ChessBoard board = ChessBoard(3);

  std::pair<int, int> start{0, 0};
  std::pair<int, int> end{1, 1};
  int dist = board.knightDistance(start, end);
  EXPECT_EQ(dist, -1);

  start = {0, 0};
  end = {2, 2};
  dist = board.knightDistance(start, end);
  EXPECT_EQ(dist, 4);
}
