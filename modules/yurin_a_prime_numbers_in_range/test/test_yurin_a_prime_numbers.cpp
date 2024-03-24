// Copyright 2024 Yurin Andrey

#include <gtest/gtest.h>

#include "include/getting_prime_numbers.h"


TEST(Yurin_Andrey_Getting_Prime_Numbers, InvalidInput) {
    EXPECT_ANY_THROW(GettingPrimeNumbers().getPrimeNumbersInRange(50, 5));
    EXPECT_ANY_THROW(GettingPrimeNumbers().getPrimeNumbersInRange(0, UINT32_MAX));
}

TEST(Yurin_Andrey_Getting_Prime_Numbers, LowerEqUpper) {
    auto x = GettingPrimeNumbers().getPrimeNumbersInRange(0, 0);
    EXPECT_EQ(uint32_t{0}, x.size());

    x = GettingPrimeNumbers().getPrimeNumbersInRange(10, 10);
    EXPECT_EQ(uint32_t{0}, x.size());

    x = GettingPrimeNumbers().getPrimeNumbersInRange(7, 7);
    EXPECT_EQ(uint32_t{1}, x.size());
}

TEST(Yurin_Andrey_Getting_Prime_Numbers, UpperEqOne) {
    auto x = GettingPrimeNumbers().getPrimeNumbersInRange(0, 1);
    EXPECT_EQ(uint32_t{0}, x.size());
}

// Выполняется правильно, но слишком долго =)
//TEST(Yurin_Andrey_Getting_Prime_Numbers, UpperEqMaxUINT32) {
//    std::vector<uint32_t> res{};
//    EXPECT_NO_THROW(res = GettingPrimeNumbers().getPrimeNumbersInRange(UINT32_MAX - 10, UINT32_MAX - 1));
//    auto ans = std::vector<uint32_t>{4294967291};
//
//    EXPECT_EQ(res, ans);
//}

TEST(Yurin_Andrey_Getting_Prime_Numbers, ValidityOfReceivedRange) {
    auto res = GettingPrimeNumbers().getPrimeNumbersInRange(5, 23);
    auto ans = std::vector<uint32_t>{5, 7, 11, 13, 17, 19, 23};
    EXPECT_EQ(res, ans);

    res = GettingPrimeNumbers().getPrimeNumbersInRange(31, 31);
    ans = std::vector<uint32_t>{31};
    EXPECT_EQ(res, ans);

    res = GettingPrimeNumbers().getPrimeNumbersInRange(8, 8);
    ans = std::vector<uint32_t>{};
    EXPECT_EQ(res, ans);
}
