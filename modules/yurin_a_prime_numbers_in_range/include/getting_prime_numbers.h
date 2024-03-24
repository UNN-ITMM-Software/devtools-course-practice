// Copyright 2024 Yurin Andrey

#ifndef MODULES_GETTING_PRIME_NUMBERS_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_GETTING_PRIME_NUMBERS_INCLUDE_COMPLEX_NUMBER_H_

#include <vector>
#include <string>


class GettingPrimeNumbers {
private:
    uint32_t _lowerBound;
    uint32_t _upperBound;
    std::vector<bool> _isPrime;

public:
    std::vector<uint32_t> getPrimeNumbersInRange(uint32_t lowerBound, uint32_t upperBound);

private:
    void validateInputData();
    std::vector<uint32_t> generateListOfPrimeNumbers();
};

#endif  // MODULES_GETTING_PRIME_NUMBERS_INCLUDE_COMPLEX_NUMBER_H_
