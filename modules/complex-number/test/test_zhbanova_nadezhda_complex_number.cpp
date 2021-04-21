// Copyright 2021 Nadezhda Zhbanova

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nadezhda_Zhbanova_ComplexNumberTest, equality_of_complex_numbers) {
    double re_0 = 3.15;
    double re_1 = 3.15;
    double im_0 = 7.35;
    double im_1 = 7.35;

    ComplexNumber z0(re_0, im_0);
    ComplexNumber z1(re_1, im_1);

    ASSERT_TRUE(z0 == z1);
}

TEST(Nadezhda_Zhbanova_ComplexNumberTest, divide_the_number_by_itself) {
    ComplexNumber z1(3.15, 7.35);
    ComplexNumber z2;
    double re = 3.15;
    double im = 7.35;
    z2.setRe(re);
    z2.setIm(im);
    ComplexNumber z = z2 / z1;

    ComplexNumber expected_z(1.0, 0.0);
    ASSERT_EQ(z, expected_z);
}

TEST(Nadezhda_Zhbanova_ComplexNumberTest, inequality_of_complex_numbers) {
    double re_0 = 3.15;
    double re_1 = 3.15;
    double im_0 = 8.35;
    double im_1 = 7.35;

    ComplexNumber z0(re_0, im_0);
    ComplexNumber z1(re_1, im_1);

    ASSERT_TRUE(z0 != z1);
}
