// Copyright 2024 Khodyrev Fedor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Khodyrev_Fedor_test, test_real_and_imaginary_getters) {
    ComplexNumber cn = ComplexNumber(1.0, 2.0);
    EXPECT_DOUBLE_EQ(1.0, cn.getRe());
    EXPECT_DOUBLE_EQ(2.0, cn.getIm());
}

TEST(Khodyrev_Fedor_test, test_real_and_imaginary_setters) {
    ComplexNumber cn;
    cn.setRe(1.0);
    cn.setIm(2.0);
    EXPECT_DOUBLE_EQ(1.0, cn.getRe());
    EXPECT_DOUBLE_EQ(2.0, cn.getIm());
}

TEST(Khodyrev_Fedor_test, test_operator_equal) {
    ComplexNumber cn = ComplexNumber(1.0, 2.0);
    ComplexNumber cn2 = ComplexNumber(3.0, 4.0);
    cn = cn2;
    EXPECT_DOUBLE_EQ(3.0, cn.getRe());
    EXPECT_DOUBLE_EQ(4.0, cn.getIm());
}

TEST(Khodyrev_Fedor_test, test_operator_sum) {
    ComplexNumber cn = ComplexNumber(1.0, 2.0);
    ComplexNumber cn2 = ComplexNumber(3.0, 4.0);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn + cn2;
    EXPECT_DOUBLE_EQ(4.0, cn3.getRe());
    EXPECT_DOUBLE_EQ(6.0, cn3.getIm());
}

TEST(Khodyrev_Fedor_test, test_operator_difference) {
    ComplexNumber cn = ComplexNumber(1.0, 2.0);
    ComplexNumber cn2 = ComplexNumber(3.0, 4.0);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn2 - cn;
    EXPECT_DOUBLE_EQ(2.0, cn3.getRe());
    EXPECT_DOUBLE_EQ(2.0, cn3.getIm());
}

TEST(Khodyrev_Fedor_test, test_operator_multiply) {
    ComplexNumber cn = ComplexNumber(1.0, 2.0);
    ComplexNumber cn2 = ComplexNumber(3.0, 4.0);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn * cn2;
    EXPECT_DOUBLE_EQ(-5.0, cn3.getRe());
    EXPECT_DOUBLE_EQ(10.0, cn3.getIm());
}

TEST(Khodyrev_Fedor_test, test_operator_division) {
    ComplexNumber cn = ComplexNumber(6.0, 12.0);
    ComplexNumber cn2 = ComplexNumber(3.0, -6.0);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn / cn2;
    EXPECT_DOUBLE_EQ(-1.2, cn3.getRe());
    EXPECT_DOUBLE_EQ(1.6, cn3.getIm());
}
