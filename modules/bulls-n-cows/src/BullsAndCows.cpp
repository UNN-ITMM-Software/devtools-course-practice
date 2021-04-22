// Copyright 2021 Kolesnikov Gleb

#include <utility>
#include <vector>
#include <random>
#include "include/BullsAndCows.h"

std::vector<int> generateNonRepeatingDigits(int len) {
    if (len >= 10 || len < 0) {
        throw "bad size";
    }
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, 10);
    std::vector<int> seq;
    for (int i = 0; i < 10; i++)
        seq.push_back(i);

    std::vector<int> ret;
    for (int i = 0; i < len; i++) {
        int pos = uid(gen) % seq.size();
        ret.push_back(seq[pos]);
        seq.erase(seq.begin() + pos);
    }
    return ret;
}
void bullsAndCowsGame::setAnswer(std::vector<int> ans) {
    answer = ans;
}
void bullsAndCowsGame::setAnimals(std::pair<int, int> bnc) {
    curStats = bnc;
}
void bullsAndCowsGame::setGuess(std::vector<int> guess) {
    if (guess.size() != getAnswer().size()) {
        throw "bad size";
    }
    curGuess = guess;
}
std::vector<int> bullsAndCowsGame::getAnswer() {
    return answer;
}
std::pair<int, int> bullsAndCowsGame::getAnimals() {
    return curStats;
}
std::vector<int> bullsAndCowsGame::getGuess() {
    return curGuess;
}
bool bullsAndCowsGame::winCheck() {
    if (getAnimals().first == static_cast<int>(getAnswer().size())) {
        return 1;
    }
    return 0;
}
bullsAndCowsGame::bullsAndCowsGame(std::vector<int> ans) {
    setAnswer(ans);
    setAnimals(std::pair<int, int> (0, 0));
    setGuess(std::vector<int>(ans.size(), 0));
}
void bullsAndCowsGame::guessing() {
    std::pair<int, int> bnc(0, 0);
    std::vector<int> ans = getAnswer();
    std::vector<int> guess = getGuess();
    for (unsigned  int i = 0; i < guess.size(); i++) {
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

