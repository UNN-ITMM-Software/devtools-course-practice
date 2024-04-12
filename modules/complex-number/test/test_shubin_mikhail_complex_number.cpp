// Copyright 2024 Shubin Mikhail

#include <gtest/gtest.h>

#include <random>

#include "include/complex_number.h"

#define MIN_RAND -100.0
#define MAX_RAND 100.0

double round_double(double val, int zeros) {
  return (static_cast<int>(val * pow(10, zeros)))/pow(10, zeros);
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Sum_Random) {
    std::uniform_real_distribution<double> unif(MIN_RAND, MAX_RAND);
    std::default_random_engine re;
    double re1 = unif(re);
    double im1 = unif(re);
    double re2 = unif(re);
    double im2 = unif(re);

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z = z1 + z2;

    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Sub_Random) {
    std::uniform_real_distribution<double> unif(MIN_RAND, MAX_RAND);
    std::default_random_engine re;
    double re1 = unif(re);
    double im1 = unif(re);
    double re2 = unif(re);
    double im2 = unif(re);

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z = z1 - z2;

    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Mult_Random) {
    std::uniform_real_distribution<double> unif(MIN_RAND, MAX_RAND);
    std::default_random_engine re;
    double re1 = unif(re);
    double im1 = unif(re);
    double re2 = unif(re);
    double im2 = unif(re);

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z = z1 * z2;

    EXPECT_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_EQ(im1 * re2 + re1 * im2, z.getIm());
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Div_Random) {
    std::uniform_real_distribution<double> unif(MIN_RAND, MAX_RAND);
    std::default_random_engine re;
    double re1 = unif(re);
    double im1 = unif(re);
    double re2 = unif(re);
    double im2 = unif(re);

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z = z1 / z2;

    EXPECT_EQ(round_double((re1 * re2 + im1 * im2) /
              (re2 * re2 + im2 * im2), 8),
              round_double(z.getRe(), 8));
    EXPECT_EQ(round_double((im1 * re2 - re1 * im2) /
              (re2 * re2 + im2 * im2), 8),
              round_double(z.getIm(), 8));
}

TEST(Shubin_Mikhail_ComplexNumberTest, Cannot_Divide_By_Zero) {
    std::uniform_real_distribution<double> unif(MIN_RAND, MAX_RAND);
    std::default_random_engine re;
    ComplexNumber z(unif(re), unif(re));
    ComplexNumber z0(0.0, 0.0);

    ASSERT_ANY_THROW(z / z0);
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Check_Eq) {
    double re1 = 0.0;
    double im1 = 0.0;
    double re2 = 0.0;
    double im2 = 0.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    EXPECT_EQ(z1, z2);
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Check_NE) {
    double re1 = 0.0;
    double im1 = 0.0;
    double re2 = 1.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    EXPECT_NE(z1, z2);
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Set_Re) {
    double re = 0.0;
    double im = 0.0;
    double re1 = 1.0;

    ComplexNumber z(re, im);
    z.setRe(re1);

    EXPECT_EQ(re1, z.getRe());
}

TEST(Shubin_Mikhail_ComplexNumberTest, Can_Set_Im) {
    double re = 0.0;
    double im = 0.0;
    double im1 = 1.0;

    ComplexNumber z(re, im);
    z.setIm(im1);

    EXPECT_EQ(im1, z.getIm());
}
