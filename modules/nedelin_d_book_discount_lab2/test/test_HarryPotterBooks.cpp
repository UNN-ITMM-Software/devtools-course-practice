// Copyright 2024 Nedelin Dmitry

#include <gtest/gtest.h>
#include "include/HarryPotterBooks.h"

TEST(Nedelin_HarryPotterBooksTest, SingleBook) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 1, 0, 0, 0, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 8.0);
}

TEST(Nedelin_HarryPotterBooksTest, TwoDifferentBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 1, 1, 0, 0, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 2 * 8.0 * 0.95);
}

TEST(Nedelin_HarryPotterBooksTest, ThreeDifferentBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 1, 1, 1, 0, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 8.0 * 3 * 0.9);
}

TEST(Nedelin_HarryPotterBooksTest, FourDifferentBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 1, 1, 1, 1, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 8.0 * 4 * 0.8);
}

TEST(Nedelin_HarryPotterBooksTest, FullSetOfFiveBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 1, 1, 1, 1, 1 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 8.0 * 5 * 0.75);
}

TEST(Nedelin_HarryPotterBooksTest, ComplexBasket) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 2, 2, 2, 1, 1 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 51.6);
}

TEST(Nedelin_HarryPotterBooksTest, NoBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 0, 0, 0, 0, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 0.0);
}

TEST(Nedelin_HarryPotterBooksTest, MultipleSameBooks) {
    HarryPotterBooks hpBooks;
    std::vector<int> books = { 3, 0, 0, 0, 0 };
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(books), 8.0 * 3);
}
