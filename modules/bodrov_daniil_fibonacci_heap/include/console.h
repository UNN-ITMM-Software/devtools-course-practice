// Copyright 2024 Savchuk Anton

#ifndef MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_CONSOLE_H_
#define MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_CONSOLE_H_

#include "include/fibonacci_heap.h"

class Console {
 public:
    void run();

 private:
    FibonacciHeap<int> heap;

    void printMenu();
    void handleUserInput();
    void insertElement();
    void extractMinimum();
    void decreaseKey();
    void deleteNode();
    void mergeHeaps();
};

#endif  // MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_CONSOLE_H_
