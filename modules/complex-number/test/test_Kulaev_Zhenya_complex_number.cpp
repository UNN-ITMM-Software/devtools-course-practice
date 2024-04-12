// Copyright 2024 Kulaev Zhenya

#include <gtest/gtest.h>

#include "include/complex_number.h"

bool isEqualWithD(ComplexNumber a, double re, double im) {
    return (a.getRe() == re) && (a.getIm() == im);
}

bool isEqualWithComNum(ComplexNumber a, ComplexNumber b) {
    return (a.getRe() == b.getRe()) && (a.getIm() == b.getIm());
}

TEST(Kulaev_Zhenya_ComplexTest, test_1_getter) {
    double re = 5.2512;
    double im = 10.24212;

    ComplexNumber z(re, im);

    EXPECT_TRUE(isEqualWithD(z, re, im));
}

TEST(Kulaev_Zhenya_ComplexTest, test_2_setter) {
    double re = 0.125;
    double im = 3.132;

    ComplexNumber z;

    z.setIm(im);
    z.setRe(re);

    EXPECT_TRUE(isEqualWithD(z, re, im));
}

TEST(Kulaev_Zhenya_ComplexTest, test_3_assignments) {
    double re1 = 4.4;
    double im1 = 3.2;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2;

    z2 = z1;

    EXPECT_TRUE(isEqualWithComNum(z1, z2));
}

TEST(Kulaev_Zhenya_ComplexTest, test_4_div_by_zero) {
    ComplexNumber z1(534.353, 3124.25);
    ComplexNumber z2(0, 0);

    EXPECT_ANY_THROW(z1 / z2);
}

TEST(Kulaev_Zhenya_ComplexTest, test_5_copying) {
    ComplexNumber z1(4.4, 3.2);
    ComplexNumber z2(z1);

    EXPECT_TRUE(isEqualWithComNum(z1, z2));
}


TEST(Kulaev_Zhenya_ComplexTest, test_6_sum) {
    ComplexNumber z1(4.4, 3.2);
    ComplexNumber z2(z1);

    ComplexNumber z3(0, 0);
    z3 = z1 + z2;

    EXPECT_TRUE(isEqualWithD(z3, 8.8, 6.4));
}


TEST(Kulaev_Zhenya_ComplexTest, test_6_sub) {
    ComplexNumber z1(4.4, 3.2);
    ComplexNumber z2(z1);

    ComplexNumber z3(0, 0);
    z3 = z1 - z2;

    EXPECT_TRUE(isEqualWithD(z3, 0.0, 0.0));
}

TEST(Kulaev_Zhenya_ComplexTest, test_7_mult) {
    ComplexNumber z1(1.5, 1.0);
    ComplexNumber z2(z1);

    ComplexNumber z3(0, 0);
    z3 = z1 * z2;

    EXPECT_TRUE(isEqualWithD(z3, 1.25, 3.0));
}
