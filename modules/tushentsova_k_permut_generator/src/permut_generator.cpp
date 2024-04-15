// Copyright 2024 Tushentsova Karina

#include "include/permut_generator.h"
#include <string>
#include <stdexcept>

PermutGenerator::PermutGenerator(int* arr, const int size) {
    if (size <= 0 || arr == NULL) {
        throw std::invalid_argument("invalid value");
    }
    size_ = size;
    array_ = arr;
}

std::string PermutGenerator::PrintArray() {
    std::string result;
    for (int i = 0; i < size_; i++) {
        result += std::to_string(array_[i]);
    }
    return result;
}

void PermutGenerator::CreateArray() {
    for (int i = 0; i < size_; i++) {
        array_[i] = i;
    }
}

void PermutGenerator::Swap(int i, int j) {
    if (i < 0 || j >= size_) {
        throw std::invalid_argument("invalid value");
    }
    int t = array_[i];
    array_[i] = array_[j];
    array_[j] = t;
}

bool PermutGenerator::NextSet() {
    int j = size_ - 2;
    while (j != -1 && array_[j] >= array_[j + 1])
        j--;
    if (j == -1)
        return false;

    int k = size_ - 1;
    while (array_[j] >= array_[k])
        k--;
    Swap(j, k);
    int l = j + 1, r = size_ - 1;
    while (l < r)
        Swap(l++, r--);
    return true;
}

std::string PermutGenerator::GeneratorPermut() {
    BubbleSort();
    std::string result = PrintArray();
    while (NextSet())
        result += ' ' + PrintArray();
    return result;
}

bool PermutGenerator::BubbleSort() {
    int listLength = size_;
    while (listLength--) {
        bool swapped = false;

        for (int i = 0; i < listLength; i++) {
            if (array_[i] > array_[i + 1]) {
                Swap(i, i + 1);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
    return true;
}
