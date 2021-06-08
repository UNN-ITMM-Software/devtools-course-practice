// Copyright 2021 Ikromov Inom

#ifndef MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_APPLICATION_H_
#define MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_APPLICATION_H_

#include <vector>
#include <string>

class Conwayslife_App {
 public:
    Conwayslife_App();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int sizew_;
        int sizeh_;
        int numOfStartPoint_;
        int epsSteps_;
        std::vector<int> points_;
    } Arguments;
};

#endif  // MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_APPLICATION_H_