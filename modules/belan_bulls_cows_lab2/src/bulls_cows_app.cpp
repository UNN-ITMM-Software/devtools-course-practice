// Copyright 2024 Novostroev Ivan

#include "../include/bulls_cows_app.h"
#include <iostream>
#include <sstream>
#include <string>

BullsCowsApplication::BullsCowsApplication() : appName("Bulls and Cows"), errorCode(EC_OK) {}

std::string BullsCowsApplication::getHelpMessage(const char* appname) {
    std::ostringstream message;
    message << "This is a Bulls and Cows application.\n"
            << "Please provide arguments in the following format:\n\n"
            << "  $ " << appname << " <difficulty level>\n\n"
            << "Where <difficulty level> is an integer value that determines the number of digits in the secret number.\n";
    return message.str();
}

int BullsCowsApplication::charToInt(const char* arg) {
    return std::atoi(arg);
}

std::string BullsCowsApplication::doWork(int argc, const char** argv) {
    if (argc == 1) {
        return getHelpMessage(argv[0]);
    } else if (argc != 2) {
        errorCode = EC_INCORRECT_ARGUMENT_NUMBER;
        return "ERROR: Incorrect number of arguments.\n" + getHelpMessage(argv[0]);
    }

    int difficulty = charToInt(argv[1]);
    if (difficulty <= 0) {
        errorCode = EC_INCORRECT_DIFFICULTY;
        return "ERROR: Difficulty level must be a positive integer.\n" + getHelpMessage(argv[0]);
    }

    game.setDifficulty(difficulty);
    game.setSecretNumber(game.generateSecretNumber());

    std::ostringstream message;
    message << "Welcome to Bulls and Cows game!\n"
            << "I have generated a secret number with " << difficulty << " unique digits.\n"
            << "You have 3 attempts to guess the number.\n";

    while (game.getAttemptsLeft() > 0) {
        std::string guess;
        message << "Enter your guess: ";
        std::cout << message.str();
        std::cin >> guess;

        if (!game.validateGuess(guess)) {
            message << "Invalid guess. Make sure it has " << difficulty << " digits and contains only numbers.\n";
            continue;
        }

        auto result = game.guessNumber(guess);
        if (result.first == difficulty) {
            message << "Congratulations! You've guessed the number correctly.\n";
            break;
        } else {
            message << "Bulls: " << result.first << ", Cows: " << result.second << "\n";
            if (game.getAttemptsLeft() > 0) {
                message << "Attempts left: " << game.getAttemptsLeft() << "\n";
            } else {
                message << "Sorry, you've run out of attempts. The secret number was: " << game.generateSecretNumber() << "\n";
            }
        }
    }

    return message.str();
}
