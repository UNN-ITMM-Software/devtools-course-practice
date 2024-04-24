// Copyright 2024 Kudinov Nikita

#include "include/conways_game_of_life.h"

#include <exception>
#include <iostream>

void ConwaysGameOfLife::_checkCellPositionOrThrow(
  std::size_t y,
  std::size_t x) const {
  if (y >= this->_board_height) {
    throw std::invalid_argument("y position should be less than board height");
  }

  if (x >= this->_board_width) {
    throw std::invalid_argument("x position should be less than board width");
  }
}

std::size_t ConwaysGameOfLife::_calculateBoardIndexFromCellPosition(
  std::size_t y,
  std::size_t x) const {
  return y * this->_board_width + x;
}

ConwaysGameOfLife::ConwaysGameOfLife(
  std::size_t board_height,
  std::size_t board_width):
  _board_height(board_height),
  _board_width(board_width) {
  if (board_height == 0 || board_width == 0) {
    throw std::invalid_argument("board cannot be empty");
  }

  this->_board = std::vector<bool>(board_height * board_width, false);
}

ConwaysGameOfLife::ConwaysGameOfLife(
  const std::vector<std::vector<bool>>& cells) {
  if (cells.empty()) {
    throw std::invalid_argument("board cannot be empty");
  }

  this->_board_height = cells.size();
  this->_board_width = cells.front().size();

  if (this->_board_width == 0) {
    throw std::invalid_argument("board cannot be empty");
  }

  this->_board = std::vector<bool>();

  for (const auto& row : cells) {
    if (row.size() != this->_board_width) {
      throw std::invalid_argument(
        "all rows in cells vector should have the same size");
    }

    for (bool cell_state : row) {
      this->_board.push_back(cell_state);
    }
  }
}

std::size_t ConwaysGameOfLife::getBoardHeight() const {
  return this->_board_height;
}

std::size_t ConwaysGameOfLife::getBoardWidth() const {
  return this->_board_width;
}

const std::vector<bool>& ConwaysGameOfLife::getBoard() const {
  return this->_board;
}

std::vector<std::vector<bool>> ConwaysGameOfLife::getBoard2d() const {
  std::vector<std::vector<bool>> out(
    this->_board_height,
    std::vector<bool>(this->_board_width));

  for (std::size_t y = 0; y < this->_board_height; y += 1) {
    for (std::size_t x = 0; x < this->_board_width; x += 1) {
      const std::size_t i = this->_calculateBoardIndexFromCellPosition(y, x);
      out[y][x] = this->_board[i];
    }
  }

  return out;
}

bool ConwaysGameOfLife::getCellState(std::size_t y, std::size_t x) const {
  this->_checkCellPositionOrThrow(y, x);

  std::size_t i = this->_calculateBoardIndexFromCellPosition(y, x);

  return this->_board[i];
}

void ConwaysGameOfLife::setCellState(std::size_t y, std::size_t x, bool state) {
  this->_checkCellPositionOrThrow(y, x);

  std::size_t i = this->_calculateBoardIndexFromCellPosition(y, x);

  this->_board[i] = state;
}

void ConwaysGameOfLife::simulateNextGeneration() {
  std::vector<bool> next_gen_board = this->_board;

  for (std::size_t y = 0; y < this->_board_height; y += 1) {
    for (std::size_t x = 0; x < this->_board_width; x += 1) {
      std::uint8_t alive_neighbors = 0;

      for (std::ptrdiff_t dy = -1; dy <= 1; dy += 1) {
        for (std::ptrdiff_t dx = -1; dx <= 1; dx += 1) {
          if (dy == 0 && dx == 0) { continue; }
          const std::ptrdiff_t y_pos = y + dy;
          const std::ptrdiff_t x_pos = x + dx;
          if (y_pos < 0 || std::size_t(y_pos) >= this->_board_height) {
            continue;
          }
          if (x_pos < 0 || std::size_t(x_pos) >= this->_board_width) {
            continue;
          }

          const std::size_t i = this->_calculateBoardIndexFromCellPosition(
            y_pos,
            x_pos);

          alive_neighbors += std::uint8_t(this->_board[i]);
        }
      }

      const std::size_t i = this->_calculateBoardIndexFromCellPosition(y, x);
      if (this->_board[i] && (alive_neighbors < 2 || alive_neighbors > 3)) {
        next_gen_board[i] = false;
      } else if (alive_neighbors == 3) {
        next_gen_board[i] = true;
      }
    }
  }

  this->_board = next_gen_board;
}

void ConwaysGameOfLife::resetBoard() {
  std::fill(this->_board.begin(), this->_board.end(), false);
}

std::string ConwaysGameOfLife::toString(
  char cell_alive_char,
  char cell_dead_char) {
  std::string out;

  for (std::size_t y = 0; y < this->_board_height; y += 1) {
    for (std::size_t x = 0; x < this->_board_width; x += 1) {
      std::size_t i = this->_calculateBoardIndexFromCellPosition(y, x);
      out.push_back(this->_board[i] ? cell_alive_char : cell_dead_char);
    }
    if (y != this->_board_height - 1) {
      out.push_back('\n');
    }
  }

  return out;
}
