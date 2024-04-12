// Copyright 2024 Tushentsova Karina

#include "include/permut_generator.h"
#include <string>

PermutGenerator::PermutGenerator() {}

PermutGenerator::PermutGenerator(int size) {
    size_ = size;
}

std::string PermutGenerator::PrintArray(int array[]) {
    std::string result = "";
    for (int i = 0; i < size_; i++) {
        result += std::to_string(array[i]);
    }
    return result;
}

void PermutGenerator::CreateArray(int array[]) {
    for (int i = 0; i < size_; i++) {
        array[i] = i;
    }
}

void PermutGenerator::swap(int* a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool PermutGenerator::NextSet(int* array) {
    int j = size_ - 2;
    while (j != -1 && array[j] >= array[j + 1])
        j--;
    if (j == -1)
        return false; // больше перестановок нет

    int k = size_ - 1;
    while (array[j] >= array[k])
        k--;
    swap(array, j, k);
    int l = j + 1, r = size_ - 1; // сортируем оставшуюся часть последовательности
    while (l < r)
        swap(array, l++, r--);
    return true;
}


std::string PermutGenerator::GeneratorPermut(int array[]) {
    std::string result = PrintArray(array);
    while (NextSet(array))
        result += ' ' + PrintArray(array);
    return result;
}

