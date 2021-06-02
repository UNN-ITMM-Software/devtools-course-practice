// Copyright 2021 Kolesnikov Gleb

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/prime_numbers_application.h"

std::string PrimeNumbersApplication::getHelp(const std::string& appname) {
        return  "This is an application that finds prime numbers in range\n" \
        "Please provide arguments in the following format:\n" +
        appname + " <left_border> <right_borber> "
        "Where all arguments are positive integer numbers more than 1.";
}

std::string PrimeNumbersApplication::operator()(int argc, const char** argv) {
    std::vector<int> primevec;
    int a;
    int b;

    if (argc == 1) {
        return getHelp(argv[0]);
    }
    try {
        if (argc != 3) {
            throw  std::runtime_error("ERROR: Should be 2 arguments.\n");
        }
        a = parseArgument(argv[1]);
        b = parseArgument(argv[2]);
        if (a <= 1 || b <= 1 || b < a) {
            throw std::runtime_error("ERROR: Wrong format.\n");
        }
    }
    catch (std::exception& exp) {
        return exp.what();
    }
    std::ostringstream oss;
    PrimeNumber pn(a, b);
    pn.FindPrimes();
    primevec = pn.Get_primes();
    if (!primevec.empty()) {
        std::copy(primevec.begin(), primevec.end() - 1,
            std::ostream_iterator<int>(oss, " "));
        oss << primevec.back();
    }
    return oss.str();
}
bool PrimeNumbersApplication::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
int PrimeNumbersApplication::parseArgument(const char* arg) {
    if (!checkArgument(arg)) {
        throw std::runtime_error("ERROR: Wrong format.\n");
    }
    return std::stoi(arg);
}
