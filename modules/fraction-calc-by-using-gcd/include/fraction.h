// Copyright 2021 Yurin Stanislav

#ifndef MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_H_

class Fraction {
 public:
    explicit Fraction(int n = 0, int d = 1);

    int getNumerator() const;
    int getDenominator() const;

    // Greatest Commom Divisor - наибольший общий делитель
    int gcd(int, int);

    // Least Common Multiple - наименьшее общее кратное
    int lcm(int, int);

    Fraction& operator=(const Fraction&);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);

 private:
    int numerator;
    int denominator;
};

#endif  // MODULES_FRACTION_CALC_BY_USING_GCD_INCLUDE_FRACTION_H_
