// Copyright 2024 Tushentsova Karina

#ifndef MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_INCLUDE_PERMUT_GENERATOR_H_
#define MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_INCLUDE_PERMUT_GENERATOR_H_

#include <string>

class PermutGenerator {
 public:
    PermutGenerator(int* arr, int size);
    std::string PrintArray();
    void CreateArray();
    void Swap(int i, int j);
    bool NextSet();
    std::string GeneratorPermut();
    bool BubbleSort();

 private:
    int size_;
    int* array_;
};

#endif  // MODULES_TUSHENTSOVA_K_PERMUT_GENERATOR_INCLUDE_PERMUT_GENERATOR_H_
