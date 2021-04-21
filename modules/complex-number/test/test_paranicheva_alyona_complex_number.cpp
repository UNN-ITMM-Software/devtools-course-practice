// Copyright 2021 Paranicheva Alyona

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Paranicheva_Alyona_ComplexNumberTest, Module) {
    ComplexNumber z(6.0, -8.0);

    double resmodule = hypot(z.getRe(), z.getIm());
    ASSERT_DOUBLE_EQ(10.0, resmodule);
}

TEST(Paranicheva_Alyona_ComplexNumberTest, Module_Addition) {
    ComplexNumber z1(6.0, -8.0);
    ComplexNumber z2(3.0, -4.0);

    double resmodule1 = hypot(z1.getRe(), z1.getIm());
    double resmodule2 = hypot(z2.getRe(), z2.getIm());
    double sum = resmodule1 + resmodule2;

    ASSERT_DOUBLE_EQ(15.0, sum);
}

TEST(Paranicheva_Alyona_ComplexNumberTest, Module_Subtraction) {
    ComplexNumber z1(6.0, -8.0);
    ComplexNumber z2(3.0, -4.0);

    double resmodule1 = hypot(z1.getRe(), z1.getIm());
    double resmodule2 = hypot(z2.getRe(), z2.getIm());
    double sub = resmodule1 - resmodule2;

    ASSERT_DOUBLE_EQ(5.0, sub);
}
