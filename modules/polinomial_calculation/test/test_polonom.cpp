// Copyright 2021 Gapon Andrey
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/Polinom.h"

TEST(Poly, can_create_polinom_with_vars_and_base) {
    std::vector<std::string> var;
    var.push_back("x");
    ASSERT_NO_THROW(Polinom p(var, 20));
}

TEST(Poly, throws_when_create_polinom_with_zero_base) {
    std::vector<std::string> var;
    var.push_back("x");
    ASSERT_ANY_THROW(Polinom p(var, 0));
}

TEST(Poly, can_construct_from_string) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    ASSERT_NO_THROW(
        Polinom p("10*x^5*y^1*z^4+7*x^4*y^2*z^1+12*x^3+7*z^2+7-13*x^7*y^1*z^3",
        var, 20));
}

TEST(Poly, can_construct_from_string_NO2) {
    std::vector<std::string> var;
    var.push_back("x");

    ASSERT_NO_THROW(
        Polinom p("7+x", var, 20));
}

TEST(Poly, throws_when_incorrect_string_given) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    ASSERT_ANY_THROW(Polinom p("12*x+", var, 20));
}

TEST(Poly, throws_when_incorrect_vars_given) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    ASSERT_ANY_THROW(Polinom p("4*x*y+7*y", var, 20));
}

TEST(Poly, throws_when_incorrect_vars_given_NO2) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    ASSERT_ANY_THROW(Polinom p("12+6*x^5*z^3+4*y^3-3-13*x^5*z^3-7", var, 20));
}


TEST(Poly, is_equal_working_correctly) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("15*x+7*y", var, 20);
    Polinom p2("7*y+15*x", var, 20);

    EXPECT_TRUE(p1 == p2);
}

TEST(Poly, is_equal_working_correctly_NO2) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("12 + 6 * x^5 * z^3 + 4* y ^3 -3-13*x^5*z^3 - 7", var, 20);
    Polinom p2("12+6*x^5*z^3+4*y^3-3-13*x^5*z^3-7", var, 20);

    EXPECT_EQ(p1, p2);
}

TEST(Poly, is_not_equal_working_correctly) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("15*x+7*y", var, 20);
    Polinom p2("-7*y+15*x", var, 20);

    EXPECT_TRUE(p1 != p2);
}

TEST(Poly, can_cast_similar_monoms) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p("12+6*x^5*z^3+4*y^3-3-13*x^5*z^3", var, 20);

    Polinom res("9+4*y^3-7*x^5*z^3", var, 20);

    EXPECT_EQ(res, p);
}

TEST(Poly, can_copy) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p("15*x+7*y", var, 20);
    Polinom p2 = p;

    EXPECT_EQ(p2, p);
}

TEST(Poly, sum_gives_correct_answer) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("7*x*y^2+4", var, 20);
    Polinom p2("-3*x*y^2-4", var, 20);

    Polinom res("4*x*y^2", var, 20);

    EXPECT_EQ(res, p1 + p2);
}

TEST(Poly, sum_gives_correct_answer_NO2) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("6*x^2+3*x^3+20*x^5*y^3*z^10-7", var, 20);
    Polinom p2("-12*x^2+3*y*z+4", var, 20);

    Polinom res("-6*x^2+3*x^3+3*y*z+20*x^5*y^3*z^10-3", var, 20);

    EXPECT_EQ(res, p1 + p2);
}

TEST(Poly, sum_gives_correct_answer_NO3) {
    std::vector<std::string> var;
    var.push_back("x");
    var.push_back("y");
    var.push_back("z");

    Polinom p1("-12*x^2+3*y*z+4", var, 20);
    Polinom p2("6*x^2+3*x^3+20*x^5*y^3*z^10-7", var, 20);

    Polinom res("-6*x^2+3*x^3+3*y*z+20*x^5*y^3*z^10-3", var, 20);

    EXPECT_EQ(res, p1 + p2);
}


TEST(Poly, diff_gives_correct_answer) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("-12*a^2+3*b*c+4", var, 20);
    Polinom p2("6*a^2+3*a^3+20*a^5*b^3*c^10-7", var, 20);

    Polinom res("-18*a^2-3*a^3+3*b*c-20*a^5*b^3*c^10+11", var, 20);

    EXPECT_EQ(res, p1 - p2);
}

TEST(Poly, diff_gives_correct_answer_NO2) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("6*a^2+3*a^3+20*a^5*b^3*c^10-7", var, 20);
    Polinom p2("-12*a^2+3*b*c+4", var, 20);

    Polinom res("18*a^2+3*a^3-3*b*c+20*a^5*b^3*c^10-11", var, 20);

    EXPECT_EQ(res, p1 - p2);
}

TEST(Poly, mult_gives_correct_answer) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("-12*a^2+3*b*c+4", var, 20);
    Polinom p2("8*a^2+9*b^3+7", var, 20);

    Polinom res(
        "-96*a^4-108*a^2*b^3-52*a^2+24*a^2*b*c+27*b^4*c+21*b*c+36*b^3+28",
        var, 20);

    Polinom p3 = p1 * p2;

    EXPECT_EQ(res, p3);
}

TEST(Poly, mult_with_num_gives_correct_answer) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p("-12*a^2+3*b*c+4", var, 20);

    Polinom res("36*a^2-9*b*c-12", var, 20);

    Polinom p3 = p * -3;

    EXPECT_EQ(res, p3);
}

TEST(Poly, sum_throws_when_base_is_different) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("-12*a^2+3*b*c+4", var, 10);
    Polinom p2("6*a^2+3*a^3+20*a^5*b^3*c^10-7", var, 20);

    ASSERT_ANY_THROW(p1 + p2);
}

TEST(Poly, diff_throws_when_base_is_different) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("-12*a^2+3*b*c+4", var, 10);
    Polinom p2("6*a^2+3*a^3+20*a^5*b^3*c^10-7", var, 20);

    ASSERT_ANY_THROW(p1 - p2);
}

TEST(Poly, mul_throws_when_base_is_different) {
    std::vector<std::string> var;
    var.push_back("a");
    var.push_back("b");
    var.push_back("c");

    Polinom p1("-12*a^2+3*b*c+4", var, 10);
    Polinom p2("6*a^2+3*a^3+20*a^5*b^3*c^10-7", var, 20);

    ASSERT_ANY_THROW(p1 * p2);
}
