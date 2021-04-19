// Copyright 2021 Yurin Stanislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

#define eps 0.00001

TEST(Yurin_Stanislav_ComplexNumberTest_Zero_Devision,
     Devision_With_Denominator_Re_Not_EQ_Zero_No_Throw_Exception) {
    double re1 = 5.4;
    double im1 = 3.2;

    ComplexNumber z1(re1, im1);


    double re2 = 2.0;
    double im2 = 0.0;

    ComplexNumber z2(re2, im2);


    ASSERT_NO_THROW(z1/z2);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Zero_Devision,
     Devision_With_Denominator_Im_Not_EQ_Zero_No_Throw_Exception) {
    double re1 = 5.4;
    double im1 = 3.2;

    ComplexNumber z1(re1, im1);


    double re2 = 0.0;
    double im2 = 1.0;

    ComplexNumber z2(re2, im2);


    ASSERT_NO_THROW(z1/z2);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Zero_Devision,
     Zero_Devision_Throw_Exception) {
    double re1 = 5.4;
    double im1 = 3.2;

    ComplexNumber z1(re1, im1);


    double re2 = 0.0;
    double im2 = 0.0;

    ComplexNumber z2(re2, im2);


    ASSERT_ANY_THROW(z1/z2);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Reverse_Operations, Sum_Than_Diff) {
    double re1 = -14.2;
    double im1 = 3.11;

    ComplexNumber z1(re1, im1);


    double re2 = 13.4;
    double im2 = 14.21;

    ComplexNumber z2(re2, im2);


    ComplexNumber z3 = z1 + z2;
    ComplexNumber z3_and_z1_diff = z3 - z1;
    ComplexNumber z3_and_z2_diff = z3 - z2;


    ASSERT_NEAR(z3_and_z1_diff.getRe(), z2.getRe(), eps);
    ASSERT_NEAR(z3_and_z1_diff.getIm(), z2.getIm(), eps);
    ASSERT_NEAR(z3_and_z2_diff.getRe(), z1.getRe(), eps);
    ASSERT_NEAR(z3_and_z2_diff.getIm(), z1.getIm(), eps);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Reverse_Operations, Diff_Than_Sum) {
    double re1 = 54.2;
    double im1 = -0.11;

    ComplexNumber z1(re1, im1);


    double re2 = -83.4;
    double im2 = 5.1;

    ComplexNumber z2(re2, im2);


    ComplexNumber z1_and_z2_diff = z1 - z2;
    ComplexNumber z2_and_z1_diff = z2 - z1;


    ASSERT_NEAR((z1_and_z2_diff + z2).getRe(), z1.getRe(), eps);
    ASSERT_NEAR((z1_and_z2_diff + z2).getIm(), z1.getIm(), eps);
    ASSERT_NEAR((z2_and_z1_diff + z1).getRe(), z2.getRe(), eps);
    ASSERT_NEAR((z2_and_z1_diff + z1).getIm(), z2.getIm(), eps);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Reverse_Operations, Mult_Than_Dev) {
    double re1 = -14.2;
    double im1 = 3.11;

    ComplexNumber z1(re1, im1);


    double re2 = 13.4;
    double im2 = 14.21;

    ComplexNumber z2(re2, im2);


    ComplexNumber z3 = z1 * z2;
    ComplexNumber z3_and_z1_dev = z3 / z1;
    ComplexNumber z3_and_z2_dev = z3 / z2;


    ASSERT_NEAR(z3_and_z1_dev.getRe(), z2.getRe(), eps);
    ASSERT_NEAR(z3_and_z1_dev.getIm(), z2.getIm(), eps);
    ASSERT_NEAR(z3_and_z2_dev.getRe(), z1.getRe(), eps);
    ASSERT_NEAR(z3_and_z2_dev.getIm(), z1.getIm(), eps);
}

TEST(Yurin_Stanislav_ComplexNumberTest_Reverse_Operations, Dev_Than_Mult) {
    double re1 = 0.0;
    double im1 = -13.84;

    ComplexNumber z1(re1, im1);


    double re2 = -19.1;
    double im2 = 2.77;

    ComplexNumber z2(re2, im2);


    ComplexNumber z1_and_z2_dev = z1 / z2;
    ComplexNumber z2_and_z1_dev = z2 / z1;


    ASSERT_NEAR((z1_and_z2_dev * z2).getRe(), z1.getRe(), eps);
    ASSERT_NEAR((z1_and_z2_dev * z2).getIm(), z1.getIm(), eps);
    ASSERT_NEAR((z2_and_z1_dev * z1).getRe(), z2.getRe(), eps);
    ASSERT_NEAR((z2_and_z1_dev * z1).getIm(), z2.getIm(), eps);
}
