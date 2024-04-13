// Copyright 2024 Belan Vadim

#include <gtest/gtest.h>
#include "/Users/vadimbelan/Desktop/belan_bulls_cows_lab2/include/bulls_cows.h"

TEST(BullsCowsTest, GenerateSecretNumber) {
    BullsCows game;

    std::string secretNumber = game.generateSecretNumber();

    ASSERT_EQ(secretNumber.length(), 4);
    ASSERT_TRUE(std::all_of(secretNumber.begin(),
    secretNumber.end(), ::isdigit));
}

TEST(BullsCowsTest, GuessNumber) {
    BullsCows game;
    std::string secretNumber = "1234";
    game.setSecretNumber(secretNumber);

    std::string guess = "1243";
    std::pair<int, int> result = game.guessNumber(guess);

    ASSERT_EQ(result.first, 2);
    ASSERT_EQ(result.second, 2);
}

TEST(BullsCowsTest, ValidateGuess) {
    BullsCows game;
    std::string secretNumber = "1234";
    game.setSecretNumber(secretNumber);

    ASSERT_TRUE(game.validateGuess("1234"));
    ASSERT_FALSE(game.validateGuess("12345"));
    ASSERT_FALSE(game.validateGuess("12A4"));
}

TEST(BullsCowsTest, DifficultyTest) {
    BullsCows game;

    game.setDifficulty(3);
    EXPECT_EQ(game.getDifficultyLevel(), 3);

    game.setDifficulty(3);
    std::string secretEasy = game.generateSecretNumber();
    EXPECT_EQ(secretEasy.length(), 3);

    game.setDifficulty(4);
    std::string secretMedium = game.generateSecretNumber();
    EXPECT_EQ(secretMedium.length(), 4);

    game.setDifficulty(5);
    std::string secretHard = game.generateSecretNumber();
    EXPECT_EQ(secretHard.length(), 5);
}

TEST(BullsCowsTest, HintTest) {
    BullsCows game;

    std::string secretNumber = "1234";
    game.setSecretNumber(secretNumber);

    char hint = game.getHint();
    ASSERT_TRUE(secretNumber.find(hint) != std::string::npos);
}

TEST(BullsCowsTest, AttemptsLimitTest) {
    BullsCows game;

    std::string secretNumber = "1234";
    game.setSecretNumber(secretNumber);

    for (int i = 0; i < 3; ++i) {
        std::string guess = "5678";
        game.guessNumber(guess);
        ASSERT_EQ(game.getAttemptsLeft(), 2 - i);
    }

    ASSERT_EQ(game.getAttemptsLeft(), 0);
}
