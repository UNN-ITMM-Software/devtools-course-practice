// Copyright 2024 Kriseev Mikhail

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kriseev_Mikhail_ComplexNumberTest, InitializerConstructorCorrect) {
    double expectedRe = -2.0;
    double expectedIm = 3.5;
    ComplexNumber c(expectedRe, expectedIm);
    EXPECT_EQ(expectedRe, c.getRe());
    EXPECT_EQ(expectedIm, c.getIm());
}

TEST(Kriseev_Mikhail_ComplexNumberTest, CopyConstructorCorrect) {
    double expectedRe = -2.0;
    double expectedIm = 3.5;
    ComplexNumber c(expectedRe, expectedIm);
    ComplexNumber c2(c);
    EXPECT_EQ(expectedRe, c2.getRe());
    EXPECT_EQ(expectedIm, c2.getIm());
}

TEST(Kriseev_Mikhail_ComplexNumberTest, EqualityOperator) {
    double re = 0.52;
    double im = -1.45;
    ComplexNumber c1(re, im);
    ComplexNumber c2(re, im);
    EXPECT_TRUE(c1 == c2);
}

TEST(Kriseev_Mikhail_ComplexNumberTest, EqualityOperatorNegative) {
    double re1 = 0.42;
    double re2 = -94.04;
    double im1 = 23.43;
    double im2 = 24.0;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);

    EXPECT_FALSE(c1 == c2);
}

TEST(Kriseev_Mikhail_ComplexNumberTest, AssignmentOperator) {
    double re1 = 0.42;
    double re2 = -94.04;
    double im1 = 23.43;
    double im2 = 24.0;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    c = c2 = c1;

    EXPECT_EQ(c1.getRe(), c2.getRe());
    EXPECT_EQ(c1.getIm(), c2.getIm());

    EXPECT_EQ(c1.getRe(), c.getRe());
    EXPECT_EQ(c1.getIm(), c.getIm());

    EXPECT_EQ(c.getRe(), c2.getRe());
    EXPECT_EQ(c.getIm(), c2.getIm());
}
