// Copyright 2021 Napylov Evgeniy

#include "include/interpolation_search.h"
#include <time.h>
#include <random>
#include <vector>

std::vector<int> InterpSearch::get_random_vec(int size, int min, int max) {
    static std::mt19937 gen(time(0));
    std::vector<int> result(size);
    std::uniform_int_distribution<int> distr(min, max);
    for (int i = 0; i < size; i++) {
        result[i] = (distr(gen));
    }
    return result;
}

int search_algorithm(const std::vector<int>& vec, int key) {
    const int size = vec.size();
    int left = 0;
    int right = size - 1;

    while (vec[left] < key && vec[right] > key && vec[left] != vec[right]) {
        int index = (key - vec[left]) * (left - right) /
                        (vec[left] - vec[right]) + left;

        if (vec[index] > key) {
            right = index - 1;
        } else {
            if (vec[index] < key) {
                left = index + 1;
            } else {
                return index;
            }
        }
    }
    if (vec[left] == key) {
        return left;
    } else {
        if (vec[right] == key) {
            return right;
        } else {
            return -1;
        }
    }
}

int InterpSearch::interpolation_search(std::vector<int> vec, int key,
                                                  bool unique_keys) {
    if (vec.size() == 0) {
        return -1;
    }

    int res = search_algorithm(vec, key);

    if (res == -1 || unique_keys) {
        return res;
    } else {
        int id = res - 1;
        if (id < 0) return res;
        while (vec[id] == key) {
            id--;
        }
        return id + 1;
    }
}

int InterpSearch::linear_search(std::vector<int> vec, int key) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        if (vec[i] == key) {
            return i;
        }
    }
    return -1;
}
