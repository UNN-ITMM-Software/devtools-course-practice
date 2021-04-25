// Copyright 2021 Gogov Vladislav

#include <iostream>
#include <vector>

#ifndef MODULES_DHEAP_INCLUDE_DHEAP_H_
#define MODULES_DHEAP_INCLUDE_DHEAP_H_

class Dheap {
    int base;
    std::vector<int> weights;

    int findMinChild(int node) const;
    void transpose(int i, int j);
    void diving(int node);
    void emersion(int node);
    void hilling();

 public:
    explicit Dheap(int base_ = 2);
    Dheap(int base_, const std::vector<int>& weights_);
    ~Dheap() = default;

    void popMin();
    int topMin() const;

    void insert(int value);
    int getBase() const;
    size_t getSize() const;

    const std::vector<int>& getWeights() const;
};

#endif  // MODULES_DHEAP_INCLUDE_DHEAP_H_
