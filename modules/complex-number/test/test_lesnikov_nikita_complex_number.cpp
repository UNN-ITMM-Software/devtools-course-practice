// Copyright 2024 Lesnikov Nikita

#include <gtest/gtest.h>
#include "include/complex_number.h"

namespace {
    double precision = 0.0001;

    bool Eq(double a, double b) {
        return std::abs(a - b) < precision;
    }
}

TEST(ComplexNumerTest_Lesnikov_Nikita, ZeroDevisionTest) {
    ComplexNumber n1(1, 1);
    ComplexNumber zero(0, 0);

    ASSERT_ANY_THROW(n1 / zero);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, EqualTest) {
    ComplexNumber n1(1, 1);
    ComplexNumber n2(1, 1);

    EXPECT_EQ(n1, n2);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, NotEqualTestIm) {
    ComplexNumber n1(1, 1);
    ComplexNumber n2(1, 2);

    EXPECT_NE(n1, n2);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, NotEqualTestRe) {
    ComplexNumber n1(1, 1);
    ComplexNumber n2(2, 1);

    EXPECT_NE(n1, n2);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, ReValueTest) {
    ComplexNumber n1(2, 1);

    EXPECT_FLOAT_EQ(n1.getRe(), 2);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, ImValueTest) {
    ComplexNumber n1(2, 1);

    EXPECT_FLOAT_EQ(n1.getIm(), 1);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, AddTest) {
    ComplexNumber n1(2.2, 3.2);
    ComplexNumber n2(4, 5);
    ComplexNumber n3 = n1 + n2;

    EXPECT_FLOAT_EQ(n3.getRe(), 6.2);
    EXPECT_FLOAT_EQ(n3.getIm(), 8.2);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, SubTest) {
    ComplexNumber n1(2.2, 3.2);
    ComplexNumber n2(4, 6);

    ComplexNumber n3 = n1 - n2;

    EXPECT_FLOAT_EQ(n3.getRe(), -1.8);
    EXPECT_FLOAT_EQ(n3.getIm(), -2.8);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, MultTest) {
    ComplexNumber n1(2.2, 3.2);
    ComplexNumber n2(4, 6);

    ComplexNumber n3 = n1 * n2;

    EXPECT_FLOAT_EQ(n3.getRe(), -10.4);
    EXPECT_FLOAT_EQ(n3.getIm(), 26);
}

TEST(ComplexNumerTest_Lesnikov_Nikita, DivTest) {
    ComplexNumber n1(4, 8);
    ComplexNumber n2(4, 10);

    ComplexNumber n3 = n1 / n2;

    EXPECT_TRUE(Eq(n3.getRe(), 0.8275862068965517));
    EXPECT_TRUE(Eq(n3.getIm(), -0.06896551724137931));
}
