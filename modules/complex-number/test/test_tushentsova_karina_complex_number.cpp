// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0, im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Addition) {
    ComplexNumber z1(3, 4), z2(2, 6);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(result.getRe(), 5);
    EXPECT_EQ(result.getIm(), 10);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Subtract) {
    ComplexNumber z1(3, 4), z2(1, 0);

    ComplexNumber result = z1 - z2;

    EXPECT_EQ(result.getRe(), 2);
    EXPECT_EQ(result.getIm(), 4);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Multiply) {
    ComplexNumber z1(1, 2), z2(2, 1);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(result.getRe(), 0);
    EXPECT_EQ(result.getIm(), 5);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Multiply_By_Zero) {
    ComplexNumber z1(1, 2), z2(0, 0);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(result.getRe(), 0);
    EXPECT_EQ(result.getIm(), 0);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Divide) {
    ComplexNumber z1(3, 5), z2(2, 1);

    ComplexNumber result = z1 / z2;

    EXPECT_EQ(result.getRe(), 2.2);
    EXPECT_EQ(result.getIm(), 1.4);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Divide_By_Zero) {
    ComplexNumber z1(3, 5), z2(0, 0);

    ASSERT_THROW(z1 / z2, std::string);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Copy) {
    ComplexNumber z1(1, 1), z2;
    z2 = z1;

    EXPECT_DOUBLE_EQ(z2.getRe(), 1);
    EXPECT_DOUBLE_EQ(z2.getIm(), 1);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Compare) {
    ComplexNumber z1(1, 0);
    ComplexNumber z2(2, 0);
    ComplexNumber z3(2, 0);

    ASSERT_TRUE(z1 != z2);
    ASSERT_TRUE(z2 == z3);
    ASSERT_FALSE(z1 == z2);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Create_Fractional) {
    double re = 1.5, im = 2.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Addition_Fractional) {
    ComplexNumber z1(1.3, 2.1), z2(1.0, 1.5);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(result.getRe(), 2.3);
    EXPECT_EQ(result.getIm(), 3.6);
}

TEST(Tushentsova_Karina_ComplexNumberTest, Can_Divide_Fractional_By_Zero) {
    ComplexNumber z1(1.5, 2.5), z2(0.0, 0.0);

    ASSERT_THROW(z1 / z2, std::string);
}
