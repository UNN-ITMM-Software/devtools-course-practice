// Copyright 2021 Makaryichev Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Makarichev_Sergey_ComplexNumberTest, Equals_One) {
    double re = 3.0984, im = 9.5671;
    ComplexNumber num(re, im);

    ComplexNumber result = num / num;
    ASSERT_DOUBLE_EQ(1.0, result.getRe());
    ASSERT_DOUBLE_EQ(0.0, result.getIm());
}

TEST(Makarichev_Sergey_ComplexNumberTest, Equals_Zero) {
    double re1 = 16.89475;
    double im1 = 57.01124;
    ComplexNumber num = ComplexNumber();
    num.setRe(re1);
    num.setIm(im1);

    ComplexNumber cresult = num - num;
    ASSERT_TRUE(cresult.getRe() == 0.0);
    ASSERT_TRUE(cresult.getIm() == 0.0);
}

TEST(Makarichev_Sergey_ComplexNumberTest, Arifmetic_Operation_With_Complex) {
    ComplexNumber number1(5.0, 7.0);
    ComplexNumber number2(-2.0, 9.0);
    ComplexNumber number3(5.0, -6.0);

    ComplexNumber cres = number1 * number2 - number3;
  ComplexNumber dres(-78.0, 37.0);

    ASSERT_EQ(dres.getRe(), cres.getRe());
    ASSERT_EQ(dres.getIm(), cres.getIm());
}
