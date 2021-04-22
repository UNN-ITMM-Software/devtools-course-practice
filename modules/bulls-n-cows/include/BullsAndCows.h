// Copyright 2021 Kolesnikov Gleb

#ifndef MODULES_BULLS_N_COWS_INCLUDE_BULLSANDCOWS_H_
#define MODULES_BULLS_N_COWS_INCLUDE_BULLSANDCOWS_H_

#include <ctime>
#include <vector>
#include <utility>

class  bullsAndCowsGame {
    std::pair<int, int> curStats;
    std::vector<int> answer;
    std::vector<int> curGuess;
 public:
     explicit bullsAndCowsGame(std::vector<int> ans);
    void guessing();
    void setAnswer(std::vector<int> ans);
    void setAnimals(std::pair<int, int> bnc);
    void setGuess(std::vector<int> guess);
    std::vector<int> getAnswer();
    std::pair<int, int> getAnimals();
    std::vector<int> getGuess();
    bool winCheck();
};
#endif  // MODULES_BULLS_N_COWS_INCLUDE_BULLSANDCOWS_H_
