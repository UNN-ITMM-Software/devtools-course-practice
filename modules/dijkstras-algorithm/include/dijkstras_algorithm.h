// Copyright 2021 Rustamov Azer

#include <vector>

#ifndef MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_
#define MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_

using Matrix = std::vector<double>;
namespace GraphAlgorithms {
    Matrix dijkstras_algorithm
        (const Matrix& graph, int verts, int source_vertex);
}

#endif  // MODULES_DIJKSTRAS_ALGORITHM_INCLUDE_DIJKSTRAS_ALGORITHM_H_
