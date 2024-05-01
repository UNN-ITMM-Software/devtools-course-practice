// Copyright 2024 Yurin Andrey

#ifndef MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_GETTING_PRIME_NUMBERS_H_
#define MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_GETTING_PRIME_NUMBERS_H_

#define LEFT_BORDER_BIGGER "The left bound should be larger than the right one!"
#define RIGHT_BORDER_OVERFLOW "The right border is too big!"

#include <vector>
#include <string>
#include <stdexcept>


class GettingPrimeNumbers {
 private:
    uint32_t _lowerBound;
    uint32_t _upperBound;
    std::vector<bool> _isPrime;

 public:
    std::vector<uint32_t> getPrimeNumbersInRange(
            uint32_t lowerBound, uint32_t upperBound);

 private:
    void validateInputData();
    std::vector<uint32_t> generateListOfPrimeNumbers();
};

#endif  // MODULES_YURIN_A_PRIME_NUMBERS_IN_RANGE_INCLUDE_GETTING_PRIME_NUMBERS_H_
