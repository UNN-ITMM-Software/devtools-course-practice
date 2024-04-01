// Copyright 2024 Ivanov Nikita

#include "include/subseq.h"

void LIS::addNumber(int a) {
    nums.push_back(a);
}

size_t LIS::getSize() {
    return nums.size();
}

std::vector<int> LIS::run() {
    size_t n = getSize();
    std::vector<int> ans;

    if (n == 0ull)
        return ans;

    std::vector<int> prev(n, -1);
    std::vector<int> d(n, 1);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int length = d[0];
    for (size_t i = 0; i < n; ++i) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    while (pos != -1) {
        ans.push_back(nums[pos]);
        pos = prev[pos];
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
}
