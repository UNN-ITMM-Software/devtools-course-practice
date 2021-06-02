// Copyright 2021 Tsvetkov Maxim

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include "include/string_calculator.h"


bool StringCalculator::isNumber(char a) {
    return (a < '9' && a > '0');
}

int StringCalculator::add(const std::string& str) {
    return operation(str, std::plus<int>());
}

int StringCalculator::subtract(const std::string& str) {
    return operation(str, std::minus<int>());
}

int StringCalculator::multiplicate(const std::string& str) {
    return operation(str, std::multiplies<int>());
}

