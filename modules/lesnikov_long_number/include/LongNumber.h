// Copyright 2024 Lesnikov Nikita

#pragma once

#include <vector>
#include <cstdint>
#include <string>

#define TYPE uint8_t
#define BIG_TYPE int32_t
#define MAX_VALUE 9

class LongNumber {
 public:
    LongNumber();
    LongNumber(const LongNumber& n);
    LongNumber(LongNumber&& n) noexcept;
    explicit LongNumber(const std::string& s);
    LongNumber& operator=(const LongNumber& n);
    LongNumber& operator=(LongNumber&& n) noexcept;
    LongNumber operator+(const LongNumber& n) const;
    LongNumber& operator+=(const LongNumber& n);
    LongNumber operator-(const LongNumber& n) const;
    LongNumber& operator-=(const LongNumber& n);
    LongNumber operator*(const LongNumber& n);
    LongNumber& operator*=(const LongNumber& n);
    LongNumber operator-() const;
    bool operator==(const LongNumber& n) const;
    bool operator!=(const LongNumber& n) const;
    bool operator<(const LongNumber& n) const;
    bool operator>(const LongNumber& n) const;
    bool operator<=(const LongNumber& n) const;
    bool operator>=(const LongNumber& n) const;
    bool absIsLess(const LongNumber& n) const;
    bool absIsGreater(const LongNumber& n) const;

    std::string getString() const;

 private:
    static void _checkZero(LongNumber& n);

    std::vector<TYPE> _data;
    bool _negative = false;
};
