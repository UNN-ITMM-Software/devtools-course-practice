// Copyright 2021 Gapon Andrey
#ifndef MODULES_POLINOMIAL_CALCULATION_INCLUDE_MONOM_H_
#define MODULES_POLINOMIAL_CALCULATION_INCLUDE_MONOM_H_

struct Monom {
    double coef;
    int pow;

    Monom* next;

    Monom();
};

#endif  // MODULES_POLINOMIAL_CALCULATION_INCLUDE_MONOM_H_
