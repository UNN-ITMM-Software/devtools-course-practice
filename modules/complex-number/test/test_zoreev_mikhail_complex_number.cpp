// Copyright 2021 Zoreev Mikhail

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Zoreev_Mikhail_ComplexNumberTest, Changes_In_Copy_Not_Affect_Original) {
    double re_1 = 4.5;
    double im_1 = 6.0;
    double re_2 = 1.0;
    ComplexNumber number_original(re_1, im_1);

    ComplexNumber number_copy(number_original);
    number_copy.setRe(re_2);

    ASSERT_EQ(number_original.getRe(), re_1);
    ASSERT_EQ(number_original.getIm(), im_1);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
        Zoreev_Mikhail_ComplexNumberTest_Parametrized;
TEST_P(Zoreev_Mikhail_ComplexNumberTest_Parametrized,
       Equality_Is_Opposite_To_Inequality) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber number_1(re_1, im_1);
    ComplexNumber number_2(re_2, im_2);

    bool is_equal = number_1 == number_2;
    bool is_not_equal = number_1 != number_2;

    ASSERT_NE(is_equal, is_not_equal);
}

TEST_P(Zoreev_Mikhail_ComplexNumberTest_Parametrized,
       Substraction_After_Summ_Give_Original) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber number_1(re_1, im_1);
    ComplexNumber number_2(re_2, im_2);

    ComplexNumber result = number_1 + number_2;
    result = result - number_2;

    ASSERT_EQ(result, number_1);
}

INSTANTIATE_TEST_CASE_P(/**/, Zoreev_Mikhail_ComplexNumberTest_Parametrized,
    testing::Values(
  std::make_tuple(5.0, 3.0, 5.0, 3.0),
  std::make_tuple(0.0, 7.0, 4.0, 8.0),
  std::make_tuple(2.0, 6.0, 7.0, 1.0),
  std::make_tuple(3.5, 3.5, 3.5, 3.5)
));
