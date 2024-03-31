// Copyright 2024 Shmelev Ivan

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Shmelev_Ivan_Complex_Number, Getters_Test) {
    ComplexNumber z(1.0, 2.0);
    EXPECT_DOUBLE_EQ(1.0, z.getRe());
    EXPECT_DOUBLE_EQ(2.0, z.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Getters_Fractional_Test) {
    ComplexNumber z(1.25, 2.5);
    EXPECT_DOUBLE_EQ(1.25, z.getRe());
    EXPECT_DOUBLE_EQ(2.5, z.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Setters_Test) {
    ComplexNumber z;
    z.setRe(1.0);
    z.setIm(2.0);
    EXPECT_DOUBLE_EQ(1.0, z.getRe());
    EXPECT_DOUBLE_EQ(2.0, z.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Setters_Fractional_Test) {
    ComplexNumber z;
    z.setRe(1.25);
    z.setIm(2.5);
    EXPECT_DOUBLE_EQ(1.25, z.getRe());
    EXPECT_DOUBLE_EQ(2.5, z.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Sum_Complex_Numbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3 = z1 + z2;
    EXPECT_DOUBLE_EQ(4.0, z3.getRe());
    EXPECT_DOUBLE_EQ(6.0, z3.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Sum_Fraction_Complex_Numbers) {
    ComplexNumber z1(1.25, 2.5);
    ComplexNumber z2(3.85, 4.3);
    ComplexNumber z3 = z1 + z2;
    EXPECT_DOUBLE_EQ(5.1, z3.getRe());
    EXPECT_DOUBLE_EQ(6.8, z3.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Difference_Complex_Numbers) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(5.0, 7.0);
    ComplexNumber z3 = z2 - z1;
    EXPECT_DOUBLE_EQ(3.0, z3.getRe());
    EXPECT_DOUBLE_EQ(4.0, z3.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Difference_Fraction_Complex_Numbers) {
    ComplexNumber z1(2.25, 3.1);
    ComplexNumber z2(5.75, 7.9);
    ComplexNumber z3 = z2 - z1;
    EXPECT_DOUBLE_EQ(3.5, z3.getRe());
    EXPECT_DOUBLE_EQ(4.8, z3.getIm());
}

TEST(Shmelev_Ivan_Complex_Number, Divide_By_Zero) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(0.0, 0.0);
    ASSERT_ANY_THROW(z1 / z2);
}
