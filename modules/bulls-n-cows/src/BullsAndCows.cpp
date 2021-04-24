// Copyright 2021 Kolesnikov Gleb

#include <utility>
#include <vector>
#include <random>

#include "include/BullsAndCows.h"

void bullsAndCowsGame::setAnswer(const std::vector<int>& ans) {
    answer = ans;
}

void bullsAndCowsGame::setAnimals(std::pair<int, int> bnc) {
    curStats = bnc;
}

void bullsAndCowsGame::setGuess(const std::vector<int>& guess) {
    if (guess.size() != getAnswer().size()) {
        throw "bad size";
    }
    curGuess = guess;
}

std::vector<int> bullsAndCowsGame::getAnswer() const {
    return answer;
}

std::pair<int, int> bullsAndCowsGame::getAnimals() const {
    return curStats;
}

std::vector<int> bullsAndCowsGame::getGuess() const {
    return curGuess;
}

bool bullsAndCowsGame::winCheck() {
    bool res = getAnimals().first == static_cast<int>(getAnswer().size());
    return res;
}

bullsAndCowsGame::bullsAndCowsGame(const std::vector<int>& ans) {
    setAnswer(ans);
    setAnimals(std::pair<int, int> (0, 0));
    setGuess(std::vector<int>(ans.size(), 0));
}

void bullsAndCowsGame::guessing() {
    std::pair<int, int> bnc(0, 0);
    std::vector<int> ans = getAnswer();
    std::vector<int> guess = getGuess();
    for (unsigned int i = 0; i < guess.size(); i++) {
        for (unsigned int j = 0; j < guess.size(); j++) {
            if (guess[i] == ans[j]) {
                if (i == j) {
                    bnc.first++;
                } else {
                    bnc.second++;
                }
            }
        }
    }
    setAnimals(bnc);
}
