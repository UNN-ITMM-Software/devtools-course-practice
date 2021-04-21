// Copyright 2021 Ludina Daria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ludina_Daria_ComplexNumberTest, Division) {
  // Arrange
  double re1 = 1.1, im1 = 8.4;
  double re2 = 3.4, im2 = 6.3;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);

  // Act
  ComplexNumber res((re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2),
    (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2));

  // Assert
  ASSERT_EQ(res, z1 / z2);
}

TEST(Ludina_Daria_ComplexNumberTest, Check_Commutability_Sum) {
  // Arrange
  double re1 = 1.0, im1 = 2.0;
  double re2 = 0.4, im2 = 3.0;

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);

  ComplexNumber res1 = z1 + z2;
  ComplexNumber res2 = z2 + z1;

  // Assert
  ASSERT_EQ(res2, res1);
}

TEST(Ludina_Daria_ComplexNumberTest, Check_Associativity_Sum) {
  // Arrange
  double re1 = 1.0, im1 = 2.0;
  double re2 = 2.0, im2 = 3.0;
  double re3 = 3.0, im3 = 4.0;

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber z3(re3, im3);

  ComplexNumber res1 = (z1 + z2) + z3;
  ComplexNumber res2 = z1 + (z2 + z3);

  // Assert
  ASSERT_EQ(res1, res2);
}
