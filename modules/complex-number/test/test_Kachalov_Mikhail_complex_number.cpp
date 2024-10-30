// Copyright 2024 Kachalov Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kachalov_Mikhail_ComplexNumberTest, Can_Add_ComplexNumbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, -4.0);

    ComplexNumber result = z1 + z2;

    EXPECT_EQ(4.0, result.getRe());
    EXPECT_EQ(-2.0, result.getIm());
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Can_Subtract_ComplexNumbers) {
    ComplexNumber z1(5.0, 6.0);
    ComplexNumber z2(3.0, 2.0);

    ComplexNumber result = z1 - z2;

    EXPECT_EQ(2.0, result.getRe());
    EXPECT_EQ(4.0, result.getIm());
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Can_Multiply_ComplexNumbers) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(4.0, -1.0);

    ComplexNumber result = z1 * z2;

    EXPECT_EQ(11.0, result.getRe());
    EXPECT_EQ(10.0, result.getIm());
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Are_Equal_ComplexNumbers) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    EXPECT_EQ(z1, z2);
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Are_Not_Equal_ComplexNumbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(2.0, 1.0);

    EXPECT_NE(z1, z2);
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Can_Divide_ComplexNumbers) {
    ComplexNumber z1(4.0, 2.0);
    ComplexNumber z2(3.0, -1.0);

    ComplexNumber result = z1 / z2;

    EXPECT_NEAR(1.0, result.getRe(), 1e-9);
    EXPECT_NEAR(1.0, result.getIm(), 1e-9);
}

TEST(Kachalov_Mikhail_ComplexNumberTest, Division_By_Zero_ComplexNumbers) {
    ComplexNumber z1(4.0, 2.0);
    ComplexNumber z2(0.0, 0.0);

    EXPECT_THROW({
        ComplexNumber result = z1 / z2;
    }, std::runtime_error);
}
