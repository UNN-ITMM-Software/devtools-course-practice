// Copyright 2024 Shubin Mikhail

#include <gtest/gtest.h>

#include <random>

#include "include/CustomNSNumber.hpp"

#define RND_MIN 0
#define RND_MAX 10000

#define DEC 10
#define BIN 2
#define OCT 8
#define HEX 16
#define CUST 20

// Generic tests

TEST(Shubin_Mikhail_NS_Test, CannotCreate_NS_0) {
  EXPECT_ANY_THROW(CustomNSNumber(0, 0));
}

TEST(Shubin_Mikhail_NS_Test, CannotCreate_NS_1) {
  EXPECT_ANY_THROW(CustomNSNumber(0, 1));
}

TEST(Shubin_Mikhail_NS_Test, Cannot_NS_Any_Set_NS_0) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);

  EXPECT_ANY_THROW(ns_var_num.SetNumSys(0));
}

TEST(Shubin_Mikhail_NS_Test, Cannot_NS_Any_Set_NS_1) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);

  EXPECT_ANY_THROW(ns_var_num.SetNumSys(1));
}

TEST(Shubin_Mikhail_NS_Test, Cannot_NS_Any_To_NS_0) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);

  EXPECT_ANY_THROW(ns_var_num.ToNumSys(0));
}

TEST(Shubin_Mikhail_NS_Test, Cannot_NS_Any_To_NS_1) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);

  EXPECT_ANY_THROW(ns_var_num.ToNumSys(1));
}

TEST(Shubin_Mikhail_NS_Test, CannotSum_Different_NS) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num_2, BIN);

  EXPECT_ANY_THROW(ns_dec_num + ns_bin_num);
}

TEST(Shubin_Mikhail_NS_Test, CannotSub_Different_NS) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num_2, BIN);

  EXPECT_ANY_THROW(ns_dec_num - ns_bin_num);
}

TEST(Shubin_Mikhail_NS_Test, CannotMult_Different_NS) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num_2, BIN);

  EXPECT_ANY_THROW(ns_dec_num * ns_bin_num);
}

TEST(Shubin_Mikhail_NS_Test, CanComp_EQ_Different_NS) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_dec_num == ns_bin_num, true);
}

TEST(Shubin_Mikhail_NS_Test, CanComp_NE_Different_NS) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_dec_num != ns_bin_num, false);
}

// DEC tests

TEST(Shubin_Mikhail_NS_Test, CanCreateZero_NS_DEC) {
  number_t _num = 0;
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.IsNegative(), false);
  EXPECT_EQ(ns_dec_num.GetNumSys(), static_cast<size_t>(DEC));
  EXPECT_EQ(static_cast<number_t>(ns_dec_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroBelowNS_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, DEC - 1);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.IsNegative(), false);
  EXPECT_EQ(ns_dec_num.GetNumSys(), static_cast<size_t>(DEC));
  EXPECT_EQ(static_cast<number_t>(ns_dec_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroAboveNS_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(DEC, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.IsNegative(), false);
  EXPECT_EQ(ns_dec_num.GetNumSys(), static_cast<size_t>(DEC));
  for (size_t i = 0; i < ns_dec_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_dec_num[i]),
              static_cast<number_t>(_num % DEC));
    _num /= DEC;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroBelowNS_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, DEC - 1);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.IsNegative(), true);
  EXPECT_EQ(ns_dec_num.GetNumSys(), static_cast<size_t>(DEC));
  EXPECT_EQ(static_cast<number_t>(ns_dec_num[0]), (-_num));
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroAboveNS_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(DEC, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.IsNegative(), true);
  EXPECT_EQ(ns_dec_num.GetNumSys(), static_cast<size_t>(DEC));
  for (size_t i = 0; i < ns_dec_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_dec_num[i]),
              static_cast<number_t>((-_num) % DEC));
    _num /= DEC;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);

  EXPECT_EQ(ns_dec_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_DEC_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_DEC_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, DEC);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_DEC_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);
  CustomNSNumber ns_cust_num = ns_dec_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_DEC_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_dec_num = CustomNSNumber(_num, DEC);
  CustomNSNumber ns_cust_num = ns_dec_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Positive_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 + ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Negative_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 + ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_DiffSign_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 + ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Positive_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 - ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Negative_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 - ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_DiffSign_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 - ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Positive_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 * ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Negative_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 * ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_DiffSign_NS_DEC) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_dec_num_1 = CustomNSNumber(_num_1, DEC);
  CustomNSNumber ns_dec_num_2 = CustomNSNumber(_num_2, DEC);
  CustomNSNumber ns_dec_num_3 = ns_dec_num_1 * ns_dec_num_2;

  EXPECT_EQ((ns_dec_num_3).ToDec(), _num_1 * _num_2);
}

