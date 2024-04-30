// Copyright 2024 Makhinya Danil

#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>

#include "include/chess_board_app.h"

int ChessBoardApp::knightDistance() {
  #ifdef PRINT_DEBUG_INFO
  std::fprintf(stderr, "%s size{%lu}, start{%u, %u}; end{%u, %u}\n", 
               __func__, size,
               start.first, start.second,
               end.first, end.second);
  #endif
  return board.knightDistance(start, end);
}

std::string ChessBoardApp::getHelpMessage() {
  return "usage: name_file [--version] [--help]\n"
         "                 [-s <size>]\n"
         "                 [-S <start.X start.Y>] [-E <end.X end.Y>]\n"
         "                 [-A <count ob1.X ob1.Y ob2.X ob2.Y ...>]";
}

std::string ChessBoardApp::getErrInvalidArgv(const char *command) {
  std::string err_message;
  err_message += "Invalide command: ";
  err_message += command;
  err_message += "\n";

  // err_message += getHelpMessage();
  return err_message;
}

std::string ChessBoardApp::getVersion() {
  return std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR);
}

std::string ChessBoardApp::parseArg(int argc,  const char *argv[]) {
  const char *command = argv[1];

  if (argc == 2 && strcmp(command, "--help") == 0) {
    return getHelpMessage();
  }

  if (argc == 2 && strcmp(command, "--version") == 0) {
    return getVersion();
  }

  for (uint16_t i = 1; i + 1 < argc; i++) {
    command = argv[i];
    const char** next_command_ptr = argv + i + 1;
    int16_t offset = -1;

    #ifdef PRINT_DEBUG_INFO
    std::fprintf(stderr, "%s command{\"%s\"}; next_command{\"%s\"}\n", 
                 __func__, 
                 command, 
                 *next_command_ptr);
    #endif

    if (strcmp(command, "-A") == 0) {
      offset = parseObstacles(argc - 1 - i, next_command_ptr);
    } else if (!have_start && strcmp(command, "-S") == 0) {
      offset = parseStart(argc - 1 - i, next_command_ptr);
      have_start |= (offset > 0);
    } else if (!have_end && strcmp(command, "-E") == 0) {
      offset = parseEnd(argc - 1 - i, next_command_ptr);
      have_end |= (offset > 0);
    } else if (!have_size && strcmp(command, "-s") == 0) {
      offset = parseSize(argc - 1 - i, next_command_ptr);
      have_size |= (offset > 0);
    }

    if (offset <= 0) {
      return getErrInvalidArgv(command);
    }

    i += offset;
  }

  if (!have_start || !have_end) {
    return getErrInvalidArgv(command);
  }

  return "";
}

static int16_t parsePoint(int argc, const char *begin[], ChessBoard::Point& p) {
  if (argc < 2) {
    return -1;
  }

  int ptr = 0;

  #ifdef PRINT_DEBUG_INFO
  std::fprintf(stderr, "%s argc{%d}; begin[0]{\"%s\"}; begin[1]{\"%s\"}\n", 
               __func__, 
               argc, 
               begin[0], begin[1]);
  #endif

  char* end_x, * end_y;
  uint32_t X = std::strtol(begin[ptr++], &end_x, 10);
  uint32_t Y = std::strtol(begin[ptr++], &end_y, 10);
  if (end_x[0] || end_y[0]) {
    return -1;
  }

  #ifdef PRINT_DEBUG_INFO
  std::fprintf(stderr, "%s X{%u}; Y{%u}\n", __func__, X, Y);
  #endif

  p = {X, Y};
  return 2;
}

int16_t ChessBoardApp::parseObstacles(int argc, const char *begin[]) {
  ChessBoard::Point p;
  uint16_t offset = 0;
  uint32_t i = 0;

  char* end;
  uint32_t count = std::strtol(begin[offset++], &end, 10);
  if (end[0] || count % 2 != 0) {
    return -1;
  }
  while (offset + 2 <= argc && i < count) {
    auto o = parsePoint(argc - offset, begin + offset, p);
    if (o <= 0) {
      return -1;
    }

    offset += o;
    obstacles.insert(p);
    ++i;
  }

  if (i != count) {
    return -1;
  }

  return offset;
}

int16_t ChessBoardApp::parseStart(int argc, const char *begin[]) {
  return parsePoint(argc, begin, start);
}

int16_t ChessBoardApp::parseEnd(int argc, const char *begin[]) {
  return parsePoint(argc, begin, end);
}

int16_t ChessBoardApp::parseSize(int argc, const char *begin[]) {
  char* end;
  uint32_t S = std::strtol(begin[0], &end, 10);
  if (end[0]) {
    return -1;
  }
  size = S;
  return 1;
}

void ChessBoardApp::initBoard() {
  board = ChessBoard(size, obstacles);
}

std::string ChessBoardApp::run(int argc, const char *argv[]) {
  std::string message;

  message = parseArg(argc, argv);

  if (!message.empty()) {
    return message;
  }

  initBoard();

  int ans = 0;
  try {
    ans = knightDistance();
  }
  catch(std::exception &str) {
    return str.what();
  }
  message = "The minimum number of moves "
            "required for the knight to reach from start to end = ";
  message += std::to_string(ans);
  return message;
}
