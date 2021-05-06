// Copyright 2021 Tsvetkov Maksim
#include <gtest/gtest.h>
#include <tuple>
#include <algorithm>
#include <cmath>
#include "include/complex_number.h"

TEST(Tsvetkov_Maksim_ComplexNumberTest, Pow_of_imaginary_unit) {
    // Arrange
    ComplexNumber z(0, 2.0);
    ComplexNumber res(0, -8.0);
    ComplexNumber res1(z);

    // Act
    for ( int i = 0; i < 2; i++ )
       res1 = res1*z;
    // Assert
    ASSERT_EQ(res, res1);
}

TEST(Tsvetkov_Maksim_ComplexNumberTest, Use_of_lamda) {
    // Arrange
    ComplexNumber a(3.56, 1.12);
    ComplexNumber expRes(8.1, 6.55);
    ComplexNumber actRes;
    auto lambda = [](ComplexNumber& x){
        ComplexNumber b(4.54, 5.43);
        return x + b;
    };

    // Act
    actRes = lambda(a);

    // Assert
    ASSERT_EQ(expRes, actRes);
}

TEST(Tsvetkov_Maksim_ComplexNumberTest, Multiply_by_an_object) {
    // Arrange
    ComplexNumber a(4.0, 2.0);
    ComplexNumber res;

    // Act
    res = a * ComplexNumber(1.0, 1.0);

    // Assert
    ASSERT_EQ(res, ComplexNumber(2.0, 6.0));
}
