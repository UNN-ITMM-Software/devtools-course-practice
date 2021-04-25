// Copyright 2021 Vodeneev Mikhail

#ifndef MODULES_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_
#define MODULES_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_

#include<stdio.h>
#include<stack>

class Hanoi {
    int size;
    std::stack<int> towerA;
    std::stack<int> towerB;
    std::stack<int> towerC;

 public:
    Hanoi();
    explicit Hanoi(int size);
    int Size();
    std::stack<int> GetTowerA();
    std::stack<int> GetTowerB();
    std::stack<int> GetTowerC();
    void ring(int n, std::stack<int> *A, std::stack<int> *B,
        std::stack<int> *C);
};

#endif  // MODULES_HANOI_TOWER_INCLUDE_HANOI_TOWER_H_
