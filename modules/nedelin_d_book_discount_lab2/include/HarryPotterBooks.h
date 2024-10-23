// Copyright 2024 Nedelin Dmitry

#ifndef MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKS_H_
#define MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKS_H_

#include <vector>
#include <stdexcept>

class HarryPotterBooks {
    std::vector<int> books;

 public:
    const double bookPrice = 8.0;

    explicit HarryPotterBooks(const std::vector<int>& book_counts);

    std::vector<int> getBooks() const;
    void setBooks(const std::vector<int>& book_counts);

    double calculateTotalPrice();
};

#endif  // MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKS_H_
