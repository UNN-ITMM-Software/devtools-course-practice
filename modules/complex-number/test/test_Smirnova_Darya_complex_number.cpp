// Copyright 2024 Smirnova Darya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Smirnova_Daria_ComplexNumberTest, Can_Square_Complex) {
ComplexNumber a(3.0, 2.0);
ComplexNumber result = a * a;

ComplexNumber exp_ans(5.0, 12.0);

EXPECT_EQ(exp_ans, result);
}

TEST(Smirnova_Daria_ComplexNumberTest, Cant_Divide_By_Zero) {
ComplexNumber a(-32., 24.);
ComplexNumber b(0., 0.);

ASSERT_ANY_THROW(a / b);
}

TEST(Smirnova_Daria_ComplexNumberTest, Addition_Is_Commutative) {
ComplexNumber z1(4.5, 3.2);
ComplexNumber z2(-1.3, 5.8);

ComplexNumber result1 = z1 + z2;
ComplexNumber result2 = z2 + z1;

EXPECT_EQ(result1, result2);
}

TEST(Smirnova_Daria_ComplexNumberTest, Division_By_Itself_Equals_One) {
ComplexNumber z1(7.0, -3.0);

ComplexNumber result = z1 / z1;

ComplexNumber exp_ans(1.0, 0.0);
EXPECT_EQ(exp_ans, result);
}

TEST(Smirnova_Daria_ComplexNumberTest, Can_Create_Addition) {
ComplexNumber z1(1.5, 6.4);
ComplexNumber z2(3.0, 2.1);

ComplexNumber z3 = z1 + z2;

EXPECT_EQ(4.5, z3.getRe());
EXPECT_EQ(8.5, z3.getIm());
}

TEST(Smirnova_Daria_ComplexNumberTest, Can_Equal) {
ComplexNumber z1(1.0, 3.2);
ComplexNumber z2(2.0, 5.0);

ASSERT_TRUE(z1 != z2);
ASSERT_FALSE(z1 == z2);
}
