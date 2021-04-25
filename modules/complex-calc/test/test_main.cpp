// Copyright 2021 Kolesin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesin_Andrey_ComplexNumberTest, can_create_zero) {
    ASSERT_NO_THROW(Complex comp);
}

TEST(Kolesin_Andrey_ComplexNumberTest, can_get_real) {
    Complex comp(3.1);

    ASSERT_DOUBLE_EQ(3.1, comp.getReal());
}

TEST(Kolesin_Andrey_ComplexNumberTest, can_get_image) {
    Complex comp(1.2, -5.3);

    ASSERT_DOUBLE_EQ(-5.3, comp.getImag());
}
TEST(Kolesin_Andrey_ComplexNumberTest, can_print) {
    Complex comp(1.2, 5.3);
    std::stringstream buffer;
    std::string expected = "1.2+5.3i";

    buffer << comp;

    ASSERT_EQ(expected, buffer.str());
}
TEST(Kolesin_Andrey_ComplexNumberTest, can_print_neg) {
    Complex comp(1.2, -5.3);
    std::stringstream buffer;
    std::string expected = "1.2-5.3i";

    buffer << comp;

    ASSERT_EQ(expected, buffer.str());
}
TEST(Kolesin_Andrey_ComplexNumberTest, can_get_as_string) {
    Complex comp(1.9, -5.9);
    std::string expected = "1.9-5.9i";

    ASSERT_EQ(expected, comp.getAsStr());
}

TEST(Kolesin_Andrey_ComplexNumberTest, equality_operator) {
    Complex comp1(1.2, -5.3);
    Complex comp2(1.2, -5.3);

    ASSERT_EQ(comp1, comp2);
}

TEST(Kolesin_Andrey_ComplexNumberTest, not_equality_operator) {
    Complex comp1(1.2, -5.3);
    Complex comp2(1.2, 5.3);

    ASSERT_NE(comp1, comp2);
}

TEST(Kolesin_Andrey_ComplexNumberTest, addition_operator) {
    Complex comp1(1.2, -5.3);
    Complex comp2(1.8, 6);
    Complex expected(3, 0.7);

    ASSERT_EQ(expected, comp1 + comp2);
}

TEST(Kolesin_Andrey_ComplexNumberTest, subtraction_operator) {
    Complex comp1(1.1, -5.4);
    Complex comp2(1.8, 1);
    Complex expected(-0.7, -6.4);

    ASSERT_EQ(expected, comp1 - comp2);
}
TEST(Kolesin_Andrey_ComplexNumberTest, multiplication_operator) {
    Complex comp1(1.9, -5.3);
    Complex comp2(-2, 1);
    Complex expected(1.5, 12.5);

    ASSERT_EQ(expected, comp1 * comp2);
}
TEST(Kolesin_Andrey_ComplexNumberTest, devision_operator) {
    Complex comp1(1.9, -5.3);
    Complex comp2(-2, 1);
    Complex expected(-1.82, 1.74);
    ASSERT_EQ(expected, comp1 / comp2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
