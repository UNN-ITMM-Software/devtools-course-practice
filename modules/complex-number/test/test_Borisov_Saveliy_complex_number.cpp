// Copyright 2024 Borisov Saveliy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Borisov_Saveliy_ComplexNumberTest, Can_Copy_Complex_Number) {
    ComplexNumber z(0.4, 2.0);

    ComplexNumber copy_z(z);

    ASSERT_DOUBLE_EQ(copy_z.getRe(), 0.4);
    ASSERT_DOUBLE_EQ(copy_z.getIm(), 2.0);
}

TEST(Borisov_Saveliy_ComplexNumberTest, Can_Assign_Complex_Number) {
    ComplexNumber z1(3.14, 2.72);
    ComplexNumber z2(1.62, 6.63);

    z2 = z1;

    ASSERT_DOUBLE_EQ(z2.getRe(), 3.14);
    ASSERT_DOUBLE_EQ(z2.getIm(), 2.72);
}

TEST(Borisov_Saveliy_ComplexNumberTest, Can_Add_Complex_Numbers) {
    ComplexNumber z1(2.0, 2.4);
    ComplexNumber z2(1.9, 8.4);

    ComplexNumber z3 = z1 + z2;

    ASSERT_DOUBLE_EQ(z3.getRe(), 3.9);
    ASSERT_DOUBLE_EQ(z3.getIm(), 10.8);
}

TEST(Borisov_Saveliy_ComplexNumberTest, Can_Divide_Complex_Numbers) {
    ComplexNumber z1(4.0, 8.0);
    ComplexNumber z2(2.0, 2.0);

    ComplexNumber z3 = z1 / z2;

    ASSERT_DOUBLE_EQ(z3.getRe(), 3.0);
    ASSERT_DOUBLE_EQ(z3.getIm(), 1.0);
}

TEST(Borisov_Saveliy_ComplexNumberTest, Product_of_Complex_Conjugate) {
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(3.0, -4.0);

    ComplexNumber z3 = z1 * z2;

    ASSERT_DOUBLE_EQ(z3.getRe(), 25.0);
    ASSERT_DOUBLE_EQ(z3.getIm(), 0.0);
}

TEST(Borisov_Saveliy_ComplexNumberTest, Throws_When_Divide_By_Zero) {
    ComplexNumber z1(1.1, 1.1);
    ComplexNumber z0(0.0, 0.0);

    ASSERT_THROW(z1 / z0, std::string);
}
