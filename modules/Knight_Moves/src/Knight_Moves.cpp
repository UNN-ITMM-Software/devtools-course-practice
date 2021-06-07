// Copyright 2021 Galindo Buitrago Julio Cesar

#include <iostream>
#include <utility>
#include <algorithm>

#include "include/Knight_Moves.h"

int KM::operation(int x, int y) {
    while (true) {
        if (x + y == 0) {return 0;}
        if (x + y == 2) {return 2;}
        std::pair<int, int> saved({x, y});
        if (alfa.count(saved)) return alfa[saved];
        alfa[saved] = std::min(operation(abs(x - 1),
            abs(y - 2)), operation(abs(x - 2), abs(y - 1))) + 1;
        continue;
    }
}

int KM::knightMinimumValue(int x, int y) {
    return operation(abs(x), abs(y));
}
