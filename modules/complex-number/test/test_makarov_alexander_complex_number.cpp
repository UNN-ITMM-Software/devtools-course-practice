// Copyright 2021 Makarov Alexander

#include <math.h>
#include <gtest/gtest.h>
#include <limits>


#include "include/complex_number.h"

TEST(Makarov_Alexander_ComlexNumberTest, Infty_Mlp) {
    double real = 1.0;
    double img = 1.0;
    ComplexNumber z1(real, img);
    ComplexNumber z2(0.0, std::numeric_limits<double>::infinity());
    ASSERT_EQ(-std::numeric_limits<double>::infinity(), (z1 * z2).getRe());
    ASSERT_EQ(std::numeric_limits<double>::infinity(), (z1 * z2).getIm());
}

TEST(Makarov_Alexander_ComlexNumberTest, Is_i_Square_Minus_One) {
    double real = 0.0;
    double img = 1.0;
    ComplexNumber z1(real, img);
    ComplexNumber result = z1 * z1;
    ASSERT_DOUBLE_EQ(-1.0, result.getRe());
    ASSERT_DOUBLE_EQ(0.0, result.getIm());
}

TEST(Makarov_Alexander_ComlexNumberTest, Infty_Sum) {
    double real = std::numeric_limits<double>::infinity();
    double img = -std::numeric_limits<double>::infinity();
    ComplexNumber z(real, img);
    ComplexNumber result = z + z;
    ASSERT_DOUBLE_EQ(std::numeric_limits<double>::infinity(), result.getRe());
    ASSERT_DOUBLE_EQ(-std::numeric_limits<double>::infinity(), result.getIm());
}

TEST(Makarov_Alexander_ComlexNumberTest, Infty_Diff) {
    double real = std::numeric_limits<double>::infinity();
    double img = -std::numeric_limits<double>::infinity();
    ComplexNumber z(real, img);
    ComplexNumber result = z - z;
    ASSERT_TRUE(std::isnan(result.getRe()));
    ASSERT_TRUE(std::isnan(result.getIm()));
}
