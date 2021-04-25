// Copyright 2021 Alibekov Murad

#include <gtest/gtest.h>

#include <tuple>
#include <utility>
#include <memory>

#include "include/complex_number.h"

typedef testing::TestWithParam<std::tuple<double, double> >
        Alibekov_Murad_ComplexNumberTest_2_Parametrized;

typedef testing::TestWithParam<std::tuple<double, double, double, double> >
        Alibekov_Murad_ComplexNumberTest_4_Parametrized;

TEST_P(Alibekov_Murad_ComplexNumberTest_2_Parametrized,
        Can_Set_Values_To_ComplexNumber_Pointer) {
    double re = std::get<0>(GetParam());
    double im = std::get<1>(GetParam());
    ComplexNumber z;
    std::unique_ptr<ComplexNumber> z_ptr(new ComplexNumber());

    z.setRe(re);
    z.setIm(im);
    z_ptr->setRe(re);
    z_ptr->setIm(im);

    ASSERT_EQ(z, *z_ptr);
}

TEST_P(Alibekov_Murad_ComplexNumberTest_4_Parametrized,
        Can_Use_Pair_Of_Complex_Numbers) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    ComplexNumber z_1(re_1, im_1);

    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber z_2(re_2, im_2);

    std::pair<ComplexNumber, ComplexNumber> pair_of_complex_numbers(z_1, z_2);

    ASSERT_EQ(z_1, pair_of_complex_numbers.first);
    ASSERT_EQ(z_2, pair_of_complex_numbers.second);
}

TEST_P(Alibekov_Murad_ComplexNumberTest_4_Parametrized,
        Addition_With_Using_ComplexNumber_Pointer) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    ComplexNumber z_1(re_1, im_1);
    std::unique_ptr<ComplexNumber> z_ptr(new ComplexNumber(re_1, im_1));

    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber z_2(re_2, im_2);

    ASSERT_EQ(z_1 + z_2, z_ptr->operator+(z_2));
}

TEST_P(Alibekov_Murad_ComplexNumberTest_4_Parametrized,
        Substraction_With_Using_ComplexNumber_Pointer) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    ComplexNumber z_1(re_1, im_1);
    std::unique_ptr<ComplexNumber> z_ptr(new ComplexNumber(re_1, im_1));

    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber z_2(re_2, im_2);

    ASSERT_EQ(z_1 - z_2, z_ptr->operator-(z_2));
}

TEST_P(Alibekov_Murad_ComplexNumberTest_4_Parametrized,
        Multiplication_With_Using_ComplexNumber_Pointer) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    ComplexNumber z_1(re_1, im_1);
    std::unique_ptr<ComplexNumber> z_ptr(new ComplexNumber(re_1, im_1));

    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber z_2(re_2, im_2);

    ASSERT_EQ(z_1 * z_2, z_ptr->operator*(z_2));
}

INSTANTIATE_TEST_CASE_P(/**/, Alibekov_Murad_ComplexNumberTest_2_Parametrized,
        testing::Combine(
  testing::Values(1.0, 2.0),
  testing::Values(3.0, 4.0)
));

INSTANTIATE_TEST_CASE_P(/**/, Alibekov_Murad_ComplexNumberTest_4_Parametrized,
        testing::Values(
  std::make_tuple(1.1, 2.9, 3.6, 4.2),
  std::make_tuple(1.0, 0.0, 0.0, 1.0)
));
