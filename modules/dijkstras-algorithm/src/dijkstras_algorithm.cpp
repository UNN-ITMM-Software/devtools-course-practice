// Copyright 2021 Rustamov Azer

#include <iostream>
#include <limits>
#include <vector>

#include "include/dijkstras_algorithm.h"

Matrix GraphAlgorithms::dijkstras_algorithm
        (const Matrix& graph, int verts, int source_vertex) {
    if (graph.size() != (unsigned)verts * verts) {
        throw std::runtime_error("Incorrect graph");
    }
    if (source_vertex >= verts) {
        throw std::runtime_error("Incorrecr source vertex");
    }

    double inf = std::numeric_limits<double>::infinity();
    Matrix distance_to_verex(verts, inf);
    distance_to_verex[source_vertex] = 0.0;
    int closest_vert_out;

    while (true) {
        double shortest_path;
        shortest_path = inf;
        for (int vert_in = 0; vert_in < verts; vert_in++) {
            if (distance_to_verex[vert_in] != inf) {
                for (int vert_out = 0; vert_out < verts; vert_out++) {
                    if ((distance_to_verex[vert_out] == inf) &&
                        ((distance_to_verex[vert_in] +
                        graph[vert_in * verts + vert_out]) < shortest_path)) {
                        closest_vert_out = vert_out;
                        shortest_path = distance_to_verex[vert_in] +
                            graph[vert_in * verts + vert_out];
                    }
                }
            }
        }
        if (shortest_path == inf)
            break;
        distance_to_verex[closest_vert_out] = shortest_path;
    }

    return distance_to_verex;
}
