// Copyright 2024 Fedotov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Fedotov_Kirill_ComplexNumberTest, defaultConstruct) {
    ComplexNumber z(re, im);

    ASSERT_EQ(0.0, z.getRe());
    ASSERT_EQ(0.0, z.getIm());
}

TEST(Fedotov_Kirill_ComplexNumberTest, divByZero) {
    ComplexNumber u(5.0, 3.2);
    ComplexNumber v(0.0, 0.0);

    ASSERT_ANY_THROW(u/v);
}

TEST(Fedotov_Kirill_ComplexNumberTest, substract) {
   ASSERT_EQ(ComplexNumber u(2.0,1.0) - ComplexNumber(0.1, 1.0), ComplexNumber(1.9, 0.0));
}

