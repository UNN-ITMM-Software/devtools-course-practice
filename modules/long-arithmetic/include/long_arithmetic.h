// Copyright 2021 Chistov Vladimir
#ifndef MODULES_LONG_ARITHMETIC_INCLUDE_LONG_ARITHMETIC_H_
#define MODULES_LONG_ARITHMETIC_INCLUDE_LONG_ARITHMETIC_H_

#include <vector>
#include <sstream>
#include <iostream>
#include <string>

class bigInt {
    static const int BASE = 1000000000;
    std::vector<int> storage;
    bool negFlag;
    void delZeros();
    void shiftRight();

 public:
    class devByZero : public std::exception {  };
    bigInt();
    explicit bigInt(std::string);
    explicit bigInt(int i);
    bigInt operator -() const;
    bigInt operator ++();
    bigInt operator ++(int i);
    bigInt operator --();
    bigInt operator --(int i);
    bool operator==(const bigInt&) const;
    bool operator!=(const bigInt&) const;
    bool operator<(const bigInt&) const;
    bool operator>(const bigInt&) const;
    bool operator<=(const bigInt&) const;
    bool operator>=(const bigInt&) const;
    bigInt operator+(const bigInt&) const;
    bigInt operator-(const bigInt&) const;
    bigInt operator*(const bigInt&) const;
    bigInt operator/(const bigInt&) const;
    bigInt operator%(const bigInt&) const;
    bigInt& operator +=(const bigInt&);
    bigInt& operator -=(const bigInt&);
    bigInt& operator *=(const bigInt&);
    bigInt& operator /=(const bigInt&);
    bool odd() const;
    bool even() const;
    const bigInt pow(bigInt) const;
};

#endif  // MODULES_LONG_ARITHMETIC_INCLUDE_LONG_ARITHMETIC_H_
