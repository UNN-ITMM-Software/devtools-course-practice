 // Copyright 2024 Dostavalov Semyon

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dostavalov_Semyon_ComplexNumberTest, DefCon) {
    ComplexNumber a;
    ASSERT_EQ(0.0, a.getRe());
    ASSERT_EQ(0.0, a.getIm());
}

TEST(Dostavalov_Semyon_ComplexNumberTest, ParCon) {
    ComplexNumber a(3.0, 4.0);
    ASSERT_EQ(3.0, a.getRe());
    ASSERT_EQ(4.0, a.getIm());
}

TEST(Dostavalov_Semyon_ComplexNumberTest, Addition) {
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumber c = a + b;
    ASSERT_EQ(4.0, c.getRe());
    ASSERT_EQ(6.0, c.getIm());
}

TEST(Dostavalov_Semyon_ComplexNumberTest, Subtraction) {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.0, 3.0);
    ComplexNumber c = a - b;
    ASSERT_EQ(3.0, c.getRe());
    ASSERT_EQ(4.0, c.getIm());
}

TEST(Dostavalov_Semyon_ComplexNumberTest, Equality) {
    ComplexNumber a(2.0, 3.0);
    ComplexNumber b(2.0, 3.0);
    ASSERT_TRUE(a == b);
}

TEST(Dostavalov_Semyon_ComplexNumberTest, DivisionByZero) {
    ComplexNumber a(4.0, 3.0);
    ComplexNumber b(0.0, 0.0);

    ASSERT_ANY_THROW(a / b);
}
// Test for conjugate method
TEST(Dostavalov_Semyon_ComplexNumberTest, Conjugate) {
    ComplexNumber a(3.0, 4.0);
    ComplexNumber conjugate = a.conjugate();
    ASSERT_EQ(3.0, conjugate.getRe());
    ASSERT_EQ(-4.0, conjugate.getIm());
}

// Test for modulus method
TEST(Dostavalov_Semyon_ComplexNumberTest, Modulus) {
    ComplexNumber a(3.0, 4.0);
    double modulus = a.modulus();
    ASSERT_EQ(5.0, modulus);
}

// Test for argument method
TEST(Dostavalov_Semyon_ComplexNumberTest, Argument) {
    ComplexNumber a(1.0, 1.0);
    double argument = a.argument();
    ASSERT_NEAR(0.7854, argument, 0.0001); // approximately equal to pi/4
}
