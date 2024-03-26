// Copyright 2024 Safarov Nurlan

#include "include/interpolation_search.h"

int interpolationSearch(const std::vector<int> &sequence, const int &target) {
    if (sequence.size() == 0) {
        return -1;
    }

    int left = 0;
    int right = sequence.size() - 1;

    while (sequence[left] < target && sequence[right] > target) {
        int index = (target - sequence[left]) * (left - right) / (sequence[left] - sequence[right])
        + left;

        if (sequence[index] > target) {
            right = index - 1;
        } else if (sequence[index] < target) {
            left = index + 1;
        } else {
            return index;
        }
    }

    if (sequence[left] == target) {
        return left;
    } else if (sequence[right] == target) {
        return right;
    }

    return -1;
}
