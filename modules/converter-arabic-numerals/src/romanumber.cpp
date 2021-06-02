// Copyright 2021 Gurylev Nikita

#include <string>

#include "include/romanumber.h"

std::string RomaNumber::RomaConvert(int n, int rank) {
    if (n == 0) {
        return "";
    }
    if (rank == 4) {
        std::string arr[3] = { "M", "MM", "MMM" };
        return arr[n - 1];
    }
    if (rank == 3) {
        std::string arr[9] = { "C", "CC", "CCC", "CD",
            "D", "DC", "DCC", "DCCC", "CM" };
        return arr[n - 1];
    }
    if (rank == 2) {
        std::string arr[9] = { "X", "XX", "XXX", "XL",
            "L", "LX", "LXX", "LXXX", "XC" };
        return arr[n - 1];
    }
        std::string arr[9] = { "I", "II", "III", "IV",
            "V", "VI", "VII", "VIII", "IX" };
        return arr[n - 1];
}

void RomaNumber::arabToRoma(int ar) {
    if (ar < 0 || ar > 3999)
        throw std::string("Wrong number");
    arabic_ = ar;
    roma_ = "";
    for (int i = 1; (ar != 0 && i < 5); ++i) {
        roma_ = RomaConvert(ar % 10, i) + roma_;
        ar /= 10;
    }
}

void RomaNumber::romaToArab(const std::string& ro) {
    if (!IsStringCorrect(ro))
        throw std::string("Wrong string");
    int _ar = 0;
    int n = ro.length();
    for (int i = 0; i < n; ++i) {
        char t = ro[i];
        if (t == 'I') {
            if (ro[i + 1] == 'V' || ro[i + 1] == 'X')
                _ar -= 1;
            else
                _ar += 1;
        } else if (t == 'V') {
            _ar += 5;
        } else if (t == 'X') {
            if (ro[i + 1] == 'L' || ro[i + 1] == 'C')
                _ar -= 10;
            else
                _ar += 10;
        } else if (t == 'L') {
            _ar += 50;
        } else if (t == 'C') {
            if (ro[i + 1] == 'D' || ro[i + 1] == 'M')
                _ar -= 100;
            else
                _ar += 100;
        } else if (t == 'D') {
            _ar += 500;
        } else if (t == 'M') {
            _ar += 1000;
        }
    }
    roma_ = ro;
    arabic_ = _ar;
}

RomaNumber::RomaNumber(int ar) {
    arabToRoma(ar);
}

RomaNumber::RomaNumber(const std::string& ro) {
    if (!IsStringCorrect(ro))
        throw std::string("Wrong string");
    else
        romaToArab(ro);
}

bool RomaNumber::IsStringCorrect(const std::string& ro) {
    int n = ro.length();
    for (int i = 0; i < n; ++i) {
        bool flag = (ro[i] == 'I' || ro[i] == 'V' ||
            ro[i] == 'X' || ro[i] == 'L' ||
            ro[i] == 'C' || ro[i] == 'D' ||
            ro[i] == 'M');
        if (!flag)
            return false;
    }
    return true;
}
