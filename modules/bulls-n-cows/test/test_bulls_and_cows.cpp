// Copyright 2021 Kolesnikov Gleb
#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "include/BullsAndCows.h"

TEST(BullsAndCows, Guessing_1) {
    std::vector<int> answer = { 1, 2, 3, 5 };
    std::vector<int> guess = { 1, 2, 3, 4 };
    std::pair<int, int> check(3, 0);
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(check, game.getAnimals());
}

TEST(BullsAndCows, Guessing_2) {
    std::vector<int> answer = { 1, 2, 3, 5 };
    std::vector<int> guess = { 1, 2, 3, 5 };
    std::pair<int, int> check(4, 0);
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(check, game.getAnimals());
}

TEST(BullsAndCows, Guessing_3) {
    std::vector<int> answer = { 1, 2, 3, 5 };
    std::vector<int> guess = { 6, 7, 8, 9 };
    std::pair<int, int> check(0, 0);
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(check, game.getAnimals());
}

TEST(BullsAndCows, Guessing_4) {
    std::vector<int> answer = { 1, 2, 3, 5 };
    std::vector<int> guess = { 6, 1, 8, 9 };
    std::pair<int, int> check(0, 1);
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(check, game.getAnimals());
}

TEST(BullsAndCows, Can_Create_Game) {
    std::vector<int> answer = { 1, 2, 3, 5 };

    ASSERT_NO_THROW(bullsAndCowsGame game(answer));
}

TEST(BullsAndCows, Different_sizes_throw) {
    std::vector<int> answer = { 1, 2, 3, 5, 0 };
    std::vector<int> guess = { 6, 7, 8, 9 };

    bullsAndCowsGame game(answer);

    ASSERT_ANY_THROW(game.setGuess(guess));
}

TEST(BullsAndCows, Can_Win) {
    std::vector<int> answer = { 1, 2, 3, 5, 0 };
    std::vector<int> guess = { 1, 2, 3, 5, 0 };
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(game.winCheck(), 1);
}

TEST(BullsAndCows, Can_Not_Win) {
    std::vector<int> answer = { 1, 2, 3, 5, 0 };
    std::vector<int> guess = { 1, 2, 3, 5, 0 };
    bullsAndCowsGame game(answer);
    game.setGuess(guess);

    game.guessing();

    ASSERT_EQ(game.winCheck(), 1);
}
