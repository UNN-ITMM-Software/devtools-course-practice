// Copyright 2021 Kurnikova Anastasia

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_be_created) {
    double re = 4.0;
    double im = 1.0;

    ComplexNumber a(re, im);

    ASSERT_NO_THROW(a);
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, correct_multiply_with_const) {
    double re = 4.0;
    double im = 1.0;

    ComplexNumber a(re, im);
    ComplexNumber b(2.0, 0.0);
    ComplexNumber c = a * b;

    ASSERT_DOUBLE_EQ(8.0, c.getRe());
    ASSERT_DOUBLE_EQ(2.0, c.getIm());
}

TEST(Kurnikova_Anastasia_ComplexNumberTest, can_compare) {
    double re1 = 4.0;
    double im1 = 1.0;
    double re2 = 0.0;
    double im2 = 5.0;

    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);

    EXPECT_EQ(0, a == b);
}
