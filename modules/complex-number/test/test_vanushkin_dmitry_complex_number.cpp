// Copyright 2024 Dmitry Vanushkin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vanushkin_Dmitry_ComplexNumberTest, DivideByZeroImaginaryAndNonZeroReal) {
    auto divisible = ComplexNumber(0, 0);
    auto divider = ComplexNumber(1, 0);

    auto expect = ComplexNumber(0, 0);

    ASSERT_EQ(divisible / divider, expect);
}

TEST(Vanushkin_Dmitry_ComplexNumberTest, DivideByZeroImaginaryAndZeroReal) {
    auto divisible = ComplexNumber(0, 0);
    auto divider = ComplexNumber(0, 0);

    ASSERT_ANY_THROW(divisible / divider);
}

TEST(Vanushkin_Dmitry_ComplexNumberTest, MultiplyByConjugateComplexNumber) {
    auto real = 10;
    auto imaginary = 9;

    auto number = ComplexNumber(real, imaginary);
    auto conjugateNumber = ComplexNumber(real, -imaginary);

    auto expectProduct = ComplexNumber(real * real + imaginary * imaginary, 0);

    ASSERT_EQ(number * conjugateNumber, expectProduct);
}
