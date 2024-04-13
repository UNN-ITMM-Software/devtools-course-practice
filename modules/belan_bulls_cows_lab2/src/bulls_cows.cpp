// Copyright 2024 Belan Vadim

#include "include/bulls_cows.h"
#include <cstdlib>
#include <ctime>

BullsCows::BullsCows() : attemptsLeft(3) {
    difficultyLevel = 4;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void BullsCows::setDifficulty(int level) {
    difficultyLevel = level;
}

std::string BullsCows::generateSecretNumber() {
    std::string secret;
    for (int i = 0; i < difficultyLevel; ++i) {
        char digit = '0' + std::rand() % 10;
        while (secret.find(digit) != std::string::npos) {
            digit = '0' + std::rand() % 10;
        }
        secret += digit;
    }
    return secret;
}

void BullsCows::setSecretNumber(const std::string& secret) {
    secretNumber = secret;
}

std::pair<int, int> BullsCows::guessNumber(const std::string& guess) {
    --attemptsLeft;

    int bulls = 0;
    int cows = 0;

    for (size_t i = 0; i < guess.length(); ++i) {
        if (guess[i] == secretNumber[i]) {
            ++bulls;
        } else if (secretNumber.find(guess[i]) != std::string::npos) {
            ++cows;
        }
    }

    return std::make_pair(bulls, cows);
}

bool BullsCows::validateGuess(const std::string& guess) {
    if (guess.length() != secretNumber.length()) {
        return false;
    }

    for (char c : guess) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int BullsCows::getDifficultyLevel() const {
    return difficultyLevel;
}

char BullsCows::getHint() {
    return secretNumber[std::rand() % secretNumber.length()];
}

int BullsCows::getAttemptsLeft() const {
    return attemptsLeft;
}
