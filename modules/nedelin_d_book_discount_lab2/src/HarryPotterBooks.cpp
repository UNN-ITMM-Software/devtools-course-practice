// Copyright 2024 Nedelin Dmitry

#include "include/HarryPotterBooks.h"

HarryPotterBooks::HarryPotterBooks(const std::vector<int>& book_counts)
    : books(book_counts) {
    if (books.empty()) {
        throw std::invalid_argument("Empty vector provided in constructor");
    }
}

double HarryPotterBooks::calculateTotalPrice() {
    std::vector<int> remainingBooks = books;
    double totalPrice = 0.0;

    while (true) {
        int distinctBooks = 0;
        for (int book : remainingBooks) {
            if (book > 0) {
                distinctBooks++;
            }
        }
        if (distinctBooks == 0) break;

        double discount = 1.0;
        switch (distinctBooks) {
        case 2:
            discount = 0.95;
            break;
        case 3:
            discount = 0.90;
            break;
        case 4:
            discount = 0.80;
            break;
        case 5:
            discount = 0.75;
            break;
        }

        totalPrice += distinctBooks * bookPrice * discount;

        for (size_t i = 0; i < remainingBooks.size(); ++i) {
            if (remainingBooks[i] > 0) {
                remainingBooks[i]--;
            }
        }
    }

    return totalPrice;
}

std::vector<int> HarryPotterBooks::getBooks() const {
    return books;
}

void HarryPotterBooks::setBooks(const std::vector<int>& book_counts) {
    if (book_counts.empty()) {
        throw std::invalid_argument("Empty vector provided in setter");
    }
    books = book_counts;
}
