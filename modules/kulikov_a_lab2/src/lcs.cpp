// Copyright 2024 Kulikov Artem

#include <algorithm>
#include <vector>

#include "include/lcs.h"

std::string LCS::findLCS(const std::string& str1, const std::string& str2) {
    auto lengths = getLCSLengths(str1, str2);
    return constructLCS(str1, str2, lengths);
}

std::vector<std::vector<size_t>> LCS::getLCSLengths(const std::string& str1,
                                                    const std::string& str2) {
    size_t m = str1.size();
    size_t n = str2.size();
    std::vector<std::vector<size_t>> lengths(m + 1,
                                             std::vector<size_t>(n + 1, 0));

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lengths[i][j] = lengths[i - 1][j - 1] + 1;
            } else {
                lengths[i][j] = std::max(lengths[i - 1][j], lengths[i][j - 1]);
            }
        }
    }
    return lengths;
}

std::string LCS::constructLCS(const std::string& str1, const std::string& str2,
                              const std::vector<std::vector<size_t>>& lengths) {
    size_t i = str1.size();
    size_t j = str2.size();
    std::string result;

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result = str1[i - 1] + result;
            --i;
            --j;
        } else if (lengths[i - 1][j] > lengths[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    return result;
}
