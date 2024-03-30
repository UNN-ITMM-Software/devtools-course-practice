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

TEST(Kriseev_Mikhail_ComplexNumberTest, AdditionOperator) {
    double re1 = 0.4;
    double re2 = -9.0;
    double im1 = 2.4;
    double im2 = 2.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    c = c2 + c1;
    EXPECT_DOUBLE_EQ(re1+re2, c.getRe());
    EXPECT_DOUBLE_EQ(im1+im2, c.getIm());
}

TEST(Kriseev_Mikhail_ComplexNumberTest, SubtractOperator) {
    double re1 = 0.4;
    double re2 = -9.0;
    double im1 = 2.4;
    double im2 = 2.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    c = c2 - c1;
    EXPECT_DOUBLE_EQ(re2-re1, c.getRe());
    EXPECT_DOUBLE_EQ(im2-im1, c.getIm());
}

TEST(Kriseev_Mikhail_ComplexNumberTest, MultiplicationOperator) {
    double re1 = 0.4;
    double re2 = -9.0;
    double im1 = 2.4;
    double im2 = 2.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    double expectedRe = -9.6;
    double expectedIm = -20.6;

    c = c2 * c1;
    EXPECT_DOUBLE_EQ(expectedRe, c.getRe());
    EXPECT_DOUBLE_EQ(expectedIm, c.getIm());
}

TEST(Kriseev_Mikhail_ComplexNumberTest, DivisionOperator) {
    double re1 = 1.5;
    double re2 = -9.0;
    double im1 = 5.0;
    double im2 = 2.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    double expectedRe = -0.01146;
    double expectedIm = -0.55873;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-5);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-5);
}

TEST(Kriseev_Mikhail_ComplexNumberTest, DivisionOperatorRealNumbers) {
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
TEST(Kriseev_Mikhail_ComplexNumberTest, DivisionOperatorImaginaryNumbers) {
    double re1 = 0.0;
    double re2 = 0.0;
    double im1 = 9.0;
    double im2 = -1.5;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber c;

    // Да, получается действительное число
    double expectedRe = im1 / im2;
    double expectedIm = 0.0;

    c = c1 / c2;

    EXPECT_NEAR(expectedRe, c.getRe(), 1e-6);
    EXPECT_NEAR(expectedIm, c.getIm(), 1e-6);
}

TEST(Kriseev_Mikhail_ComplexNumberTest, DivisionImaginaryByReal) {
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
TEST(Kriseev_Mikhail_ComplexNumberTest, DivisionRealByImaginary) {
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
