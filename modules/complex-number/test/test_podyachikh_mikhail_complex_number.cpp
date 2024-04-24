// Copyright 2024 Podyachikh Mikhail

#include <gtest/gtest.h>
#include <cmath>
#include "include/complex_number.h"

TEST(Podyachikh_Mikhail_ComplexNumberTest, ConstructorAndCopyConstructor) {
    double re = -2.0;
    double im = 3.5;
    ComplexNumber c(re, im);
    ComplexNumber c2(c);
    EXPECT_EQ(re, c2.getRe());
    EXPECT_EQ(im, c2.getIm());
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, EqualityOperator) {
    double re = 0.52;
    double im = -1.45;
    ComplexNumber c1(re, im);
    ComplexNumber c2(re, im);
    EXPECT_TRUE(c1 == c2);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, EqualityOperatorNegative) {
    double re1 = 0.42;
    double re2 = -94.04;
    double im1 = 23.43;
    double im2 = 24.0;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    EXPECT_FALSE(c1 == c2);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, AssignmentOperator) {
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

TEST(Podyachikh_Mikhail_ComplexNumberTest, DivisionByZero) {
    ComplexNumber first = ComplexNumber(1.0, 1.0);
    ComplexNumber zero = ComplexNumber(0.0, 0.0);

    ASSERT_ANY_THROW(first / zero);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, DivisionRealByImaginary) {
    double re1 = 9.0;
    double re2 = 0.0;
    double im1 = 0.0;
    double im2 = -1.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    double expectedRe = 0.0;
    double expectedIm = -re1 / im2;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-6);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-6);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, DivisionImaginaryByReal) {
    double re1 = 0.0;
    double re2 = -1.5;
    double im1 = 9.0;
    double im2 = 0.0;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    double expectedRe = 0.0;
    double expectedIm = im1 / re2;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-6);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-6);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, DivisionOperatorRealNumbers) {
    double re1 = 9.0;
    double re2 = -1.5;
    double im1 = 0.0;
    double im2 = 0.0;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    double expectedRe = re1 / re2;
    double expectedIm = 0.0;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-6);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-6);
}

TEST(Podyachikh_Mikhail_ComplexNumberTest, DivisionOperatorImaginaryNumbers) {
    double re1 = 0.0;
    double re2 = 0.0;
    double im1 = 9.0;
    double im2 = -1.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    // It becomes a real number
    double expectedRe = im1 / im2;
    double expectedIm = 0.0;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-6);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-6);
}
