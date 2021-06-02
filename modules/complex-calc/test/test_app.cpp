// Copyright 2021 Chirkov Roman

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/application.h"
#include "include/complex_number.h"

TEST(Complex_calc_application, can_create_just_app) {
  ASSERT_NO_THROW(Application app);
}

TEST(Complex_calc_application, can_get_help_without_throws_short_form) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "-h"};
  int argc = argv.size();

  ASSERT_NO_THROW(app(argc, &argv[0]));
}

TEST(Complex_calc_application, can_get_help_without_throws_long_form) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "--help"};
  int argc = argv.size();

  ASSERT_NO_THROW(app(argc, &argv[0]));
}

TEST(Complex_calc_application, can_add) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "1.5", "2", "+",
                                   "3.02",         "3"};
  int argc = argv.size();

  std::string exp = "(4.52;5)";
  std::string res = app(argc, &argv[0]);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_subtract) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "1.5", "2", "-",
                                   "3.02",         "3"};
  int argc = argv.size();
  std::string exp = "(-1.52;-1)";
  std::string res = app(argc, &argv[0]);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_multiply) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "1.5", "2", "*",
                                   "3.02",         "3"};
  int argc = argv.size();

  std::string exp = "(-1.47;10.54)";
  std::string res = app(argc, &argv[0]);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, can_divide) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "1.5", "2", "/",
                                   "3.02",         "3"};
  int argc = argv.size();

  std::string exp = "(0.581113;0.0849871)";
  std::string res = app(argc, &argv[0]);

  ASSERT_EQ(exp, res);
}

TEST(Complex_calc_application, cannot_divide_by_zero) {
  Application app;
  std::vector<const char*> argv = {"complex-calc", "1.5", "2", "/", "0", "0"};
  int argc = argv.size();

  app(argc, &argv[0]);

  std::string exp = "ERROR: Can't divide by zero";
  std::string res = app.getError();

  ASSERT_EQ(exp, res);
}
