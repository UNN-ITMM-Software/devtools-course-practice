// Copyright 2021 Tyurmina Alexandra

#ifndef MODULES_BOOK_DISCOUNT_INCLUDE_CALCULATE_PRICE_H_
#define MODULES_BOOK_DISCOUNT_INCLUDE_CALCULATE_PRICE_H_

#include <array>

class CalculatePrice {
 private:
  std::array<int, 5> basket_;
  double DiscountCalculate(const int book);

 public:
  CalculatePrice(int book1, int book2,
    int book3, int book4, int book5);

  double TotalSum();
};

#endif  // MODULES_BOOK_DISCOUNT_INCLUDE_CALCULATE_PRICE_H_
