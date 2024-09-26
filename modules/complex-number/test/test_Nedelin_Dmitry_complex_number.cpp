// Copyright 2024 Nedelin Dmitry

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Nedelin_Dmitry_ComplexNumberTest, contructor_test) {
    ASSERT_NO_THROW(ComplexNumber());
    ASSERT_NO_THROW(ComplexNumber(-15.0, 23.2));
    ASSERT_NO_THROW(ComplexNumber(ComplexNumber(-58.5781, 952.9172)));
}

TEST(Nedelin_Dmitry_ComplexNumberTest, getter_test) {
    ComplexNumber z(296.127, 28.12);

    ASSERT_DOUBLE_EQ(z.getRe(), 296.127);
    ASSERT_DOUBLE_EQ(z.getIm(), 28.12);
}

TEST(Nedelin_Dmitry_ComplexNumberTest, setter_test) {
    ComplexNumber z{};
    z.setRe(123.257);
    z.setIm(-95.159);

    ASSERT_DOUBLE_EQ(z.getRe(), 123.257);
    ASSERT_DOUBLE_EQ(z.getIm(), -95.159);
}

TEST(Nedelin_Dmitry_ComplexNumberTest, sum_operator_test) {
    ComplexNumber z1(16.5, 12.3);
    ComplexNumber z2(-16.5, 12.3);

    ComplexNumber res = z1 + z2;

    ASSERT_DOUBLE_EQ(res.getRe(), 0.0);
    ASSERT_DOUBLE_EQ(res.getIm(), 24.6);
}

TEST(Nedelin_Dmitry_ComplexNumberTest, dif_opetator_test) {
    ComplexNumber z1(7.3, 32.6);
    ComplexNumber z2(-2.7, 32.6);

    ComplexNumber res = z1 - z2;

    ASSERT_DOUBLE_EQ(res.getRe(), 10.0);
    ASSERT_DOUBLE_EQ(res.getIm(), 0.0);
}

TEST(Nedelin_Dmitry_ComplexNumberTest, equal_operator_test) {
    ComplexNumber z1(5.0, 2.0);
    ComplexNumber z2(5.0, 2.0);
    ComplexNumber z3(7.0, 1.0);

    EXPECT_FALSE(z1 == z3);
    EXPECT_TRUE(z1 == z2);
}