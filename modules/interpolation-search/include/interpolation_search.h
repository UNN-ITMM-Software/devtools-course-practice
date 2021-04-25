// Copyright 2021 Napylov Evgeniy

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <vector>

namespace InterpSearch {
    std::vector<int> get_random_vec(int size, int min, int max);

    int interpolation_search(std::vector<int> vec, int key, bool unique_keys);

    int linear_search(std::vector<int> vec, int key);
}

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
