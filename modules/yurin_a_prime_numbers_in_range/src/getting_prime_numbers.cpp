// Copyright 2024 Yurin Andrey

#include "include/getting_prime_numbers.h"

#include <algorithm>


std::vector<uint32_t> GettingPrimeNumbers::getPrimeNumbersInRange(
        uint32_t lowerBound, uint32_t upperBound) {
    _lowerBound = lowerBound;
    _upperBound = upperBound;
    validateInputData();

    if (_isPrime.size() > upperBound) {
        return generateListOfPrimeNumbers();
    }

    std::vector<bool> tempVector(upperBound - _isPrime.size() + 1, true);
    _isPrime.insert(_isPrime.end(), tempVector.begin(), tempVector.end());

    if (_isPrime.size() > 1) {
        _isPrime[0] = _isPrime[1] = false;
    }

    for (uint64_t p = 2; p * p <= upperBound; ++p) {
        if (_isPrime[p]) {
            for (uint64_t i = p * p; i <= upperBound; i += p) {
                _isPrime[i] = false;
            }
        }
    }

    return generateListOfPrimeNumbers();
}

void GettingPrimeNumbers::validateInputData() {
    if (_lowerBound > _upperBound) {
        throw std::string(
                "The left bound should be larger than the right one!");
    }

    if (_upperBound == UINT32_MAX) {
        throw std::string("The right border is too big!");
    }
}

std::vector<uint32_t> GettingPrimeNumbers::generateListOfPrimeNumbers() {
    std::vector<uint32_t> primeNumbers{};
    uint32_t startP = std::max(_lowerBound, uint32_t{2});
    for (uint64_t p = startP; p <= _upperBound; ++p) {
        if (_isPrime[p]) {
            primeNumbers.push_back(p);
        }
    }

    return primeNumbers;
}