// BIN tests

TEST(Shubin_Mikhail_NS_Test, CanCreateZero_NS_BIN) {
  number_t _num = 0;
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.IsNegative(), false);
  EXPECT_EQ(ns_bin_num.GetNumSys(), static_cast<size_t>(BIN));
  EXPECT_EQ(static_cast<number_t>(ns_bin_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroBelowNS_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, BIN - 1);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.IsNegative(), false);
  EXPECT_EQ(ns_bin_num.GetNumSys(), static_cast<size_t>(BIN));
  EXPECT_EQ(static_cast<number_t>(ns_bin_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroAboveNS_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(BIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.IsNegative(), false);
  EXPECT_EQ(ns_bin_num.GetNumSys(), static_cast<size_t>(BIN));
  for (size_t i = 0; i < ns_bin_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_bin_num[i]),
              static_cast<number_t>(_num % BIN));
    _num /= BIN;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroBelowNS_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, BIN - 1);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.IsNegative(), true);
  EXPECT_EQ(ns_bin_num.GetNumSys(), static_cast<size_t>(BIN));
  EXPECT_EQ(static_cast<number_t>(ns_bin_num[0]), (-_num));
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroAboveNS_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(BIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.IsNegative(), true);
  EXPECT_EQ(ns_bin_num.GetNumSys(), static_cast<size_t>(BIN));
  for (size_t i = 0; i < ns_bin_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_bin_num[i]),
              static_cast<number_t>((-_num) % BIN));
    _num /= BIN;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);

  EXPECT_EQ(ns_bin_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_BIN_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, BIN);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_BIN_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, BIN);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_BIN_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);
  CustomNSNumber ns_cust_num = ns_bin_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_BIN_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_bin_num = CustomNSNumber(_num, BIN);
  CustomNSNumber ns_cust_num = ns_bin_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Positive_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 + ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Negative_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 + ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_DiffSign_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 + ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Positive_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 - ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Negative_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 - ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_DiffSign_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 - ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Positive_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 * ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Negative_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 * ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_DiffSign_NS_BIN) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_bin_num_1 = CustomNSNumber(_num_1, BIN);
  CustomNSNumber ns_bin_num_2 = CustomNSNumber(_num_2, BIN);
  CustomNSNumber ns_bin_num_3 = ns_bin_num_1 * ns_bin_num_2;

  EXPECT_EQ((ns_bin_num_3).ToDec(), _num_1 * _num_2);
}

// OCT tests

TEST(Shubin_Mikhail_NS_Test, CanCreateZero_NS_OCT) {
  number_t _num = 0;
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.IsNegative(), false);
  EXPECT_EQ(ns_oct_num.GetNumSys(), static_cast<size_t>(OCT));
  EXPECT_EQ(static_cast<number_t>(ns_oct_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroBelowNS_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, OCT - 1);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.IsNegative(), false);
  EXPECT_EQ(ns_oct_num.GetNumSys(), static_cast<size_t>(OCT));
  EXPECT_EQ(static_cast<number_t>(ns_oct_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroAboveNS_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(OCT, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.IsNegative(), false);
  EXPECT_EQ(ns_oct_num.GetNumSys(), static_cast<size_t>(OCT));
  for (size_t i = 0; i < ns_oct_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_oct_num[i]),
              static_cast<number_t>(_num % OCT));
    _num /= OCT;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroBelowNS_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, OCT - 1);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.IsNegative(), true);
  EXPECT_EQ(ns_oct_num.GetNumSys(), static_cast<size_t>(OCT));
  EXPECT_EQ(static_cast<number_t>(ns_oct_num[0]), (-_num));
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroAboveNS_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(OCT, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.IsNegative(), true);
  EXPECT_EQ(ns_oct_num.GetNumSys(), static_cast<size_t>(OCT));
  for (size_t i = 0; i < ns_oct_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_oct_num[i]),
              static_cast<number_t>((-_num) % OCT));
    _num /= OCT;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);

  EXPECT_EQ(ns_oct_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_OCT_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, OCT);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_OCT_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, OCT);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_OCT_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);
  CustomNSNumber ns_cust_num = ns_oct_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_OCT_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_oct_num = CustomNSNumber(_num, OCT);
  CustomNSNumber ns_cust_num = ns_oct_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Positive_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 + ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Negative_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 + ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_DiffSign_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 + ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Positive_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 - ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Negative_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 - ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_DiffSign_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 - ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Positive_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 * ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Negative_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 * ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_DiffSign_NS_OCT) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_oct_num_1 = CustomNSNumber(_num_1, OCT);
  CustomNSNumber ns_oct_num_2 = CustomNSNumber(_num_2, OCT);
  CustomNSNumber ns_oct_num_3 = ns_oct_num_1 * ns_oct_num_2;

  EXPECT_EQ((ns_oct_num_3).ToDec(), _num_1 * _num_2);
}

