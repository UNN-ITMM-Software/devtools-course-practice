// Copyright 2024 Safarov Nurlan
#include "include/dijkstra_algoritm_app.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  DijkstraAlgorithmApp appObject;
  std::string output = appObject.dijkstra_algorithm_application(argc, argv);
  std::cout << output << '\n';
  return 0;
}
