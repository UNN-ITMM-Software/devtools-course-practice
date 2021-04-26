// Copyright 2021 Kolesin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesin_Andrey_ComplexNumberTest, can_create_zero) {
    ASSERT_NO_THROW(Complex comp);
}

TEST(Kolesin_Andrey_ComplexNumberTest, can_get_real) {
    double expected = 3.1;
    double actual;
    Complex comp(expected);

    actual = comp.getReal();

    ASSERT_DOUBLE_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, can_get_image) {
    double expected = -5.3;
    double actual;
    Complex comp(1.2, expected);

    actual = comp.getImag();

    ASSERT_DOUBLE_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, equality_operator) {
    double re = 1.2;
    double im = -5.3;
    Complex comp1(re, im);
    Complex comp2(re, im);

    bool actual = comp1 == comp2;

    ASSERT_EQ(true, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, not_equality_operator) {
    double re = 1.2;
    double im = -5.3;
    Complex comp1(re, im);
    Complex comp2(re, im);

    bool actual = comp1 != comp2;

    ASSERT_EQ(false, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, addition_operator) {
    Complex comp1(1.2, -5.3);
    Complex comp2(1.8, 6);
    Complex expected(3, 0.7);
    Complex actual;

    actual = comp1 + comp2;

    ASSERT_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, subtraction_operator) {
    Complex comp1(1.1, -5.4);
    Complex comp2(1.8, 1);
    Complex expected(-0.7, -6.4);
    Complex actual;

    actual = comp1 - comp2;

    ASSERT_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, multiplication_operator) {
    Complex comp1(1.9, -5.3);
    Complex comp2(-2, 1);
    Complex expected(1.5, 12.5);
    Complex actual;

    actual = comp1 * comp2;

    ASSERT_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, devision_operator) {
    Complex comp1(1.9, -5.3);
    Complex comp2(-2, 1);
    Complex expected(-1.82, 1.74);
    Complex actual;

    actual = comp1 / comp2;

    ASSERT_EQ(expected, actual);
}

TEST(Kolesin_Andrey_ComplexNumberTest, throw_when_divide_by_zero) {
    Complex comp1(1.9, -5.3);
    Complex comp2(0, 0);

    ASSERT_ANY_THROW(comp1 / comp2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
