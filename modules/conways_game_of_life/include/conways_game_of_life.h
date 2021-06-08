// Copyright 2021 Ikromov Inom
#pragma once
#ifndef MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
#define MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_

#include <vector>
#include <string>

class Conways_life {
 private:
    int sizeh_, sizew_;
    std::vector<std::string> field_;
    std::vector<bool> check_;

    void checkNextStep();
    void redraw();
    std::string print(std::string str);

 public:
    Conways_life(const int w, const int h);
    int getW();
    int getH();
    std::string getPoint(const int wi, const int hi);
    void putStart(const int wi, const int hi);

    int countNeighbors(const int wi, const int hi);
    void stepNextField();
    bool isSystemAlive();
    bool aliveNextStep(const int wi, const int hi);

    std::string Start(std::string res, int eps);
};

#endif  // MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_