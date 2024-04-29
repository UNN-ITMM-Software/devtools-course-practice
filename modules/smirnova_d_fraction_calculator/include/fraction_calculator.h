// Copyright 2024 Smirnova Darya

#ifndef MODULES_SMIRNOVA_D_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_
#define MODULES_SMIRNOVA_D_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_

#include <string>

class FractionCalculator {
 private:
     int num;
     int den;

 public:
     FractionCalculator();
     FractionCalculator(const int numerator, const int denominator);
     int GetNum() const;
     int GetDen() const;
     void SetNum(const int numerator);
     void SetDen(const int denominator);
     int NOD(int a, int b) const;
     std::string ToString() const;

     FractionCalculator operator+(const  FractionCalculator& z) const;
     FractionCalculator operator-(const  FractionCalculator& z) const;
     FractionCalculator operator*(const  FractionCalculator& z) const;
     FractionCalculator operator/(const  FractionCalculator& z) const;
     FractionCalculator& operator=(const FractionCalculator& z);
};

#endif  // MODULES_SMIRNOVA_D_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_
