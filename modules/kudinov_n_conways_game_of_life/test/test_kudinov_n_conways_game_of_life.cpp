// Copyright 2024 Kudinov Nikita

#include <gtest/gtest.h>

#include "include/conways_game_of_life.h"

#define ASSERT_EQ_2D_VECTORS(vector1, vector2)                                \
    do {                                                                      \
        ASSERT_EQ(vector1.size(), vector2.size());                            \
        if (!vector1.empty()) {                                               \
            ASSERT_EQ(vector1.front().size(), vector2.front().size());        \
                                                                              \
            for (std::size_t y = 0; y < vector1.size(); y += 1) {             \
                for (std::size_t x = 0; x < vector1.front().size(); x += 1) { \
                    ASSERT_EQ(vector1[y][x], vector2[y][x]);                  \
                }                                                             \
            }                                                                 \
        }                                                                     \
    } while (0)

TEST(
  Kudinov_Nikita_Conways_Game_Of_Life,
  CanConstructFromNonZeroHeightAndWidth) {
  ASSERT_NO_THROW((ConwaysGameOfLife{5, 10}));
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotConstructFromZeroHeight) {
  ASSERT_THROW((ConwaysGameOfLife{0, 10}), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotConstructFromZeroWidth) {
  ASSERT_THROW((ConwaysGameOfLife{5, 0}), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanConstructFromCells) {
  std::vector<std::vector<bool>> cells = {
    { true, false, true },
    { false, false, true }};

  ASSERT_NO_THROW(ConwaysGameOfLife{cells});
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotConstructFromCellsWhenEmpty) {
  std::vector<std::vector<bool>> cells = {};

  ASSERT_THROW(ConwaysGameOfLife{cells}, std::invalid_argument);
}

TEST(
  Kudinov_Nikita_Conways_Game_Of_Life,
  CannotConstructFromCellsWhenRowEmpty) {
  std::vector<std::vector<bool>> cells = {{}};

  ASSERT_THROW(ConwaysGameOfLife{cells}, std::invalid_argument);
}

TEST(
  Kudinov_Nikita_Conways_Game_Of_Life,
  CannotConstructFromCellsWhenCellRowsArentEqual) {
  std::vector<std::vector<bool>> cells = {{ true, false, true }, { false }};

  ASSERT_THROW(ConwaysGameOfLife{cells}, std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanGetBoardHeight) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_NO_THROW(cgol.getBoardHeight());

  ASSERT_EQ(cgol.getBoardHeight(), height);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanGetBoardWidth) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_NO_THROW(cgol.getBoardWidth());

  ASSERT_EQ(cgol.getBoardWidth(), width);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanGetBoard) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_NO_THROW(cgol.getBoard());

  ASSERT_EQ(cgol.getBoard().size(), height * width);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanGetCellStateInBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_NO_THROW(cgol.getCellState(1, 1));
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotGetCellStateWhenYOutOfBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_THROW(cgol.getCellState(height + 3, 0), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotGetCellStateWhenXOutOfBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_THROW(cgol.getCellState(0, width + 2), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, ConstructorShouldCreateDeadBoard) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  const auto cgol = ConwaysGameOfLife(height, width);

  for (bool cell_state : cgol.getBoard()) {
    ASSERT_FALSE(cell_state);
  }
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanSetCellStateInBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  auto cgol = ConwaysGameOfLife(height, width);

  const auto y = 1;
  const auto x = 1;

  ASSERT_FALSE(cgol.getCellState(y, x));
  ASSERT_NO_THROW(cgol.setCellState(y, x, true));
  ASSERT_TRUE(cgol.getCellState(y, x));
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotSetCellStateWhenYOutOfBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_THROW(cgol.setCellState(height + 2, 0, true), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CannotSetCellStateWhenXOutOfBounds) {
  const std::size_t height = 5;
  const std::size_t width = 10;
  auto cgol = ConwaysGameOfLife(height, width);

  ASSERT_THROW(cgol.setCellState(0, width + 4, true), std::invalid_argument);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanSimulateNextGeneration) {
  std::vector<std::vector<bool>> cells = {
    { true, false, true },
    { false, false, true },
    { true, false, true },
  };
  std::vector<std::vector<bool>> next_gen_expected = {
    { false, true, false },
    { false, false, true },
    { false, true, false },
  };
  auto cgol = ConwaysGameOfLife(cells);

  ASSERT_NO_THROW(cgol.simulateNextGeneration());

  ASSERT_EQ_2D_VECTORS(cgol.getBoard2d(), next_gen_expected);
}

TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanResetBoard) {
  std::vector<std::vector<bool>> cells = {
    { true, false, true },
    { false, false, true },
    { true, false, true },
  };
  auto cgol = ConwaysGameOfLife(cells);

  ASSERT_NO_THROW(cgol.resetBoard());

  for (bool cell_state : cgol.getBoard()) {
    ASSERT_FALSE(cell_state);
  }
}


TEST(Kudinov_Nikita_Conways_Game_Of_Life, CanConvertBoardToString) {
  std::vector<std::vector<bool>> cells = {
    { true, false, true },
    { false, false, true },
    { true, false, true },
  };
  std::string expected_cgol_board_as_string = "*.*\n..*\n*.*";
  auto cgol = ConwaysGameOfLife(cells);

  std::string cgol_board_as_string;
  ASSERT_NO_THROW(cgol_board_as_string = cgol.toString());

  ASSERT_EQ(cgol_board_as_string, expected_cgol_board_as_string);
}
