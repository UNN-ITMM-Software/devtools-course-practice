#include <iostream>
#include "include/console.h"

void Console::run() {
    while (true) {
        printMenu();
        handleUserInput();
    }
}

void Console::printMenu() {
    std::cout << "Fibonacci Heap Operations:" << std::endl;
    std::cout << "1. Insert Element" << std::endl;
    std::cout << "2. Extract Minimum" << std::endl;
    std::cout << "3. Decrease Key" << std::endl;
    std::cout << "4. Delete Node" << std::endl;
    std::cout << "5. Merge Heaps" << std::endl;
    std::cout << "Enter your choice: ";
}

void Console::handleUserInput() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            insertElement();
            break;
        case 2:
            extractMinimum();
            break;
        case 3:
            decreaseKey();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            mergeHeaps();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

void Console::insertElement() {
    int value;
    std::cout << "Enter the value to insert: ";
    std::cin >> value;
    heap.insert(value);
    std::cout << "Element inserted successfully." << std::endl;
}

void Console::extractMinimum() {
    if (heap.empty()) {
        std::cout << "Heap is empty. Cannot extract minimum." << std::endl;
        return;
    }
    int minValue = heap.extractMin();
    std::cout << "Minimum element extracted: " << minValue << std::endl;
}

void Console::decreaseKey() {
    if (heap.empty()) {
        std::cout << "Heap is empty. Cannot decrease key." << std::endl;
        return;
    }

    int index, newValue;
    std::cout << "Enter the index of the node: ";
    std::cin >> index;
    std::cout << "Enter the new value: ";
    std::cin >> newValue;

    FibonacciHeapNode<int>* node = heap.insert(newValue);
    heap.decreaseKey(node, newValue);
    std::cout << "Key decreased successfully." << std::endl;
}

void Console::deleteNode() {
    if (heap.empty()) {
        std::cout << "Heap is empty. Cannot delete node." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter the index of the node to delete: ";
    std::cin >> index;

    FibonacciHeapNode<int>* node = heap.insert(index);
    heap.deleteNode(node);
    std::cout << "Node deleted successfully." << std::endl;
}

void Console::mergeHeaps() {
    FibonacciHeap<int> otherHeap;
    int numElements;
    std::cout << "Enter the number of elements in the other heap: ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        int value;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        otherHeap.insert(value);
    }

    heap.merge(&otherHeap);
    std::cout << "Heaps merged successfully." << std::endl;
}