// Copyright 2024 Dostavalov Semyon

#include "include/KMP.h"
#include <vector>
#include <string>
#include <iostream>

namespace KnuthMorrisPratt {
    std::vector<int> computePrefixFunction(const std::string& pattern) {
        int patternLength = pattern.size();
        std::vector<int> prefixArray(patternLength, 0);
        int border = 0;
        for (int q = 1; q < patternLength; ++q) {
            while (border > 0 && pattern[border] != pattern[q]) {
                border = prefixArray[border - 1];
            }
            if (pattern[border] == pattern[q]) {
                border++;
            }
            prefixArray[q] = border;
        }

        return prefixArray;
    }

    std::vector<int> findPattern(const std::string& text,
        const std::string& pattern) {
        std::vector<int> prefixArray = computePrefixFunction(pattern);
        std::vector<int> occurrences;
        int textLength = text.size();
        int patternLength = pattern.size();
        int border = 0;
        for (int i = 0; i < textLength; ++i) {
            while (border > 0 && pattern[border] != text[i]) {
                border = prefixArray[border - 1];
            }
            if (pattern[border] == text[i]) {
                border++;
            }
            if (border == patternLength) {
                occurrences.push_back(i - patternLength + 1);
                border = prefixArray[border - 1];
            }
        }

        return occurrences;
    }
}  // namespace KnuthMorrisPratt
