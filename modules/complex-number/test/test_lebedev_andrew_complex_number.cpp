// Copyright 2021 Lebedev Andrew

#include <gtest/gtest.h>

#include <iostream>

#include "include/complex_number.h"

TEST(Lebedev_Andrew_ComplexNumberTest, copiedObjectHasItsOwnMemory) {
     ComplexNumber x(3, 5);
     ComplexNumber y(x);
     x.setRe(9);
     x.setRe(12);

     ASSERT_NE(x, y);
}

TEST(Lebedev_Andrew_ComplexNumberTest, testMultipleAssignment) {
     ComplexNumber z1(-5, 6);
     ComplexNumber z2(23, 0);
     ComplexNumber z3(4, 8);
     double re, im;
     re = 4;
     im = 8;
     z1 = z2 = z3;

     ASSERT_EQ(z3, z1);
     ASSERT_EQ(z3, z2);
     ASSERT_EQ(z1, z2);
     ASSERT_EQ(re, z1.getRe());
     ASSERT_EQ(im, z1.getIm());
}

TEST(Lebedev_Andrew_ComplexNumberTest, testSubAfterMult) {
     ComplexNumber z1(1, 1);
     ComplexNumber z2(3, 4);
     ComplexNumber z3(2, 1);
     ComplexNumber z4(-3, 6);

     ASSERT_EQ(z4, z1 * z2 - z3);
}

TEST(Lebedev_Andrew_ComplexNumberTest, testMultAfterSub) {
     ComplexNumber z1(1, 1);
     ComplexNumber z2(3, 4);
     ComplexNumber z3(2, 1);
     ComplexNumber z4(-1, -10);

     ASSERT_EQ(z4, z1 - z2 * z3);
}

TEST(Lebedev_Andrew_ComplexNumberTest, testMultIsCommutative) {
     ComplexNumber z1(7, 8);
     ComplexNumber z2(3, 4);

     ASSERT_EQ(z1 * z2, z2 * z1);
}

TEST(Lebedev_Andrew_ComplexNumberTest, testMultByZeroGivesZero) {
     ComplexNumber z1(7, 8);
     ComplexNumber z2(4, 2);
     ComplexNumber z3(0, 0);

     ASSERT_EQ(z1 * z3, z2 * z3);
}
