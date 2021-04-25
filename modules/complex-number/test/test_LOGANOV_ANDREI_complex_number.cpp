// Copyright 2021 Loganov Andrei

#include <gtest/gtest.h>
#include <tuple>
#include <map>
#include "include/complex_number.h"

TEST(Loganov_Andrei_ComplexNumberTest, arithmetic_op) {
    // initialization
    ComplexNumber n1(182.0, 17.0);
    ComplexNumber n2(3.0, 10.0);
    ComplexNumber n3(2.0, 2.0);
    ComplexNumber n4(1.0, 1.0);
    // calc
    ComplexNumber op = (n1+n2)*n3/n4;
    ComplexNumber Result(370, 54);
    // Assert
    ASSERT_EQ(op, Result);
}

TEST(Loganov_Andrei_ComplexNumberTest, Can_Use_MAP) {
    // initialization
    ComplexNumber n1(5.0, 4.0);
    ComplexNumber n2(3.0, 10.0);
    std::map<int, ComplexNumber> map1 = {{1, n1}, {2, n2}};
    auto elem = map1[2];
    // Assert
    ASSERT_EQ(elem, n2);
}

typedef testing::TestWithParam<std::tuple<double, double>>
    Loganov_Parametrized;

TEST_P(Loganov_Parametrized, MultByConstPARAM) {
    // initialization
    const double co = 2;
    ComplexNumber numb1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    // calc
    ComplexNumber result(numb1.getRe()*co, numb1.getIm()*co);
    result = result - numb1;
    // Assert
    ASSERT_EQ(result, numb1);
}

INSTANTIATE_TEST_CASE_P(/**/, Loganov_Parametrized, testing::Combine(
  testing::Values(2.0, 1.0),
  testing::Values(1.0, 8.0)
));
