// Copyright 2024 Makhinya Danil
#ifndef MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_APP_H_
#define MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_APP_H_

#include "include/chess_board.h"

#include<string>
#include<set>

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

// #define PRINT_DEBUG_INFO

class ChessBoardApp {
  std::set<ChessBoard::Point> obstacles;
  ChessBoard board;
  size_t size;
  ChessBoard::Point start;
  ChessBoard::Point end;
  bool have_size, have_start, have_end;
  int knightDistance();

  std::string getHelpMessage();
  std::string getVersion();
  std::string getErrInvalidArgv(const char *command);
  int16_t parseObstacles(int argc,  const char *argv[]);
  int16_t parseStart(int argc,  const char *argv[]);
  int16_t parseEnd(int argc,  const char *argv[]);
  int16_t parseSize(int argc,  const char *argv[]);
  std::string parseArg(int argc,  const char *argv[]);


 public:
  ChessBoardApp() : size(8), have_size(0), have_start(0), have_end(0) {}
  void initBoard();
  std::string run(int argc, const char *argv[]);
};

#endif  // MODULES_PODYACHIKH_KNIGHT_MOVES_LAB2_INCLUDE_CHESS_BOARD_APP_H_

