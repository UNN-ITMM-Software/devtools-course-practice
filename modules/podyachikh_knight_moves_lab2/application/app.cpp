// Makhinya Danil 2024

#include <iostream>
#include <string.h>

#include "include/chess_board_app.h"

int main(int argc, const char *argv[]) {
  ChessBoardApp app;
  auto message = app.run(argc, argv);
  std::cout << message << std::endl;
  return 0;
}