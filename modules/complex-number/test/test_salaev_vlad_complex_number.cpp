// Copyright 2024 Salaev Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Salaev_Vlad_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Create_With_Real_And_Imaginary) {
    double re = 1.0;
    double im = -1.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Copy_Complex_Number) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Assign_Complex_Numbers) {
    ComplexNumber z1(3.4, 6.1);
    ComplexNumber z2 = z1;

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Add_Complex_Numbers) {
    ComplexNumber z1(5.6, 1.1);
    ComplexNumber z2(4.5, 3.3);
    ComplexNumber z = z1 + z2;

    EXPECT_EQ(10.1, z.getRe());
    EXPECT_EQ(4.4, z.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    ComplexNumber z1(5.0, 6.0);
    ComplexNumber z2(1.0, 2.0);
    ComplexNumber z = z1 - z2;

    EXPECT_EQ(4.0, z.getRe());
    EXPECT_EQ(4.0, z.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z = z1 * z2;

    EXPECT_EQ(-5.0, z.getRe());
    EXPECT_EQ(10.0, z.getIm());
}

TEST(Salaev_Vlad_ComplexNumberTest, Throw_Div_By_Zero) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(0.0, 0.0);

    EXPECT_THROW(z1 / z2, std::string);
}
