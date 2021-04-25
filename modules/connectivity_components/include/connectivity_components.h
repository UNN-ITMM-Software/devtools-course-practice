// Copyright 2021 Pestreev Daniil

#ifndef MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_
#define MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_

class Graph {
 private:
    char* used;
    int** matrix;
    int n;
 public:
    explicit Graph(int n_);
    ~Graph();
    int& element(int i, int j);
    void dfs(int s);
    int countConectComps();
};

#endif  // MODULES_CONNECTIVITY_COMPONENTS_INCLUDE_CONNECTIVITY_COMPONENTS_H_
