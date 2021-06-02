// Copyright 2021 Tkachev Alexey

#ifndef MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_
#define MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_

#include <vector>

class Graph {
 private:
    std::vector<bool> used;
    std::vector<std::vector<unsigned int>> matrix;
    bool areValidCoords(unsigned int x, unsigned int y) const;
    void dfs(unsigned int from);
 public:
    explicit Graph(unsigned int n_);
    unsigned int getElement(unsigned int x, unsigned int y) const;
    void setElement(unsigned int data, unsigned int x, unsigned int y);
    unsigned int getCountConnComps();
    void append();
    std::size_t getSize() const;
};

#endif  // MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_
