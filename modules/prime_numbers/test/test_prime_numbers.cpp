// Copyright 2021 Chernyh Daria

#include <gtest/gtest.h>

#include "include/prime_numbers.h"

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_default) {
  PrimeNumber pn;

  ASSERT_EQ(0, pn.Get_n());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_rand) {
  int size = 4;
  PrimeNumber pn(size);

  ASSERT_EQ(size, pn.Get_n());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Not_empty_constructor_rand) {
  int size = 4;
  PrimeNumber pn(4);
  bool res = pn.Get_primes().empty();

  ASSERT_TRUE(!res);
}

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_intrval) {
  int start = 2;
  int count = 4;
  PrimeNumber pn(start, count);

  ASSERT_EQ(count, pn.Get_n());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Not_empty_constructor_interval) {
  int start = 2;
  int count = 4;
  PrimeNumber pn(start, count);
  bool res = pn.Get_primes().empty();

  ASSERT_EQ(0, res);
}

TEST(Chernyh_Daria_PrimeNumberTEST, Constructor_copy) {
  PrimeNumber pn_tmp(3);
  PrimeNumber pn(pn_tmp);
	
  ASSERT_EQ(pn_tmp.Get_n(), pn.Get_n());
  ASSERT_EQ(pn_tmp.Get_primes(), pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_find_primes1) {
  int start = 2;
  int count = 4;
  // 2 3 4 5 
  std::vector<int> res = { 2, 3, 5 };
  PrimeNumber pn(start, count); 
  pn.FindPrimes();
  
  ASSERT_EQ(res, pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_find_primes2) {
  int start = 10;
  int count = 5;
  int h = 3;
  // 10 13 16 19 22 25
  std::vector<int> res = { 13, 19 };
  PrimeNumber pn(start, count, h);
  pn.FindPrimes();
	
  ASSERT_EQ(res, pn.Get_primes());
}

TEST(Chernyh_Daria_PrimeNumberTEST, Can_not_find_primes) {
  int start = 4;
  int count = 4;
  int h = 2;
  // 4 6 8 10 
  PrimeNumber pn(start, count, h);
  pn.FindPrimes();
  bool res = pn.Get_primes().empty();

  ASSERT_TRUE(res);
}
