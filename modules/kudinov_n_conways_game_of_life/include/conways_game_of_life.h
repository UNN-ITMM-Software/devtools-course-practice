// Copyright 2024 Kudinov Nikita

#ifndef MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
#define MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_

#include <vector>
#include <string>

class ConwaysGameOfLife {
 private:
    std::vector<bool> _board;
    std::size_t _board_height;
    std::size_t _board_width;

    void _checkCellPositionOrThrow(std::size_t y, std::size_t x) const;
    std::size_t _calculateBoardIndexFromCellPosition(
      std::size_t y,
      std::size_t x) const;

 public:
    ConwaysGameOfLife(std::size_t board_height, std::size_t board_width);
    explicit ConwaysGameOfLife(const std::vector<std::vector<bool>>& cells);

    std::size_t getBoardHeight() const;
    std::size_t getBoardWidth() const;
    const std::vector<bool>& getBoard() const;
    std::vector<std::vector<bool>> getBoard2d() const;

    bool getCellState(std::size_t y, std::size_t x) const;
    void setCellState(std::size_t y, std::size_t x, bool state);

    void simulateNextGeneration();
    void resetBoard();
    std::string toString(char cell_alive_char = '*', char cell_dead_char = '.');
};

#endif  // MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
