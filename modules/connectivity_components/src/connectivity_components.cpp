// Copyright 2021 Tkachev Alexey

#include <vector>

#include "include/connectivity_components.h"

bool Graph::areValidCoords(unsigned int x, unsigned int y) const {
    return x < this->matrix.size() && y < this->matrix.size();
}

std::size_t Graph::getSize() const {
    return this->matrix.size();
}

Graph::Graph(unsigned int n_):
    used(std::vector<bool>(n_, false)),
    matrix(std::vector<std::vector<unsigned int>>(
        n_, std::vector<unsigned int>(n_, 0))) {}

unsigned int Graph::getElement(unsigned int x, unsigned int y) const {
    if (areValidCoords(x, y)) {
        return this->matrix[x][y];
    }
    throw std::exception();
}

void Graph::setElement(unsigned int data, unsigned int x, unsigned int y) {
    if (areValidCoords(x, y)) {
        this->matrix[x][y] = data;
    } else {
        throw std::exception();
    }
}

void Graph::append() {
    for (std::size_t i = 0; i < this->matrix.size(); i++) {
        this->matrix[i].push_back(0);
    }
    unsigned int new_size = 0;
    new_size = this->matrix[0].size();
    this->matrix.emplace_back(new_size, 0);
}

void Graph::dfs(unsigned int from) {
    used[from] = true;
    for (std::size_t i = 0; i < this->matrix.size(); i++) {
        if (!used[i] && (matrix[from][i] >= 1 || matrix[i][from] >= 1)) {
            dfs(i);
        }
    }
}

unsigned int Graph::getCountConnComps() {
    unsigned int count = 0;

    for (std::size_t i = 0; i < this->matrix.size(); i++) {
        if (!used[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}
