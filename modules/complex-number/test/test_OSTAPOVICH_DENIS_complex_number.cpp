// Copyright 2021 Ostapovich Denis

#include <gtest/gtest.h>
#include "include/complex_number.h"

const double epsilon = std::numeric_limits<double>::epsilon();

TEST(Ostapovich_Denis_ComplexNumberTest, Throw_On_Division_By_Zero) {
    ComplexNumber a(1, 2);
    ComplexNumber b(0, 0);
    ASSERT_ANY_THROW(a / b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, Equality_Operator_Not_Zero) {
    ComplexNumber a(2, 1);
    ComplexNumber b(2, 1);
    ASSERT_TRUE(a == b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, Equality_Operator_Approximately_Zero) {
    ComplexNumber a(0, 0);
    ComplexNumber b(-epsilon, epsilon);
    ASSERT_TRUE(a != b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, No_Throw_On_Addition) {
    ComplexNumber a(5, 6);
    ComplexNumber b(1, 2);
    ASSERT_NO_THROW(a + b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, No_Throw_On_Subtraction) {
    ComplexNumber a(0, 1);
    ComplexNumber b(1, 2);
    ASSERT_NO_THROW(a - b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, No_Throw_On_Multiplication) {
    ComplexNumber a(8, 9);
    ComplexNumber b(10, 11);
    ASSERT_NO_THROW(a * b);
}

TEST(Ostapovich_Denis_ComplexNumberTest, No_Throw_On_Division_By_Not_Zero) {
    ComplexNumber a(7, 6);
    ComplexNumber b(5, 4);
    ASSERT_NO_THROW(a / b);
}
