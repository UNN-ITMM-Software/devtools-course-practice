// Copyright 2024 Nedelin Dmitry

#ifndef MODULES_NEDELIN_D_BOOK_DISCOUNT_H_
#define MODULES_NEDELIN_D_BOOK_DISCOUNT_H_

#include <vector>
#include <algorithm>
#include <numeric>

class HarryPotterBooks {
public:
    double calculateTotalPrice(std::vector<int> books);

    const double bookPrice = 8.0;
    const std::vector<double> discounts = { 0.0, 0.0, 0.05, 0.1, 0.2, 0.25 };
};

#endif  // MODULES_NEDELIN_D_BOOK_DISCOUNT_H_