// HEX tests

TEST(Shubin_Mikhail_NS_Test, CanCreateZero_NS_HEX) {
  number_t _num = 0;
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.IsNegative(), false);
  EXPECT_EQ(ns_hex_num.GetNumSys(), static_cast<size_t>(HEX));
  EXPECT_EQ(static_cast<number_t>(ns_hex_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroBelowNS_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, HEX - 1);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.IsNegative(), false);
  EXPECT_EQ(ns_hex_num.GetNumSys(), static_cast<size_t>(HEX));
  EXPECT_EQ(static_cast<number_t>(ns_hex_num[0]), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNonZeroAboveNS_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(HEX, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.IsNegative(), false);
  EXPECT_EQ(ns_hex_num.GetNumSys(), static_cast<size_t>(HEX));
  for (size_t i = 0; i < ns_hex_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_hex_num[i]),
              static_cast<number_t>(_num % HEX));
    _num /= HEX;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroBelowNS_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(1, HEX - 1);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.IsNegative(), true);
  EXPECT_EQ(ns_hex_num.GetNumSys(), static_cast<size_t>(HEX));
  EXPECT_EQ(static_cast<number_t>(ns_hex_num[0]), (-_num));
}

TEST(Shubin_Mikhail_NS_Test, CanCreateNegativeNonZeroAboveNS_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(HEX, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.IsNegative(), true);
  EXPECT_EQ(ns_hex_num.GetNumSys(), static_cast<size_t>(HEX));
  for (size_t i = 0; i < ns_hex_num.GetLength(); i++) {
    EXPECT_EQ(static_cast<number_t>(ns_hex_num[i]),
              static_cast<number_t>((-_num) % HEX));
    _num /= HEX;
  }
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);

  EXPECT_EQ(ns_hex_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_HEX_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, HEX);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_HEX_Set_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_var_num = CustomNSNumber(_num, HEX);
  ns_var_num.SetNumSys(CUST);

  EXPECT_EQ(ns_var_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Positive_NS_HEX_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);
  CustomNSNumber ns_cust_num = ns_hex_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanReturnToDec_Negative_NS_HEX_To_NS_CUST) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num = -number_t_dist(rng);
  CustomNSNumber ns_hex_num = CustomNSNumber(_num, HEX);
  CustomNSNumber ns_cust_num = ns_hex_num.ToNumSys(CUST);

  EXPECT_EQ(ns_cust_num.ToDec(), _num);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Positive_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 + ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_Negative_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 + ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSum_DiffSign_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 + ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 + _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Positive_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 - ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_Negative_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 - ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanSub_DiffSign_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 - ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 - _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Positive_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 * ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_Negative_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = -number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 * ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 * _num_2);
}

TEST(Shubin_Mikhail_NS_Test, CanMult_DiffSign_NS_HEX) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<number_t> number_t_dist(RND_MIN, RND_MAX);

  number_t _num_1 = number_t_dist(rng);
  number_t _num_2 = -number_t_dist(rng);
  CustomNSNumber ns_hex_num_1 = CustomNSNumber(_num_1, HEX);
  CustomNSNumber ns_hex_num_2 = CustomNSNumber(_num_2, HEX);
  CustomNSNumber ns_hex_num_3 = ns_hex_num_1 * ns_hex_num_2;

  EXPECT_EQ((ns_hex_num_3).ToDec(), _num_1 * _num_2);
}
