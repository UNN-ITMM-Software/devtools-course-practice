// Copyright 2021 Kolesin Andrey

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_


class Complex {
   double real;
   double imag;
public:
   Complex(double r = 0, double i = 0);
   double getReal();
   double getImag();

};



#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
