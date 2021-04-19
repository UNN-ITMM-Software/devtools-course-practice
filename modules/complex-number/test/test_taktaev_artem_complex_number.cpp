// Copyright 2021 Taktaev Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Taktaev_Artem_ComplexNumberTest, dividing_throws) {
    double re = -1.0;
    double im = 2.0;

    ComplexNumber c_zero;
    ComplexNumber c(re, im);

    ASSERT_ANY_THROW(c / c_zero);
}

TEST(Taktaev_Artem_ComplexNumberTest, dividing_and_mult_work_in_pair) {
    double re1 = 1.2;
    double im1 = -2.3;

    ComplexNumber c1(re1, im1);
    ComplexNumber c2(-0.6, 1.9);
    ComplexNumber c3 = c1 * c2 / c2;

    ASSERT_DOUBLE_EQ(re1, c3.getRe());
    ASSERT_DOUBLE_EQ(im1, c3.getIm());
}

TEST(Taktaev_Artem_ComplexNumberTest, both_constructors_creates_same_objects) {
    double re = -2.0;
    double im = 1.0;

    ComplexNumber c_set;
    c_set.setRe(re);
    c_set.setIm(im);
    ComplexNumber c_copy(c_set);
    ComplexNumber c_param(re, im);

    ASSERT_EQ(c_copy, c_param);
}
