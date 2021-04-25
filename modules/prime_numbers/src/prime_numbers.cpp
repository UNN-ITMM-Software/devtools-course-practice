// Copyright 2021 Chernyh Daria

#include<iostream>
#include<vector>

#include "include/prime_numbers.h"

PrimeNumber::PrimeNumber(const PrimeNumber& pn) : n(pn.n),
primes(pn.primes) {}

PrimeNumber::PrimeNumber(int a, int b) {
  n = b - a + 1;
  primes.resize(n, 0);
  for (int i = 0; i < n; i++) {
    primes[i] = a;
    a++;
  }
}

void PrimeNumber::FindPrimes() {
  std::vector<int> primes_tmp;
  for (int i = 0; i < n; i++) {
    int j = 2;
    while (primes[i] % j != 0) {
      j++;
    }
    if (primes[i] == j) {
      primes_tmp.push_back(j);
    }
  }
  primes = primes_tmp;
  n = static_cast<int>(primes_tmp.size());
}

void PrimeNumber::PrintPrimes() {
  for (int i = 0; i < n; i++) {
    std::cout << primes[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> PrimeNumber::Get_primes() const {
  return primes;
}

int PrimeNumber::Get_n() const {
  return n;
}
