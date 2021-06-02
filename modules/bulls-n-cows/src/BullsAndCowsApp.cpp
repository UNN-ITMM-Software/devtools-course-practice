// Copyright 2021 Solovev Aleksandr
#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/BullsAndCowsApp.h"
#include "include/BullsAndCows.h"

std::string BullsAndCowsApp::operator()(int argc, const char* argv[],
                               int* retcode) const {
    if (retcode)
        *retcode = 1;
    if (argc <= 1)
        return help(argv[0]);
    std::string arg = argv[1];
    int count;
    try {
        count = std::stoi(arg);
    } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    arg = argv[2];
    std::vector<int> guess(count);
    for (int i = 0; i < count - 1; i++) {
        guess[i] = static_cast<int>(arg[i]);
    }
    int x;
    std::vector<int> answer(count);
    std::mt19937 gen;
    int min = 0;
    int max = 9;
    gen.seed(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < count; i++) {
        do {
            x = abs(static_cast<int>(gen()) % (max - min + 1) + min);
        } while (std::find(answer.begin(), answer.end(), x) != answer.end());
        answer[i] = x;
    }
    std::string str;
    bullsAndCowsGame game(answer);
    game.setGuess(guess);
    game.guessing();
    std::pair<int, int> result = game.getAnimals();
    str = "Bulls:" + std::to_string(result.first) +
          " Cows:" + std::to_string(result.second);
    std::cout << "Answer:";
    for (int i = 0; i < count; i++) {
        std::cout << answer[i];
    }
    if (retcode)
        *retcode = 0;
    return str;
}

std::string BullsAndCowsApp::help(const std::string& filename) const {
        return "Usage: " + filename +
            " Count of numbers Answer...\n" \
            "Example: " + filename +
            " 3 123";
}
