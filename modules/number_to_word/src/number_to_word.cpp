// Copyright 2021 Lukyanchenko Ivan

#include <string>
#include "include/number_to_word.h"

void num_to_word::num2word() {
    const char* third[10] = { " ", "one hundred ", "two hundred ",
    "three hundred ", "four hundred ", "five hundred ", "six hundred ",
    "seven hundred ", "eight hundred ", "nine hundred " };
    const char* second1[10] = { "ten ", "eleven ", "twelve ",
    "thirteen ", "fourteen ", "fiveteen ", "sixteen ",
    "seventeen ", "eigthteen ", "nineteen " };
    const char* second2[10] = { " ", " ", "twenty ", "thirty ",
    "fourty ", "fifty ", "sixty ", "seventy ", "eigthty ", "ninety " };
    const char* first[10] = { "", "one", "two", "three"
     "four", "five", "six", "seven", "eigth", "nine" };
    int i = 0;
    int k = num;
    while (k != 0) {
        k = k / 10;
        i++;
    }
    while (i != 0) {
        if (i == 9) {
            word += third[num / 100000000];
            num %= 100000000;
            i--;
        }
        if ((i == 8) && (num / 10000000 == 1)) {
            word += second1[(num / 10000000) % 10];
            word += " million ";
            num %= 10000000;
            num %= 1000000;
            i -= 2;
        }
        if ((i == 8) && (num / 10000000 != 1)) {
            word += second2[num / 10000000];
            num %= 10000000;
            i--;
        }
        if (i == 7) {
            word += first[num / 1000000];
            word += " million ";
            num %= 1000000;
            i--;
        }
        if (i == 6) {
            word += third[num / 100000];
            if (((num % 100000) / 10000 == 0) &&
                ((num % 10000) / 1000 == 0) && (num / 100000 != 0)) {
                word += "thousand ";
            }
            num %= 100000;
            i--;
        }
        if ((i == 5) && (num / 10000 == 1)) {
            word += second1[(num / 1000)%10];
            word += "thousand ";
            num %= 10000;
            num %= 1000;
            i -= 2;
        }
        if ((i == 5) && (num / 10000 != 1)) {
            word += second2[num / 10000];
            if (((num % 10000) / 1000 == 0) && (num / 10000 != 0)) {
                word += " thousand ";
            }
            num %= 10000;
            i--;
        }
        if (i == 4) {
            if (num / 1000 != 0) {
                word += first[num / 1000];
                word += " thousand ";
            }
            num %= 1000;
            i--;
        }
        if (i == 3) {
            word += third[num / 100];
            num %= 100;
            i--;
        }
        if ((i == 2) && (num / 10 == 1)) {
            word += second1[num % 10];
            break;
        }
        if ((i == 2) && (num / 10 != 1)) {
            word += second2[num / 10];
            num %= 10;
            i--;
        }
        if (i == 1) {
            word += first[num];
            i--;
        }
    }
}

std::string num_to_word::get_word() const {
    return word;
}
