// Copyright 2024 Kiselev Igor

#ifndef MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
#define MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_

#include <string>
#include "include/conways_game_of_life.h"

enum ErrorCode {
    EC_HELP,
    EC_INCORRECT_ARGUMENT_NUMBER,
    EC_INCORRECT_GENERATIONS_NUMBER,
    EC_INCORRECT_FIELD_SIZE,
    EC_INCORRECT_POINT,
    EC_OK
};

class ConwaysGameOfLifeApplication {
 private:
    int numberOfGenerations;
    ErrorCode dataErrorNumber;
    const char* appName;
    ConwaysGameOfLife game;
    int charToInt(const char* arg);
 public:
    ConwaysGameOfLifeApplication(int argc, const char** argv);
    std::string doWork();
    bool setNewField(int argc, const char** argv);
};

#endif  // MODULES_KUDINOV_N_CONWAYS_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
