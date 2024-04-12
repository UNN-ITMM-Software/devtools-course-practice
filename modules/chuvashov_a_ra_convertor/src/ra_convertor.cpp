// Copyright 2024 Chuvashov Andrey

#include "../include/ra_convertor.h"

bool Convertor::isRomanValid(const std::string roman_num) {
    int previousValue = 0;

    for (int i = roman_num.length() - 1; i >= 0; --i) {
        int currentValue = roman_nums[roman_num[i]];

        if (currentValue >= previousValue) {
            previousValue = currentValue;
        } else {
            if (previousValue <= 5 * currentValue) {
                return false;
            } else {
                previousValue = currentValue;
            }
        }
    }

    return true;
}

std::string Convertor::ArabicToRoman(const int arabic_num) {
    if (arabic_num < 1 || arabic_num > 15000) {
        throw std::invalid_argument(
            "Input must be greater then 0 and less then 15000");
    }
    std::string roman_num = "";
    int current = arabic_num;
    for (size_t i = 0; i < values.size(); i++) {
        int times = current / values[i];
        while (times--) {
            roman_num += chars[i];
        }
        current = current % values[i];
    }

    return roman_num;
}

int Convertor::RomanToArabic(const std::string roman_num) {
    size_t l = roman_num.length();

    if (!l || l > 15) {
        throw std::invalid_argument(
            "Input's length must be greater then 0 and less then 15");
    }

    if (l == 1) {
        return roman_nums[roman_num[0]];
    }

    if (!isRomanValid(roman_num)) {
        throw std::invalid_argument("Incorrect input");
    }

    int arabic_num = 0;

    for (size_t i = 0; i < l; i++) {
        if (roman_nums[roman_num[i]] < roman_nums[roman_num[i+1]]) {
            arabic_num -= roman_nums[roman_num[i]];
        } else {
            arabic_num += roman_nums[roman_num[i]];
        }
    }
    return arabic_num;
}
