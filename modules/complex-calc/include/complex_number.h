// Copyright 2021 Kolesin Andrey

#ifndef MODULES_COMPLEX_CALC_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_COMPLEX_CALC_INCLUDE_COMPLEX_NUMBER_H_

class Complex {
    double real;
    double imag;

 public:
    explicit Complex(double r = 0, double i = 0);
    double getReal() const;
    double getImag() const;
    bool operator==(const Complex& comp) const;
    bool operator!=(const Complex& comp) const;
    const Complex operator+(const Complex& comp);
    const Complex operator-(const Complex& comp);
    const Complex operator*(const Complex& comp);
    const Complex operator/(const Complex& comp);
    friend std::ostream& operator<<(std::ostream& out, const Complex& comp);
    std::string getAsStr() const;
};

#endif  // MODULES_COMPLEX_CALC_INCLUDE_COMPLEX_NUMBER_H_
