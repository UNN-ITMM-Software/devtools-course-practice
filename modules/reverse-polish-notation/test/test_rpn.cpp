// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include <string>

#include "include/rpn.h"

TEST(RPN, can_create_notation_without_parameters) {
  ASSERT_NO_THROW(RPN rpn());
}

TEST(RPN, can_create_notation_with_empty_string) {
  ASSERT_NO_THROW(RPN rpn(""));
}

TEST(RPN, notation_without_parameters_is_empty_string) {
  RPN rpn("");
  std::string exp = "";
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, empty_string_and_void_constructors_are_equal) {
  RPN rpn_string("");
  RPN rpn_void;

  std::string exp = rpn_string.getLine();
  std::string res = rpn_void.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, can_create_notation_with_one_digit_number) {
  ASSERT_NO_THROW(RPN rpn("8"));
}

TEST(RPN, can_create_notation_with_one_variable) {
  ASSERT_NO_THROW(RPN rpn("v"));
}

TEST(RPN, can_create_notation_with_just_number) {
  std::string exp = "18923";
  RPN rpn("18923");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, addition_of_two_numbers) {
  std::string exp = "123 321 +";
  RPN rpn("123+321");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, cannot_create_notation_with_operator_at_the_beginning) {
  ASSERT_ANY_THROW(RPN rpn("/451*7+9"));
}

TEST(RPN, bunch_of_additions_and_subtitutions) {
  std::string exp = "45 89 + 21 + 75 - 4 + 987 -";
  RPN rpn("45+89+21-75+4-987");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, bunch_of_multiplications_and_divisions) {
  std::string exp = "12 46 * 72 / 4 * 9 /";
  RPN rpn("12*46/72*4/9");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, priority_of_operations_is_considered) {
  std::string exp = "1 2 3 * + 7 45 / 4 * +";
  RPN rpn("1+2*3+7/45*4");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, parentheses_are_considered) {
  std::string exp = "7 11 + 15 13 3 - / /";
  RPN rpn("(7+11)/(15/(13-3))");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, parentheses_can_be_redundant) {
  std::string exp = "523";
  RPN rpn("(((((523)))))");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, amount_of_left_parantheses_is_less) {
  ASSERT_ANY_THROW(RPN rpn("((46)))))"));
}

TEST(RPN, amount_of_right_parantheses_is_less) {
  ASSERT_ANY_THROW(RPN rpn("((((((12))"));
}

TEST(RPN, only_right_parantheses) { ASSERT_ANY_THROW(RPN rpn("1))")); }

TEST(RPN, cannot_support_unsupported_operator) {
  ASSERT_ANY_THROW(RPN rpn("12+46-2_42"));
}

TEST(RPN, pow_is_available) {
  std::string exp = "7 11 + 15 4 / ^";
  RPN rpn("(7+11)^(15/4)");
  std::string res = rpn.getLine();

  ASSERT_EQ(exp, res);
}

TEST(RPN, pow_priority_is_four) {
  RPN rpn;

  int exp = 4;
  int res = rpn.priority('^');

  ASSERT_EQ(exp, res);
}

TEST(RPN, unsupported_operator_priority) {
  char op = '&';
  RPN rpn;

  ASSERT_ANY_THROW(rpn.priority(op));
}
