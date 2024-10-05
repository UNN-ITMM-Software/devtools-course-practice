// Copyright 2024 Nedelin Dmitry
#include "include/HarryPotterBooks.h"

double HarryPotterBooks::calculateTotalPrice(std::vector<int> books) {
    double total = 0.0;

    while (true) {
        int uniqueBooks = std::count_if(books.begin(), books.end(), [](int x) { return x > 0; });

        if (uniqueBooks == 0) {
            break;
        }

        total += uniqueBooks * bookPrice * (1 - discounts[uniqueBooks]);

        for (int i = 0; i < books.size(); ++i) {
            if (books[i] > 0) {
                books[i]--;
            }
        }
    }

    return total;
}
