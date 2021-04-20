// Copyright 2021 Chernyh Daria

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_

#include <vector>
#include<random>

class PrimeNumber {
private:
    int n;
    std::vector<int> primes;
public:
    explicit PrimeNumber(const int size = 0);
    PrimeNumber(int a, int b, int h = 1);
    PrimeNumber(const PrimeNumber& pn);
    ~PrimeNumber() = default;
    PrimeNumber& PrimeNumber::operator=(const PrimeNumber& pn);
    void FindPrimes();
    void PrintPrimes();
    std::vector<int> Get_primes() const;
    int Get_n() const;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_H_
