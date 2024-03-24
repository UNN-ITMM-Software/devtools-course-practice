// Copyright 2024 Kiselev Igor

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(KiselevIgorTests, Check_Constructors) {
    ComplexNumber cn0 = ComplexNumber();
    ComplexNumber cn1 = ComplexNumber(1, 2);
    ComplexNumber cn2 = ComplexNumber(cn1);
    EXPECT_DOUBLE_EQ(cn0.getRe(), 0);
    EXPECT_DOUBLE_EQ(cn0.getIm(), 0);
    EXPECT_DOUBLE_EQ(cn1.getRe(), 1);
    EXPECT_DOUBLE_EQ(cn1.getIm(), 2);
    EXPECT_DOUBLE_EQ(cn2.getRe(), 1);
    EXPECT_DOUBLE_EQ(cn2.getIm(), 2);
}

TEST(KiselevIgorTests, Check_Copy_Constructor_Pointer) {
    ComplexNumber cn1 = ComplexNumber(1, 2);
    ComplexNumber cn2 = ComplexNumber(cn1);
    EXPECT_FALSE(&cn1 == &cn2);
}

TEST(KiselevIgorTests, Check_Setters) {
    ComplexNumber cn1 = ComplexNumber(1, 2);
    cn1.setRe(2);
    cn1.setIm(1);
    EXPECT_DOUBLE_EQ(cn1.getRe(), 2);
    EXPECT_DOUBLE_EQ(cn1.getIm(), 1);
}

TEST(KiselevIgorTests, Check_Assign_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber();
    cn2 = cn1;
    EXPECT_DOUBLE_EQ(cn2.getRe(), 2);
    EXPECT_DOUBLE_EQ(cn2.getIm(), 2);
}

TEST(KiselevIgorTests, Check_Assign_Operator_Pointer) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber();
    cn2 = cn1;
    EXPECT_FALSE(&cn2 == &cn1);
}

TEST(KiselevIgorTests, Check_Sum_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(1, 1);
    ComplexNumber cn2 = ComplexNumber(2, 2);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn1 + cn2;
    EXPECT_DOUBLE_EQ(cn3.getRe(), 3);
    EXPECT_DOUBLE_EQ(cn3.getIm(), 3);
}

TEST(KiselevIgorTests, Check_Diference_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(1, 1);
    ComplexNumber cn2 = ComplexNumber(2, 2);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn2 - cn1;
    EXPECT_DOUBLE_EQ(cn3.getRe(), 1);
    EXPECT_DOUBLE_EQ(cn3.getIm(), 1);
}

TEST(KiselevIgorTests, Check_Multiply_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber(4, 3);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn2 * cn1;
    EXPECT_DOUBLE_EQ(cn3.getRe(), 2);
    EXPECT_DOUBLE_EQ(cn3.getIm(), 14);
}

TEST(KiselevIgorTests, Check_Divide_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber(4, 3);
    ComplexNumber cn3 = ComplexNumber();
    cn3 = cn2 / cn1;
    EXPECT_DOUBLE_EQ(cn3.getRe(), 1.75);
    EXPECT_DOUBLE_EQ(cn3.getIm(), -0.25);
}

TEST(KiselevIgorTests, Check_Equal_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber(2, 2);
    ComplexNumber cn3 = ComplexNumber(2, 3);
    EXPECT_TRUE(cn1 == cn2);
    EXPECT_FALSE(cn1 == cn3);
}

TEST(KiselevIgorTests, Check_Not_Equal_Operator_Res) {
    ComplexNumber cn1 = ComplexNumber(2, 2);
    ComplexNumber cn2 = ComplexNumber(2, 3);
    ComplexNumber cn3 = ComplexNumber(2, 2);
    EXPECT_TRUE(cn1 != cn2);
    EXPECT_FALSE(cn1 != cn3);
}
