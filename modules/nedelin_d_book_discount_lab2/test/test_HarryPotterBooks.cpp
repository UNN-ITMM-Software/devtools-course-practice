// Copyright 2024 Nedelin Dmitry

#include <gtest/gtest.h>
#include "include/HarryPotterBooks.h"

TEST(Nedelin_HarryPotterBooksTest, ConstructEmptyVector) {
    std::vector<int> empty_books;
    double price_book = 8.0;
    EXPECT_THROW(HarryPotterBooks hpBooks(price_book, empty_books),
        std::invalid_argument);
}

TEST(Nedelin_HarryPotterBooksTest, SetterEmptyVector) {
    std::vector<int> start_books = { 0, 0, 0, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, start_books);
    std::vector<int> empty_books;
    EXPECT_THROW(hpBooks.setBooks(empty_books), std::invalid_argument);
}

TEST(Nedelin_HarryPotterBooksTest, ConstructValidVector) {
    std::vector<int> books = { 1, 2, 3, 4, 5 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_NO_THROW(hpBooks.calculateTotalPrice());
}

TEST(Nedelin_HarryPotterBooksTest, SetBooksWithEmptyVector) {
    std::vector<int> books = { 1, 2, 3, 4, 5 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    std::vector<int> empty_books;
    EXPECT_THROW(hpBooks.setBooks(empty_books), std::invalid_argument);
}

TEST(Nedelin_HarryPotterBooksTest, SetBooksWithValidVector) {
    std::vector<int> books = { 1, 2, 3, 4, 5 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    std::vector<int> books_2 = { 1, 1, 1, 1, 1 };
    hpBooks.setBooks(books_2);
    EXPECT_EQ(hpBooks.getBooks(), books_2);
}

TEST(Nedelin_HarryPotterBooksTest, GetBooksTest) {
    std::vector<int> books = { 1, 2, 3, 4, 5 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_EQ(hpBooks.getBooks(), books);
}

TEST(Nedelin_HarryPotterBooksTest, SingleBook) {
    std::vector<int> books = { 1, 0, 0, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 8.0);
}

TEST(Nedelin_HarryPotterBooksTest, TwoDifferentBooks) {
    std::vector<int> books = { 1, 1, 0, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 2 * 8.0 * 0.95);
}

TEST(Nedelin_HarryPotterBooksTest, ThreeDifferentBooks) {
    std::vector<int> books = { 1, 1, 1, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 8.0 * 3 * 0.9);
}

TEST(Nedelin_HarryPotterBooksTest, FourDifferentBooks) {
    std::vector<int> books = { 1, 1, 1, 1, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 8.0 * 4 * 0.8);
}

TEST(Nedelin_HarryPotterBooksTest, FullSetOfFiveBooks) {
    std::vector<int> books = { 1, 1, 1, 1, 1 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 8.0 * 5 * 0.75);
}

TEST(Nedelin_HarryPotterBooksTest, ComplexBasket) {
    std::vector<int> books = { 2, 2, 2, 1, 1 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 51.6);
}

TEST(Nedelin_HarryPotterBooksTest, NoBooks) {
    std::vector<int> books = { 0, 0, 0, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 0.0);
}

TEST(Nedelin_HarryPotterBooksTest, MultipleSameBooks) {
    std::vector<int> books = { 3, 0, 0, 0, 0 };
    double price_book = 8.0;
    HarryPotterBooks hpBooks(price_book, books);
    EXPECT_DOUBLE_EQ(hpBooks.calculateTotalPrice(), 8.0 * 3);
}
