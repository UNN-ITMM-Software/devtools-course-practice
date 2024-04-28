// Copyright 2024 Belan Vadim

#ifndef MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_H_
#define MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_H_

#include <string>
#include <ctime>
#include <utility>
#include <cstdlib>

class BullsCows {
 private:
    int difficultyLevel;
    std::string secretNumber;
    int attemptsLeft;
 public:
    BullsCows();
    void setDifficulty(int level);
    std::string generateSecretNumber();
    void setSecretNumber(const std::string& secret);
    std::pair<int, int> guessNumber(const std::string& guess);
    bool validateGuess(const std::string& guess);
    int getDifficultyLevel() const;
    char getHint();
    int getAttemptsLeft() const;
};

#endif  // MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_H_
