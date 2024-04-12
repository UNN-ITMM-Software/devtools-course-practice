// Copyright 2024 Kudinov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudinov_Nikita_ComplexNumberTest, CanConstruct) {
    EXPECT_NO_THROW(ComplexNumber());
    EXPECT_NO_THROW(ComplexNumber(10.3, -3.6));
    EXPECT_NO_THROW(ComplexNumber(ComplexNumber(-43.1, 22.3)));
}

TEST(Kudinov_Nikita_ComplexNumberTest, DefaultConstructorShouldEqualToZero) {
    auto cn = ComplexNumber();

    EXPECT_DOUBLE_EQ(cn.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(cn.getIm(), 0.0);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanGetFields) {
    auto re = 774.2;
    auto im = 112.3;
    auto cn = ComplexNumber(re, im);

    EXPECT_NO_THROW(cn.getRe());
    EXPECT_NO_THROW(cn.getIm());

    EXPECT_DOUBLE_EQ(cn.getRe(), re);
    EXPECT_DOUBLE_EQ(cn.getIm(), im);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanSetFields) {
    auto re = 774.2;
    auto im = 112.3;
    auto cn = ComplexNumber();

    EXPECT_NO_THROW(cn.setRe(re));
    EXPECT_NO_THROW(cn.setIm(im));

    EXPECT_DOUBLE_EQ(cn.getRe(), re);
    EXPECT_DOUBLE_EQ(cn.getIm(), im);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanAssign) {
    auto cn1 = ComplexNumber(123.2, 7.1);
    auto cn2 = ComplexNumber(-33.2, 13.2);

    EXPECT_NO_THROW(cn2 = cn1);

    EXPECT_DOUBLE_EQ(cn1.getRe(), cn2.getRe());
    EXPECT_DOUBLE_EQ(cn1.getIm(), cn2.getIm());
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanSum) {
    auto cn1 = ComplexNumber(123.2, 7.1);
    auto cn2 = ComplexNumber(-33.2, 13.2);
    auto cn3 = ComplexNumber();

    EXPECT_NO_THROW(cn3 = cn1 + cn2);

    EXPECT_DOUBLE_EQ(cn3.getRe(), 90.0);
    EXPECT_DOUBLE_EQ(cn3.getIm(), 20.3);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanSubtract) {
    auto cn1 = ComplexNumber(123.2, 7.1);
    auto cn2 = ComplexNumber(-33.2, 13.2);
    auto cn3 = ComplexNumber();

    EXPECT_NO_THROW(cn3 = cn1 - cn2);

    EXPECT_DOUBLE_EQ(cn3.getRe(), 156.4);
    EXPECT_DOUBLE_EQ(cn3.getIm(), -6.1);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanMultiply) {
    auto cn1 = ComplexNumber(7.0, 2.0);
    auto cn2 = ComplexNumber(-9.0, 5.0);
    auto cn3 = ComplexNumber();

    EXPECT_NO_THROW(cn3 = cn1 * cn2);

    EXPECT_DOUBLE_EQ(cn3.getRe(), -73.0);
    EXPECT_DOUBLE_EQ(cn3.getIm(), 17.0);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanDivide) {
    auto cn1 = ComplexNumber(7.0, 2.0);
    auto cn2 = ComplexNumber(-9.0, 5.0);
    auto cn3 = ComplexNumber();

    EXPECT_NO_THROW(cn3 = cn1 / cn2);

    EXPECT_DOUBLE_EQ(cn3.getRe(), -0.5);
    EXPECT_DOUBLE_EQ(cn3.getIm(), -0.5);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CannotDivideBy0) {
    auto cn1 = ComplexNumber(7.0, 2.0);
    auto cn2 = ComplexNumber();

    EXPECT_THROW(cn1 / cn2, std::string);
}

TEST(Kudinov_Nikita_ComplexNumberTest, CanCheckEquality) {
    auto cn1 = ComplexNumber(7.0, 2.0);
    auto cn2 = ComplexNumber(7.0, 2.0);

    EXPECT_NO_THROW(cn1 == cn2);
    EXPECT_NO_THROW(cn1 != cn2);

    EXPECT_TRUE(cn1 == cn2);
    EXPECT_FALSE(cn1 != cn2);
}
