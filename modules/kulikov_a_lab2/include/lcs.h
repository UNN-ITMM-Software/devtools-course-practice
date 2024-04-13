// Copyright 2024 Kulikov Artem

#ifndef MODULES_KULIKOV_A_LAB2_INCLUDE_LCS_H_
#define MODULES_KULIKOV_A_LAB2_INCLUDE_LCS_H_

#include <string>
#include <vector>

class LCS {
public:
    static std::string findLCS(const std::string& str1,
                               const std::string& str2);

private:
    static std::vector<std::vector<int>> getLCSLengths(const std::string& str1,
                                                       const std::string& str2);
    static std::string constructLCS(
        const std::string& str1, const std::string& str2,
        const std::vector<std::vector<int>>& lengths);
};

#endif  // MODULES_KULIKOV_A_LAB2_INCLUDE_LCS_H_
