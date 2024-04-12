// Copyright 2024 Chuvashov Andrey

#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <map>
#include <string>

class Convertor {
 private:
    std::map<char, int> roman_nums = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    std::vector<int> values = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    std::vector<std::string> chars = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
 public:
    bool isRomanValid(const std::string roman_num);
    std::string ArabicToRoman(const int arabic_num);
    int RomanToArabic(const std::string roman_num);
};
