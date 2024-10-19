// Copyright 2024 Shemiakina Alesia

#include "include/graph_components.h"

#include <iostream>
#include <vector>

void DFS(int x, std::vector<std::vector<int>>& v, std::vector<int>& was) {
  was[x] = 1;
  for (int y : v[x])
    if (was[y] == 0) DFS(y, v, was);
}

int graph_components_numbers(int n, std::vector<std::vector<int>> v) {
  std::vector<int> was(n);
  for (int x = 0; x < n; x++) {
    was[x] = 0;
  }
  int ans = 0;
  for (int x = 0; x < n; x++) {
    if (was[x] == 0) {
      DFS(x, v, was);
      ans++;
    }
  }
  return ans;
}
