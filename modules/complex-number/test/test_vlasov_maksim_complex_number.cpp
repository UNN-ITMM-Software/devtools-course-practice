// Copyright 2021 Vlasov Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vlasov_Maksim_ComplexNumberTest, can_be_copied) {
    double re = 1.0;
    double im = 2.0;

    ComplexNumber c(re, im);
    ComplexNumber c_copy(c);

    ASSERT_EQ(re, c_copy.getRe());
    ASSERT_EQ(im, c_copy.getIm());
}

TEST(Vlasov_Maksim_ComplexNumberTest, can_be_copy_assigned) {
    double re = 1.0;
    double im = 2.0;

    ComplexNumber c(re, im);
    ComplexNumber c_copy = c;

    ASSERT_EQ(re, c_copy.getRe());
    ASSERT_EQ(im, c_copy.getIm());
}

TEST(Vlasov_Maksim_ComplexNumberTest, can_set_real_part) {
    double re = 1.0;

    ComplexNumber c;
    c.setRe(re);

    ASSERT_EQ(re, c.getRe());
}

TEST(Vlasov_Maksim_ComplexNumberTest, can_set_imaginary_part) {
    double im = 2.0;

    ComplexNumber c;
    c.setIm(im);

    ASSERT_EQ(im, c.getIm());
}
