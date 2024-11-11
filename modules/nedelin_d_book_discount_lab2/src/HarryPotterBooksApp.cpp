// Copyright 2024 Smirnov Pavel
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/HarryPotterBooksApp.h"
#include "include/HarryPotterBooks.h"


std::string HarryPotterBooksApp::calculatePrice(
    double price, const std::vector<int>& books) {
    HarryPotterBooks hpBooks(price, books);
    double totalPrice = hpBooks.calculateTotalPrice();
    std::stringstream ss;
    ss << "Total price: " << totalPrice;
    return ss.str();
}

std::string HarryPotterBooksApp::run(int argc, char* argv[]) {
    std::vector<int> books;
    double price;
    if (argc < 7) {
return "Not enough values. Please provide 6 numbers for the book price, counts";
    }
    for (int i = 1; i < 7; ++i) {
        if (i == 1) {
            price = std::stoi(argv[i]);
            continue;
        }
        books.push_back(std::stoi(argv[i]));
    }
    return calculatePrice(price, books);
}
