// Copyright 2024 Zhatkin Vyacheslav

#include "include/levenshtein_distance.h"

LevenshteinDistance::LevenshteinDistance() {
    str1 = "";
    str1 = "";
    result = 0;
}

LevenshteinDistance::LevenshteinDistance(const std::string& str1_,
    const std::string& str2_) {
    str1 = str1_;
    str2 = str2_;
    result = distance();
}

int LevenshteinDistance::distance() {
    std::vector<std::vector<int>> matrix(str1.size() + 1,
        std::vector<int>(str2.size() + 1));

    for (int i = 0; i <= static_cast<int>(str1.size()); i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= static_cast<int>(str2.size()); j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= static_cast<int>(str1.size()); i++) {
        for (int j = 1; j <= static_cast<int>(str2.size()); j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            matrix[i][j] = std::min(
                matrix[i - 1][j] + 1,
                std::min(matrix[i][j - 1] + 1,
                matrix[i - 1][j - 1] + cost));
        }
    }

    return matrix[str1.size()][str2.size()];
}

void LevenshteinDistance::setStr1(const std::string& str1_) {
    str1 = str1_;
    result = distance();
}

void LevenshteinDistance::setStr2(const std::string& str2_) {
    str2 = str2_;
    result = distance();
}

std::string LevenshteinDistance::getStr1() {
    return str1;
}

std::string LevenshteinDistance::getStr2() {
    return str2;
}

int LevenshteinDistance::getResult() {
    return result;
}
