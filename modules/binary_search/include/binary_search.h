// Copyright 2021 Makarov Alexander

#ifndef MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <stdexcept>
#include <string>
#include <vector>

namespace BinarySearch {

    template <typename T>
    int Search(const T& key, const std::vector<T>& array, int left, int right) {
        if (left < 0 || right < 0 || left > static_cast<int>(array.size()) ||
            right > static_cast<int>(array.size()) || left > right) {
            throw std::runtime_error("Wrong borders");
        }
        int middle;
        bool is_sorted = false;
        while (left <= right && !is_sorted) {
            middle = (left + right) / 2;
            if (array[middle] == key)
                is_sorted = true;
            else if (array[middle] > key)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return is_sorted ? middle : -1;
    }

}  // namespace BinarySearch

#endif  // MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
