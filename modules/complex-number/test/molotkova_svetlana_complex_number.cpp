// Copyright 2021 Molotkova Svetlana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Molotkova_Svetlana_ComplexNumberTesting, Pow) {
    ComplexNumber a1(2.0, 3.0);
    ComplexNumber a2(a1);
    ComplexNumber rres = a1*a2;
    ComplexNumber eres(-5.0, 12.0);
    ASSERT_EQ(rres.getRe(), eres.getRe());
    ASSERT_EQ(rres.getIm(), eres.getIm());
}
TEST(Molotkova_Svetlana_ComplexNumberTesting, Multiply_by_number) {
    ComplexNumber a(2.0, -7.0);
    ComplexNumber b1(3.0, 0);
    double b2 = 3.0;
    ComplexNumber rres = a*b1;
    ComplexNumber eres(a.getRe()*b2, a.getIm()*b2);
    ASSERT_EQ(rres, eres);
}

TEST(Molotkova_Svetlana_ComplexNumberTesting, No_Exeption) {
    ComplexNumber a1(1.0, 9.0);
    ComplexNumber a2(7.0, 1.0);
    ComplexNumber a3(0.32, 1.24);
    ASSERT_NO_THROW(a1 / a2);
    ASSERT_EQ(a1 / a2, a3);
}
