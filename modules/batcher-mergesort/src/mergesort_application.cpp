// Copyright 2021 Zaitsev Andrey

#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

#include "include/mergesort_application.h"
#include "include/mergesort.h"

std::string MergeSortApplication::help(const std::string& filename) const {
    return "This is a application of odd-even merge sort.\n\n" \
        "Please provide arguments in one of two formats:\nFormat 1:\n$ " +
        filename + " <size_of_vector>\n\n"
        "Format 2:\n$ " + filename + " <elements_of_vector>\n\n"
        "Where <size_of_vector> is one integer positive number, " \
        "equal to the power of two (this is " \
        "size of vector),\n<elements_of_vector> are sequence " \
        "of numbers of a vector (!the count of numbers must be\n" \
        "equal to the power of two: 2, 4, 8, 16 ...)\n" \
        "Example1: " + filename + " 8\n" \
        "Example2: " + filename + " -20 4 14 -8 12 45 10 -5\n";
}

int MergeSortApplication::checkPositiveNumber(const char* argv) const {
    std::stringstream convert(argv);
    int result;
    if (!(convert >> result))
        throw std::runtime_error("ERROR: " + std::string(argv) +
            " is invalid argument\n\n");
    if (result <= 0)
        throw std::runtime_error("ERROR: " + std::string(argv) +
            " is not positive number\n\n");
    return result;
}

bool MergeSortApplication::checkDegreeOfTwo(int number) const {
    while (number % 2 == 0 && number != 0)
        number /= 2;
    if (number != 0 && number != 1)
        return false;
    return true;
}

std::string MergeSortApplication::operator()(int argc,
    const char* argv[]) const {
    if (argc <= 1) {
        return help(argv[0]);
    }

    try {
        if (argc == 2) {
            int size = checkPositiveNumber(argv[1]);
            if (!checkDegreeOfTwo(size))
                throw std::runtime_error("ERROR: " + std::string(argv[1]) +
                    " is not equal of degree of two\n\n");
            std::vector<double> vec(size);
            for (int i = 0; i < size; i++)
                vec[i] = size - i;
            MergeSort::OddEvenMergeSort(&vec, 0, size - 1);
            std::ostringstream stream;
            stream << "Sorted vector: ";
            for (size_t i = 0; i < vec.size(); i++) {
                stream << vec[i] << " ";
            }
            return stream.str();
        } else {
            int size = argc - 1;
            if (!checkDegreeOfTwo(size)) {
                throw std::runtime_error
                ("ERROR: count of numbers is not equal of degree of two\n\n");
            }
            std::vector<double> vec(size);
            for (int i = 0; i < size; i++) {
                std::stringstream convert(argv[i + 1]);
                double num;
                if (!(convert >> num)) {
                    throw std::runtime_error("ERROR: " +
                        std::string(argv[i + 1]) + " is invalid argument\n\n");
                }
                vec[i] = num;
            }
            MergeSort::OddEvenMergeSort(&vec, 0, size - 1);
            std::ostringstream stream;
            stream << "Sorted vector: ";
            for (size_t i = 0; i < vec.size(); i++) {
                stream << vec[i] << " ";
            }
            return stream.str();
        }
    } catch(const std::exception& e) {
        return e.what() + help(argv[0]);
    }
}
