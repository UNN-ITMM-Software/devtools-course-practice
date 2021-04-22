// Copyright 2021 Chernyh Daria

#include <gtest/gtest.h>

#include <vector>

#include "include/prime_numbers.h"

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_one_number) {
  int a = 5;
  PrimeNumber pn(a, a);

  ASSERT_EQ(1, pn.Get_n());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_intrval) {
  int a = 2;
  int b = 4;
  PrimeNumber pn(a, b);
  int size = b - a + 1;

  ASSERT_EQ(size, pn.Get_n());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Not_empty_constructor_interval) {
  int a = 2;
  int b = 4;
  PrimeNumber pn(a, b);
  bool res = pn.Get_primes().empty();

  ASSERT_EQ(0, res);
}

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_copy) {
  PrimeNumber pn_tmp(3, 4);
  PrimeNumber pn(pn_tmp);

  ASSERT_EQ(pn_tmp.Get_n(), pn.Get_n());
  ASSERT_EQ(pn_tmp.Get_primes(), pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_find_primes1) {
  int a = 2;
  int b = 5;
  // 2 3 4 5
  std::vector<int> res = { 2, 3, 5 };
  PrimeNumber pn(a, b);
  pn.FindPrimes();

  ASSERT_EQ(res, pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_find_primes2) {
  int a = 10;
  int b = 15;
  // 10 11 12 13 14 15
  std::vector<int> res = { 11, 13 };
  PrimeNumber pn(a, b);
  pn.FindPrimes();

  ASSERT_EQ(res, pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_not_find_primes) {
  int a = 4;
  // 4
  PrimeNumber pn(a, a);
  pn.FindPrimes();
  bool res = pn.Get_primes().empty();

  ASSERT_TRUE(res);
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_print_primes) {
  int a = 3;
  int b = 6;
  // 3 4 5 6
  PrimeNumber pn(a, b);
  pn.FindPrimes();

  ASSERT_NO_THROW(pn.PrintPrimes());
}
