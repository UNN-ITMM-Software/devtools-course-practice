// Copyright 2024 Nedelin Dmitry

#include "include/number_to_words.h"

#include <climits>
#include <sstream>
#include <array>

std::string trim(const std::string& str) {
    std::string trimmed = str;
    auto end = trimmed.find_last_not_of(' ');
    if (end != std::string::npos) {
        trimmed.erase(end + 1);
    }
    return trimmed;
}

std::string NumberToWords::convert(int number) {
    if (number == 0) {
        return "zero";
    }
    if (number == INT_MIN) {
        return "negative two billion one hundred forty seven million four "
               "hundred eighty three thousand six hundred forty eight";
    }

    std::stringstream ss;

    if (number < 0) {
        ss << "negative ";
        number = -number;
    }

    static constexpr int BILLION = 1000000000;
    static constexpr int MILLION = 1000000;
    static constexpr int THOUSAND = 1000;

    if (number >= BILLION) {
        ss << convertLessThanOneThousand(number / BILLION) << " billion";
        number %= BILLION;
        if (number > 0) {
            ss << " ";
        }
    }

    if (number >= MILLION) {
        ss << convertLessThanOneThousand(number / MILLION) << " million";
        number %= MILLION;
        if (number > 0) {
            ss << " ";
        }
    }

    if (number >= THOUSAND) {
        ss << convertLessThanOneThousand(number / THOUSAND) << " thousand";
        number %= THOUSAND;
        if (number > 0) {
            ss << " ";
        }
    }

    if (number > 0) {
        ss << convertLessThanOneThousand(number);
    }

    return trim(ss.str());
}

std::string NumberToWords::convertLessThanOneThousand(int number) {
    static const std::array<std::string, 20> units{
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    static const std::array<std::string, 10> tens{
        "", "", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"
    };

    std::stringstream ss;
    if (number >= 100) {
        ss << units[number / 100] << " hundred";
        number %= 100;
        if (number > 0) {
            ss << " ";
        }
    }
    if (number >= 20) {
        ss << tens[number / 10];
        number %= 10;
        if (number > 0) {
            ss << " ";
        }
    }
    if (number > 0) {
        ss << units[number];
    }

    return ss.str();
}
