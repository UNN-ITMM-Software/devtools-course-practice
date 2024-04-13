// Copyright 2024 Dostavalov Semyon

#include "include/KMP.h"
#include <vector>
#include <string>
#include <iostream>

namespace KnuthMorrisPratt {
    std::vector<int> computePrefixFunction(const std::string& pattern) {
        int m = pattern.size();
        std::vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; ++q) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }

        std::cout << "Prefix: ";
        for (int val : pi) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        return pi;
    }

    std::vector<int> findPattern(const std::string& text,
        const std::string& pattern) {
        std::vector<int> pi = computePrefixFunction(pattern);
        std::vector<int> occurrences;
        int n = text.size();
        int m = pattern.size();
        int q = 0;
        for (int i = 0; i < n; ++i) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == m) {
                occurrences.push_back(i - m + 1);
                q = pi[q - 1];
            }
        }

        std::cout << "found at positions: ";
        for (int pos : occurrences) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;

        return occurrences;
    }
} // namespace KnuthMorrisPratt
