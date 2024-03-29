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

TEST(Vanushkin_Dmitry_ComplexNumberTest, InvertComplexNumber) {
    auto real = 81.62062;
    auto imaginary = 0.999952;

    auto divisible = ComplexNumber(1, 0);
    auto divider = ComplexNumber(real, imaginary);

    auto expectDivision = ComplexNumber(
            real / (real * real + imaginary * imaginary),
            -imaginary / (real * real + imaginary * imaginary));

    ASSERT_EQ(divisible / divider, expectDivision);
}

TEST(Vanushkin_Dmitry_ComplexNumberTest, AddComplexNumbers) {
    auto first = ComplexNumber(955.1585925, -91.999952);
    auto second = ComplexNumber(-39, 91.999952);

    auto expectAdd = ComplexNumber(first.getRe() + second.getRe(), 0);

    ASSERT_EQ(first + second, expectAdd);
}

TEST(Vanushkin_Dmitry_ComplexNumberTest,
     EqualsFractionalPartOfComplexNumbersNearZero) {
    auto first = ComplexNumber(3.000000000000000000000003,
                               15.0000000000000000000000006);
    auto second = ComplexNumber(3.0000000000000000000000091,
                                15.0000000000000000000000008);

    ASSERT_EQ(first, second);
}
