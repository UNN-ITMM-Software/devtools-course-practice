// Copyright 2024 Filatov Maxim

#include <gtest/gtest.h>
#include <tuple>
#include <utility>
#include <climits>
#include "include/complex_number.h"

class Filatov_Maxim_ComplexNumberTestWithFirstPairValues
: public ::testing::TestWithParam<std::pair<double, double>> {};
class Filatov_Maxim_ComplexNumberTestWithSecondPairValues
: public ::testing::TestWithParam<std::pair<double, double>> {};
class Filatov_Maxim_ComplexNumberTestWithFirstTupleValues
: public ::testing::TestWithParam<std::tuple<double,
double, double, double>> {};
class Filatov_Maxim_ComplexNumberTestWithSecondTupleValues
: public ::testing::TestWithParam<std::tuple<double,
double, double, double>> {};

INSTANTIATE_TEST_CASE_P(
    TestComplexNumbersWithFirstPairValues,
    Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
    ::testing::Values(
        std::make_pair(INT_MIN, INT_MIN),
        std::make_pair(-1.0, -1.0),
        std::make_pair(.0, .0),
        std::make_pair(1.0, 1.0),
        std::make_pair(INT_MAX, INT_MAX)
    )
);

INSTANTIATE_TEST_CASE_P(
    TestComplexNumbersWithSecondPairValues,
    Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
    ::testing::Values(
        std::make_pair(INT_MAX, INT_MIN),
        std::make_pair(-1.4, -1.5),
        std::make_pair(.4, .5),
        std::make_pair(1.4, 1.5),
        std::make_pair(INT_MAX, INT_MIN)
    )
);

INSTANTIATE_TEST_CASE_P(
    TestComplexNumbersWithFirstTupleValues,
    Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
    ::testing::Values(
        std::make_tuple(.1, .2, 2.22, 2.0),
        std::make_tuple(1.11, 1.0, 2.22, 2.0),
        std::make_tuple(.1, .2, .3, .4),
        std::make_tuple(-1.0, -1.0, 1.0, 1.0),
        std::make_tuple(-1.0, -1.0, .1, .2)
    )
);

INSTANTIATE_TEST_CASE_P(
    TestComplexNumbersWithSecondTupleValues,
    Filatov_Maxim_ComplexNumberTestWithSecondTupleValues,
    ::testing::Values(
        std::make_tuple(.1, .2, .0, .0),
        std::make_tuple(.0, .0, .0, .0)
    )
);

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Can_Create_Complex_Numbers) {
    double re = GetParam().first;
    double im = GetParam().second;

    ASSERT_NO_THROW(ComplexNumber(re, im));
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Correct_Create_Complex_Numbers) {
    double re = GetParam().first;
    double im = GetParam().second;

    ComplexNumber z(re, im);

    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Can_Sum_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

  ComplexNumber z1(re1, im1), z2(re2, im2);

  ASSERT_NO_THROW(z1 + z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Correct_Sum_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

  ComplexNumber z1(re1, im1), z2(re2, im2);
  ComplexNumber z = z1 + z2;

  EXPECT_DOUBLE_EQ(re1 + re2, z.getRe());
  EXPECT_DOUBLE_EQ(im1 + im2, z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Can_Subtraction_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 - z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Correct_Subtraction_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 - z2;

    EXPECT_DOUBLE_EQ(re1 - re2, z.getRe());
    EXPECT_DOUBLE_EQ(im1 - im2, z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Can_Multiply_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 * z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Correct_Multiply_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 * z2;

    EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_DOUBLE_EQ(re1 * im2 + im1 * re2, z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Can_Devide_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 / z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondTupleValues,
Test_Cant_Devide_By_Zero_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_ANY_THROW(z1 / z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstTupleValues,
Test_Correct_Devide_Complex_Numbers) {
    double re1 = std::get<0>(GetParam());
    double im1 = std::get<1>(GetParam());
    double re2 = std::get<2>(GetParam());
    double im2 = std::get<3>(GetParam());

    ComplexNumber z1(re1, im1), z2(re2, im2);
    ComplexNumber z = z1 / z2;

    EXPECT_DOUBLE_EQ((re1*re2 + im1*im2) / (re2*re2 + im2*im2), z.getRe());
    EXPECT_DOUBLE_EQ((im1*re2 - re1*im2) / (re2*re2 + im2*im2), z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Can_Equal_True_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().second;
    double re2 = GetParam().first;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 == z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Correct_Equal_True_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().second;
    double re2 = GetParam().first;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    EXPECT_TRUE(z1 == z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Can_Equal_False_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().first;
    double re2 = GetParam().second;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 == z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Correct_Equal_False_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().first;
    double re2 = GetParam().second;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    EXPECT_FALSE(z1 == z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Can_Unequal_True_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().first;
    double re2 = GetParam().second;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 != z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Correct_Unequal_True_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().first;
    double re2 = GetParam().second;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    EXPECT_TRUE(z1 != z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Can_Unqual_False_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().second;
    double re2 = GetParam().first;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    ASSERT_NO_THROW(z1 != z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithSecondPairValues,
Test_Correct_Unqual_False_Complex_Numbers) {
    double re1 = GetParam().first;
    double im1 = GetParam().second;
    double re2 = GetParam().first;
    double im2 = GetParam().second;

    ComplexNumber z1(re1, im1), z2(re2, im2);

    EXPECT_FALSE(z1 != z2);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Can_Get_Params_Complex_Numbers) {
    double re = GetParam().first;
    double im = GetParam().second;

    ComplexNumber z(re, im);

    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Correct_Get_Params_Complex_Numbers) {
    double re = GetParam().first;
    double im = GetParam().second;

    ComplexNumber z(re, im);

    EXPECT_DOUBLE_EQ(z.getRe(), GetParam().first);
    EXPECT_DOUBLE_EQ(z.getIm(), GetParam().second);
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Can_Set_Params_Complex_Numbers) {
    ComplexNumber z;

    ASSERT_NO_THROW(z.setRe(GetParam().first));
    ASSERT_NO_THROW(z.setIm(GetParam().second));
}

TEST_P(Filatov_Maxim_ComplexNumberTestWithFirstPairValues,
Test_Correct_Set_Params_Complex_Numbers) {
    ComplexNumber z;

    z.setRe(GetParam().first);
    z.setIm(GetParam().second);

    EXPECT_DOUBLE_EQ(z.getRe(), GetParam().first);
    EXPECT_DOUBLE_EQ(z.getIm(), GetParam().second);
}
