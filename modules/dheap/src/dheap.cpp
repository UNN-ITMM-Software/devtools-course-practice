// Copyright 2021 Gogov Vladislav

#include "include/dheap.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

Dheap::Dheap(int base_) : base(base_) {
    if (base_ <= 1)
        throw std::runtime_error("Base must be greater than 1");
}

Dheap::Dheap(int base_, const std::vector<int>& weights_) : base(base_),
                                                            weights(weights_) {
    hilling();
}

void Dheap::transpose(int i, int j) {
    std::swap(weights[i], weights[j]);
}

int Dheap::findMinChild(int node) const {
    int size = static_cast<int>(weights.size());
    int firstChild = node * base + 1;
    if (firstChild >= size)
        return -1;
    int lastChild =
        std::min(size - 1, base * (node + 1));
    int minChild = firstChild;
    for (int i = firstChild + 1; i <= lastChild; i++) {
        if (weights[i] < weights[minChild])
            minChild = i;
    }
    return minChild;
}

void Dheap::diving(int node) {
    int minChild = findMinChild(node);
    while ((minChild != -1) && (weights[minChild] < weights[node])) {
        transpose(minChild, node);
        node = minChild;
        minChild = findMinChild(node);
    }
}

void Dheap::emersion(int node) {
    while (node > 0) {
        int parentChild = (node - 1) / base;
        if (weights[parentChild] > weights[node]) {
            transpose(node, parentChild);
            node = parentChild;
        } else {
            break;
        }
    }
}

void Dheap::hilling() {
    int size = static_cast<int>(weights.size());
    for (int i = size - 1; i >= 0; i--)
        diving(i);
}

void Dheap::popMin() {
    weights.front() = weights.back();
    diving(0);
    weights.pop_back();
}

int Dheap::topMin() const {
    return weights.front();
}

void Dheap::insert(int value) {
    weights.push_back(value);
    int size = static_cast<int>(weights.size());
    emersion(size - 1);
}

int Dheap::getBase() const {
    return base;
}

size_t Dheap::getSize() const {
    return weights.size();
}

const std::vector<int>& Dheap::getWeights() const {
    return weights;
}
