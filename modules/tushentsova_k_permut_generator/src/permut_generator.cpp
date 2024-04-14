// Copyright 2024 Tushentsova Karina

#include "include/permut_generator.h"
#include <string>

PermutGenerator::PermutGenerator(int* arr, const int size) {
    if (size <= 0 || arr == NULL) {
        throw std::string("invalid value");
    }
    size_ = size;
    array_ = arr;
}
