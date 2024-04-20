// Copyright 2024 Vinichuk Timofey

#ifndef MODULES_VINICHUK_T_BINARY_SEARCH_INCLUDE_BINARYSEARCH_H_
#define MODULES_VINICHUK_T_BINARY_SEARCH_INCLUDE_BINARYSEARCH_H_

#include <iostream>
#include <vector>

static const int NOT_LISTED = -1;

// implementing a template function implies
// its definition in the place of declaration(header file)
template <typename T>
int binary_search(const std::vector<T>& arr, const T& target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return NOT_LISTED;
}

#endif  // MODULES_VINICHUK_T_BINARY_SEARCH_INCLUDE_BINARYSEARCH_H_
