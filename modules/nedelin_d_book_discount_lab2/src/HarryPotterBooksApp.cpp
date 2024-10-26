#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/HarryPotterBooksApp.h"
#include "include/HarryPotterBooks.h"


std::string HarryPotterBooksApp::calculatePrice(const std::vector<int>& books) {
    HarryPotterBooks hpBooks(books);
    double totalPrice = hpBooks.calculateTotalPrice();
    std::stringstream ss;
    ss << "Total price: " << totalPrice;
    return ss.str();
}

std::string HarryPotterBooksApp::run(int argc, char* argv[]) {
    std::vector<int> books;
    if (argc < 6) {
        return "Not enough arguments. Please provide 5 numbers for the book counts.";
    }
    for (int i = 1; i < 6; ++i) {
        books.push_back(std::stoi(argv[i]));
    }
    return calculatePrice(books);
}
