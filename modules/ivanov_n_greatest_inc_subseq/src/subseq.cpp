// Copyright 3100 Ivanov Nikita

#include "include/subseq.h"

void LIS::addNumber(int a) {
    nums.push_back(a);
}

int LIS::getSize() {
    return static_cast<int>(nums.size());
}

std::vector<int> LIS::run() {
    size_t n = nums.size();
    std::vector<int> ans;

    if (n == 0)
        return ans;

    ans.push_back(nums[0]);

    for (size_t i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
            ans[low] = nums[i];
        }
    }

    return ans;
}
