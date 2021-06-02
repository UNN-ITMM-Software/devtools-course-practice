// Copyright 2021 Gapon Andrey
#ifndef MODULES_POLINOMIAL_CALCULATION_INCLUDE_POLINOM_H_
#define MODULES_POLINOMIAL_CALCULATION_INCLUDE_POLINOM_H_

#include "Monom.h"
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>

enum ElemType { Operation, Operand, Variable };

class Polinom {
    Monom* head;
    int numOfPows;
    int base;
    std::vector<std::string> var;

    const std::string operations = { '+', '-', '*', '^', '(', ')', '=' };

 private:
     int toDecimalSystem(const std::vector<int> v) const;
     int isNumber(std::string str);
     std::queue<std::pair<std::string, ElemType>> Parse(std::string expr);

 public:
    explicit Polinom(std::vector<std::string> _var, int _base = 20);
    Polinom(std::string str, std::vector<std::string> var, int _base = 20);

    Polinom(const Polinom& r);
    ~Polinom();

    void sortedAdd(int coef, int pows);

    Polinom operator+(const Polinom& r);
    Polinom operator-(const Polinom& r);
    Polinom operator*(const Polinom& r);
    bool operator==(const Polinom& r) const;
    bool operator!=(const Polinom& r) const;

    Polinom operator*(double factor);
};

#endif  // MODULES_POLINOMIAL_CALCULATION_INCLUDE_POLINOM_H_
