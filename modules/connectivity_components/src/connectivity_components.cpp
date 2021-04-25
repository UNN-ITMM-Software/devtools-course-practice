// Copyright 2021 Pestreev Daniil

#include "include/connectivity_components.h"

Graph::Graph(int i): n(i) {
    matrix = new int*[n];
    for (int g = 0; g < n; g++)
        matrix[g] = new int[n];
    used = new char[n];
}

Graph::~Graph() {
         for (int i = 0; i < n; i++) {
               delete[] matrix[i];
         }
         delete[] matrix;
         delete[] used;
    }

int& Graph::element(int i, int j) {
    if (i < n && j < n && i >= 0 && j >= 0)
        return matrix[i][j];
    else
        throw -1;
}

void Graph::dfs(int s) {
    used[s] = '1';
    for (int i = 0; i < n; i++) {
        if (used[i] == '0' && (matrix[s][i] >= 1 || matrix[i][s] >= 1))
            dfs(i);
    }
}

int Graph::countConectComps() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        used[i] = '0';
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == '0') {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
