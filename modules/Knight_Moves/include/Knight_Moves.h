// Copyright 2021 Galindo Buitrago Julio Cesar

#ifndef MODULES_KNIGHT_MOVES_INCLUDE_KNIGHT_MOVES_H_
#define MODULES_KNIGHT_MOVES_INCLUDE_KNIGHT_MOVES_H_

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> myKeyType;
typedef std::map<myKeyType, int> myMapType;

class KM {
 public:
    myMapType alfa;
    int operation(int x, int y);
    int knightMinimumValue(int x, int y);
};

#endif  // MODULES_KNIGHT_MOVES_INCLUDE_KNIGHT_MOVES_H_
