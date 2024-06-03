// Copyright 2024 Novostroev Ivan

#ifndef MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_APP_H_
#define MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_APP_H_

#include <string>
#include "include/bulls_cows.h"

enum ErrorCode {
    EC_HELP,
    EC_INCORRECT_ARGUMENT_NUMBER,
    EC_INCORRECT_DIFFICULTY,
    EC_OK
};

class BullsCowsApplication {
 private:
    const char* appName;
    ErrorCode errorCode;
    BullsCows game;
    std::string getHelpMessage(const char* appname);
    int charToInt(const char* arg);
    std::string generateRandomGuess(int length);
 public:
    BullsCowsApplication();
    std::string doWork(int argc, const char** argv);
};

#endif  // MODULES_BELAN_BULLS_COWS_LAB2_INCLUDE_BULLS_COWS_APP_H_
