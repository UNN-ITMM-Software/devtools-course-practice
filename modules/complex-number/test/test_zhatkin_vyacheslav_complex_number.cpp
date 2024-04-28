// Copyright 2024 Zhatkin Vyacheslav

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestDefaultConstructor) {
    ASSERT_NO_THROW(ComplexNumber());
    ComplexNumber c;
    EXPECT_EQ(c.getRe(), 0.0);
    EXPECT_EQ(c.getIm(), 0.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestParameterizedConstructor) {
    ASSERT_NO_THROW(ComplexNumber(3.0, 4.0));
    ComplexNumber cn1(3.0, 4.0);
    ASSERT_EQ(cn1.getRe(), 3.0);
    ASSERT_EQ(cn1.getIm(), 4.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestCopyConstructor) {
    ComplexNumber cn1(8.0, 7.0);
    ASSERT_NO_THROW(ComplexNumber(ComplexNumber(8.0, 7.0)));
    ComplexNumber cn2(cn1);
    ASSERT_EQ(cn2.getRe(), 8.0);
    ASSERT_EQ(cn2.getIm(), 7.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestAssignmentOperator) {
    ComplexNumber cn1(2.0, 5.0);
    ComplexNumber cn2;
    ASSERT_NO_THROW(cn2 = cn1);
    ASSERT_EQ(cn2.getRe(), 2.0);
    ASSERT_EQ(cn2.getIm(), 5.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestSumOperator) {
    ComplexNumber cn1(2.0, 5.0);
    ComplexNumber cn2(3.0, 4.0);
    ComplexNumber sum = cn1 + cn2;
    ASSERT_NO_THROW(cn1 + cn2);
    EXPECT_EQ(sum.getRe(), 5.0);
    EXPECT_EQ(sum.getIm(), 9.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestSubtractionOperator) {
    ComplexNumber cn1(4.0, 5.0);
    ComplexNumber cn2(3.0, 4.0);
    ASSERT_NO_THROW(cn1 - cn2);
    ComplexNumber diff = cn1 - cn2;
    EXPECT_EQ(diff.getRe(), 1.0);
    EXPECT_EQ(diff.getIm(), 1.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestMultiplicationOperator) {
    ComplexNumber cn1(3.0, 4.0);
    ComplexNumber cn2(1.0, 2.0);
    ASSERT_NO_THROW(cn1 * cn2);
    ComplexNumber prod = cn1 * cn2;
    EXPECT_EQ(prod.getRe(), -5.0);
    EXPECT_EQ(prod.getIm(), 10.0);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestDivisionOperator) {
    ComplexNumber cn1(3.0, 4.0);
    ComplexNumber cn2(1.0, 2.0);
    ASSERT_NO_THROW(cn1 / cn2);
    ComplexNumber cn3;
    EXPECT_THROW(cn1 / cn3, std::string);
}

TEST(Zhatkin_Vyacheslav_ComplexNumberTest, TestEqualityAndInequality) {
    ComplexNumber cn1(6.0, 4.0);
    ComplexNumber cn2(5.0, 8.0);
    ComplexNumber cn3(6.0, 4.0);
    EXPECT_TRUE(cn1 == cn3);
    EXPECT_FALSE(cn1 == cn2);
    EXPECT_FALSE(cn1 != cn3);
    EXPECT_TRUE(cn1 != cn2);
}
