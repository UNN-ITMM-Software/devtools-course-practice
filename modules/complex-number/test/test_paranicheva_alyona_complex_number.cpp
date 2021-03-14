// Copyright 2021 Paranicheva Alyona

#include <gtest/gtest.h>
#include <math.h>

#include "include/complex_number.h"

TEST(Paranicheva_Alyona_ComplexNumberTest, Module) {
    ComplexNumber z(6.0, -8.0);

    double resmodule = sqrt(pow(z.getRe(), 2) + pow(z.getIm(), 2));
    EXPECT_EQ(10.0, resmodule);
}

TEST(Paranicheva_Alyona_ComplexNumberTest, Module_Addition) {
    ComplexNumber z1(6.0, -8.0);
    ComplexNumber z2(3.0, -4.0);

    double resmodule1 = sqrt(pow(z1.getRe(), 2) + pow(z1.getIm(), 2));
    double resmodule2 = sqrt(pow(z2.getRe(), 2) + pow(z2.getIm(), 2));
    double sum = resmodule1 + resmodule2;

    EXPECT_EQ(15.0, sum);
}

TEST(Paranicheva_Alyona_ComplexNumberTest, Module_Subtraction) {
    ComplexNumber z1(6.0, -8.0);
    ComplexNumber z2(3.0, -4.0);

    double resmodule1 = sqrt(pow(z1.getRe(), 2) + pow(z1.getIm(), 2));
    double resmodule2 = sqrt(pow(z2.getRe(), 2) + pow(z2.getIm(), 2));
    double sub = resmodule1 - resmodule2;

    EXPECT_EQ(5.0, sub);
}
