// Copyright 2021 Vodeneev Mikhail

#include<stack>
#include "include/hanoi_tower.h"

Hanoi::Hanoi() {
    size = 0;
    towerA = {};
    towerB = {};
    towerC = {};
}

Hanoi::Hanoi(int size) {
    if (size < 0)
        throw 0;
    this->size = size;
    for (int i = 0; i < size; i++)
        towerA.push(i);
    towerB = {};
    towerC = {};
}

int Hanoi::Size() {
    return size;
}

std::stack<int> Hanoi::GetTowerA() {
    return towerA;
}

std::stack<int> Hanoi::GetTowerB() {
    return towerB;
}

std::stack<int> Hanoi::GetTowerC() {
    return towerC;
}

void Hanoi::ring(int n, std::stack<int> *A, std::stack<int> *B,
    std::stack<int> *C) {
    if (n <= 0)
        return;
    ring(n - 1, A, C, B);
    B->push(A->top());
    A->pop();
    ring(n - 1, C, B, A);
}




