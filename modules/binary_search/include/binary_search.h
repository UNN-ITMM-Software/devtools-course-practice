// Copyright 2021 Makarov Alexander

#ifndef MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <vector>
#include <string>

namespace binary_search {

    template <typename T>
    int BinSearch(T key, std::vector<T> array, int left, int right) {
        if (left < 0 || left >= static_cast<int>(array.size())) {
            const std::string msg("Left border out of range");
            throw msg;
        }
        if (right < 0 || right >= static_cast<int>(array.size())) {
            const std::string msg("Right border out of range");
            throw msg;
        }
        if (right < left) {
            const std::string msg(
                    "Right border must be greater than left border");
            throw msg;
        }
        int middle;
        bool flag = false;
        while (left <= right && !flag) {
            middle = (left + right) / 2;
            if (array[middle] == key)
                flag = true;
            else if (array[middle] > key)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return flag ? middle : -1;
    }

}  // namespace binary_search

#endif  // MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
