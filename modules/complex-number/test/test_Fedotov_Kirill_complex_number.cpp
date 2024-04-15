// Copyright 2024 Fedotov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Fedotov_Kirill_ComplexNumberTest, defaultConstruct) {
    ComplexNumber z;

    ASSERT_DOUBLE_EQ(0.0, z.getRe());
    ASSERT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Fedotov_Kirill_ComplexNumberTest, divByZero) {
    ComplexNumber u(5.0, 3.2);
    ComplexNumber v(0.0, 0.0);

    ASSERT_ANY_THROW(u/v);
}

TEST(Fedotov_Kirill_ComplexNumberTest, setter) {
    ComplexNumber u;
    u.setRe(2.0);
    u.setIm(5.1);

    ASSERT_EQ(u, ComplexNumber(2.0, 5.1));
}

TEST(Fedotov_Kirill_ComplexNumberTest, equalOperator) {
    ComplexNumber u;
    ComplexNumber v(2.0, 3.0);
    u = v;

    ASSERT_DOUBLE_EQ(2.0, u.getRe());
    ASSERT_DOUBLE_EQ(3.0, u.getIm());
}

TEST(Fedotov_Kirill_ComplexNumberTest, substract) {
    ASSERT_EQ(ComplexNumber u(2.0, 1.0) - ComplexNumber(0.1, 1.0),
    ComplexNumber(1.9, 0.0));
}
