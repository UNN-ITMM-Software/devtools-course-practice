// Copyright 2021 Schekotilova Julia
#include <gtest/gtest.h>

#include "include/mortgage.h"

TEST(mortagage_calculator, can_set_cost) {
  int res = 1000000;
  int cost = 0;
  int downPayment = 0;
  int creditTerm = 0;
  double interestRate = 0;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.setCost(res);

  ASSERT_EQ(res, mortgg.getCost());
}

TEST(mortagage_calculator, can_set_downPayment) {
  int res = 1000000;
  int cost = 0;
  int downPayment = 0;
  int creditTerm = 0;
  double interestRate = 0;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.setDownPayment(res);

  ASSERT_EQ(res, mortgg.getDownPayment());
}

TEST(mortagage_calculator, can_set_creditTerm) {
  int res = 1000000;
  int cost = 0;
  int downPayment = 0;
  int creditTerm = 0;
  double interestRate = 0;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.setCreditTerm(res);

  ASSERT_EQ(res, mortgg.getCreditTerm());
}

TEST(mortagage_calculator, can_set_interestRate) {
  int res = 10;
  int cost = 0;
  int downPayment = 0;
  int creditTerm = 0;
  double interestRate = 0;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.setInterestRate(res);

  ASSERT_EQ(res, mortgg.getInterestRate());
}

TEST(mortagage_calculator, can_get_totalFee) {
  int res = 3872038;
  int cost = 2000000;
  int downPayment = 0;
  int creditTerm = 10;
  double interestRate = 15;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.calc();

  ASSERT_EQ(res, mortgg.getTotalFee());
}

TEST(mortagage_calculator, can_get_monthlyPayment) {
  int res = 32266;
  int cost = 2000000;
  int downPayment = 0;
  int creditTerm = 10;
  double interestRate = 15;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgg.calc();

  ASSERT_EQ(res, mortgg.getMonthlyPayment());
}

TEST(mortagage_calculator, can_get_monthlyRate) {
  double res = 0.0125;
  int cost = 2000000;
  int downPayment = 0;
  int creditTerm = 10;
  double interestRate = 15;
  mortgage mortgg(cost, downPayment, creditTerm, interestRate);

  mortgg.calc();

  ASSERT_DOUBLE_EQ(res, mortgg.getMonthlyRate());
}

TEST(mortagage_calculator, can_create_copy) {
  int cost = 1;
  int downPayment = 1;
  int creditTerm = 1;
  double interestRate = 1;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgage mortgg_(mortgg);

  ASSERT_NO_THROW(mortgg_.getCost());
  ASSERT_NO_THROW(mortgg_.getDownPayment());
  ASSERT_NO_THROW(mortgg_.getCreditTerm());
  ASSERT_NO_THROW(mortgg_.getInterestRate());
}

TEST(mortagage_calculator, copy_working_fine) {
  int cost = 1;
  int downPayment = 1;
  int creditTerm = 1;
  double interestRate = 1;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);
  mortgage mortgg_(mortgg);

  ASSERT_EQ(mortgg.getCost(), mortgg_.getCost());
  ASSERT_EQ(mortgg.getDownPayment(), mortgg_.getDownPayment());
  ASSERT_EQ(mortgg.getCreditTerm(), mortgg_.getCreditTerm());
  ASSERT_EQ(mortgg.getInterestRate(), mortgg_.getInterestRate());
}

TEST(mortagage_calculator, can_calculate_with_zero_numbers) {
  int cost = 0;
  int downPayment = 0;
  int creditTerm = 0;
  double interestRate = 0;

  mortgage mortgg(cost, downPayment, creditTerm, interestRate);

  ASSERT_NO_THROW(mortgg.getTotalFee());
}
