// Copyright 2021 Chernyh Daria

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_

#include <vector>

class PrimeNumber {
 private:
    int n;
    std::vector<int> primes;
 public:
    PrimeNumber(int a, int b);
    PrimeNumber(const PrimeNumber& pn);
    ~PrimeNumber() = default;
    void FindPrimes();
    void PrintPrimes();
    std::vector<int> Get_primes() const;
    int Get_n() const;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
