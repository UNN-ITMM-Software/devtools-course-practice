// Copyright 2024 Смирнов Павел
#ifndef MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKSAPP_H_
#define MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKSAPP_H_

#include <vector>
#include <string>

class HarryPotterBooksApp {
 public:
    std::string run(int argc, char* argv[]);

 private:
    std::string calculatePrice(double price, const std::vector<int>& books);
};

#endif  // MODULES_NEDELIN_D_BOOK_DISCOUNT_LAB2_INCLUDE_HARRYPOTTERBOOKSAPP_H_
