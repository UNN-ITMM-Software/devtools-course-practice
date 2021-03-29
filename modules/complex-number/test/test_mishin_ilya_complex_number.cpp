// Copyright 2021 Mishin Ilya

#include <gtest/gtest.h>

#include <iostream>

#include "include/complex_number.h"

TEST(Mishin_Ilya_ComplexNumberTest, testSequentialOperationsSub) {
    ComplexNumber compx1(1, 1);
    ComplexNumber compx2(1, 1);
    ComplexNumber compx3(2, 2);
    ComplexNumber compx4(4, 4);

    ASSERT_EQ(compx1, compx4 - compx2 - compx3);
}

TEST(Mishin_Ilya_ComplexNumberTest, testSequentialOperationsMult) {
    ComplexNumber compx1(-12, 12);
    ComplexNumber compx2(1, 1);
    ComplexNumber compx3(2, 2);
    ComplexNumber compx4(3, 3);

    ASSERT_EQ(compx1, compx2 * compx3 * compx4);
}

TEST(Mishin_Ilya_ComplexNumberTest, testSequentialOperationsDiv) {
    double re = 1.0/3.0;
    double im = -1.0/3.0;
    ComplexNumber compx1(re, im);
    ComplexNumber compx2(2, 2);
    ComplexNumber compx3(3, 3);
    ComplexNumber compx4(4, 4);

    ASSERT_EQ(compx1, compx4 / compx3 / compx2);
}
