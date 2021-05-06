// Copyright 2021 Tyurmina Alexandra

#include "include/calculate_price.h"

#include <stdio.h>
#include <string>

CalculatePrice::CalculatePrice(int book1, int book2,
  int book3, int book4, int book5) {
  if ((book1 < 0) || (book2 < 0) || (book3 < 0) || (book4 < 0) || (book5 < 0))
    throw std::string("Don't negative numbers");
  basket_ = { {book1, book2, book3, book4, book5} };
}

double CalculatePrice::DiscountCalculate(const int book) {
  double sum = 0.0;
  double price = 8.0;

  switch (book) {
  case 1:
    sum = price;
    break;
  case 2:
    sum = price * book * 0.95;
    break;
  case 3:
    sum = price * book * 0.9;
    break;
  case 4:
    sum = price * book * 0.8;
    break;
  case 5:
    sum = price * book * 0.75;
    break;
  }

  return sum;
}

double CalculatePrice::TotalSum() {
  double sum = 0.0;
  std::array<int, 5> basketbook;

  for (int i = 0; i < 5; i++) {
    basketbook[i] = basket_[i];
  }

  int books = 0;

  for (int i = 0; i < 5; i++) {
    books += basketbook[i];
  }

  while (books) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
      if (basketbook[i]) {
        books--;
        basketbook[i]--;
        count++;
      }
    }
    sum += DiscountCalculate(count);
  }

  return sum;
}
