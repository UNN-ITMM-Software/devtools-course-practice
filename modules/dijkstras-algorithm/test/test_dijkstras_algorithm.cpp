// Copyright 2021 Rustamov Azer

#include <gtest/gtest.h>
#include <limits>
#include <vector>

#include "include/dijkstras_algorithm.h"


constexpr double EPSILON = 0.0001;

TEST(Dijkstra_Algorithm, Incorrect_Verts_Throws_Exception) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 0;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };;
    ASSERT_ANY_THROW(GraphAlgorithms::dijkstras_algorithm(graph, verts, 0));
}

TEST(Dijkstra_Algorithm, Incorrect_Source_Throws_Exception) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 5;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };;
    ASSERT_ANY_THROW(GraphAlgorithms::dijkstras_algorithm(graph, verts, 100));
}

TEST(Dijkstra_Algorithm, Correct_Answer_Unoriented_5_Seq) {
    double inf = std::numeric_limits<double>::infinity();
    int verts = 5;
    Matrix graph = {inf, inf, 7,   3,   9,
                    inf, inf, 2,   15,  4,
                    7,   2,   inf, 10,  inf,
                    3,   15,  10,  inf, inf,
                    9,   4,   inf, inf, inf };
    Matrix expected_result = {0, 9, 7, 3, 9};

    Matrix result = GraphAlgorithms::dijkstras_algorithm(graph, verts, 0);
    for (int i = 0; i < verts; i++) {
        if ((expected_result[i] != inf) || (result[i] != inf)) {
            ASSERT_NEAR(expected_result[i], result[i], EPSILON);
        }
    }
}
