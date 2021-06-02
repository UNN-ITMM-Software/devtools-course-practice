// Copyright 2021 Vlasov Maksim

#include "include/qsorter.h"

#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

#include "include/qsort.h"

namespace QSort {

std::string Sorter::operator()(int argc, const char* argv[],
                               int* retcode) const {
    if (retcode)
        *retcode = 1;
    if (argc <= 1)
        return help(argv[0]);
    std::vector<double> numbers;
    numbers.reserve(argc - 1);
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        try {
            double num = std::stod(arg);
            numbers.push_back(num);
        } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    }
    try {
        Sort(&numbers, 0, numbers.size() - 1);
    } catch (std::runtime_error& e) {
        return "[ERROR] Unable to sort. " + std::string(e.what());
    }
    std::ostringstream str;
    str << numbers[0];
    for (size_t i = 1; i < numbers.size(); i++)
        str << ' ' << numbers[i];
    if (retcode)
        *retcode = 0;
    return str.str();
}

std::string Sorter::help(const std::string& filename) const {
    return "Usage: " + filename + " NUMBERS...\nExample: " + filename +
           " 6 -4.3 47 1.1 2 -5 -3.87";
}

}  // namespace QSort
