// Copyright 2024 Kiselev Igor

#include "include/game_of_life_app.h"

#include <exception>

ConwaysGameOfLifeApplication::ConwaysGameOfLifeApplication(int argc,
    const char** argv) : game(1, 1) {
    dataErrorNumber = EC_OK;
    appName = argv[0];
    numberOfGenerations = 0;
    if (argc == 1) {
        dataErrorNumber = EC_HELP;
        return;
    }
    if (argc < 4 || argc % 2 == 1) {
        dataErrorNumber = EC_INCORRECT_ARGUMENT_NUMBER;
        return;
    }
    try {
        const char* numberString = argv[3];
        numberOfGenerations = charToInt(numberString);
        if (numberOfGenerations < 0) dataErrorNumber =
            EC_INCORRECT_GENERATIONS_NUMBER;
    }
    catch (...) {
        dataErrorNumber = EC_INCORRECT_GENERATIONS_NUMBER;
    }
    setNewField(argc, argv);
}

std::string ConwaysGameOfLifeApplication::doWork() {
    switch (dataErrorNumber) {
    case EC_HELP:
        return "This is application for Conway's game of life.\n" +
            std::string("Pleace, enter height and width of field, number of ") +
            "generations and living points";
        break;
    case EC_INCORRECT_ARGUMENT_NUMBER:
        return "Error: Incorrect count of arguments!";
        break;
    case EC_INCORRECT_GENERATIONS_NUMBER:
        return "Error: Incorrect number of generations!";
        break;
    case EC_INCORRECT_FIELD_SIZE:
        return "Error: Incorrect height or width!";
        break;
    case EC_INCORRECT_POINT:
        return "Error: Some of points are incorret!";
        break;
    case EC_OK:
        for (int i = 0; i < numberOfGenerations; i++) {
            game.simulateNextGeneration();
        }
        return appName + ' ' + game.toString();
        break;
    }
    return "You should not get this message";
}

bool ConwaysGameOfLifeApplication::setNewField(int argc, const char** argv) {
    int height = 0;
    int width = 0;
    dataErrorNumber = EC_HELP;
    try {
        const char* numberHeight = argv[1];
        const char* numberWidth = argv[2];
        height = charToInt(numberHeight);
        width = charToInt(numberWidth);
        if (numberOfGenerations < 0) dataErrorNumber =
            EC_INCORRECT_GENERATIONS_NUMBER;
    }
    catch (...) {
        dataErrorNumber = EC_INCORRECT_ARGUMENT_NUMBER;
        return false;
    }
    ConwaysGameOfLife newGame = ConwaysGameOfLife(1, 1);
    if (dataErrorNumber == 0) {
        try {
            if (height < 0 || width < 0) {
                dataErrorNumber = EC_INCORRECT_FIELD_SIZE;
                return false;
            }
            newGame = ConwaysGameOfLife(height, width);
        }
        catch (...) {
            dataErrorNumber = EC_INCORRECT_FIELD_SIZE;
            return false;
        }
        if (dataErrorNumber == 0) {
            try {
                for (int i = 4; i < argc - 1; i += 2) {
                    int x = charToInt(argv[i]);
                    int y = charToInt(argv[i + 1]);
                    game.setCellState(x, y, true);
                }
            }
            catch (...) {
                dataErrorNumber = EC_INCORRECT_POINT;
                return false;
            }
        }
    }
    game = ConwaysGameOfLife(newGame);
    return true;
}

int ConwaysGameOfLifeApplication::charToInt(const char* arg) {
    int ans = 0;
    const char* ptr = arg;
    bool isNegative = false;
    if (*ptr == '-') {
        ptr++;
        isNegative = true;
    }
    while (*ptr != '\0') {
        ans = ans * 10 + (*ptr - '0');
        ++ptr;
    }
    if (isNegative) ans *= -1;
    return ans;
}
