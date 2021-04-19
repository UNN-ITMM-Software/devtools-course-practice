// Copyright 2021 Denis Nikolaev

#include <gtest/gtest.h>
#include <iostream>
#include <tuple>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <limits>
#include "include/complex_number.h"

TEST(Nikolaev_Denis_ComplexNumberTest, Can_Use_List) {
    // initialization
    ComplexNumber n1(17.0, 3.0);
    ComplexNumber n2(9.0, 1.0);
    ComplexNumber n3(3.0, 4.0);
    std::list <ComplexNumber> ls;
    ls.push_back(n1);
    ls.push_back(n2);
    ls.push_back(n3);

    ASSERT_EQ(n1, *ls.begin());
}

TEST(Nikolaev_Denis_ComplexNumberTest, Vector_Complex_Summ) {
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(2.0, 4.0);

    std::complex<double> c(1.0, 2.0);
    std::complex<double> d(2.0, 4.0);

    std::vector<ComplexNumber> vec1 = {a, b};
    std::vector<std::complex<double>> vec2 = {c, d};

    ComplexNumber sum1;
    std::complex<double> sum2(0.0, 0.0);

    for (int i = 0; i < static_cast<int>(vec1.size()); i++) {
        sum1 = sum1 + vec1[i];
        sum2 = sum2 + vec2[i];
    }

    ASSERT_DOUBLE_EQ(sum1.getRe(), static_cast<double>(sum2.real()));
    ASSERT_DOUBLE_EQ(sum1.getIm(), static_cast<double>(sum2.imag()));
}

TEST(Nikolaev_Denis_ComplexNumberTest, Can_Substract) {
    ComplexNumber a(3.0, 5.0);
    ComplexNumber b(2.0, 7.0);
    ComplexNumber c(17.0, 19.0);

    ComplexNumber res1(12.0, 7.0);
    ComplexNumber res2 = c - a - b;

    ASSERT_EQ(res2.getRe(), res1.getRe());
    ASSERT_EQ(res2.getIm(), res1.getIm());
}
