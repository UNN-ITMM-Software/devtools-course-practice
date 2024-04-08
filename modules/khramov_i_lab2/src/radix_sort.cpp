// Copyright 2024 Khramov Ivan

#include <string>

#include "include/radix_sort.h"

void RadixSort::radixSort(std::vector<int>& array, bool order) {
    int array_size = array.size();
    if (array_size == 0) {
        throw std::string("The array is empty. Nothing to sort.");
    }

    int extreme_el = RadixSort::getMaximumOrMinimum(array);

    if (extreme_el < 0) {
        for (int i = 0; i < array_size; i++) {
            array[i] += -(extreme_el);
        }
    }

    for (int digit = 1; abs(extreme_el) / digit > 0; digit *= 10) {
        RadixSort::countSort(array, digit, order);
    }

    if (extreme_el < 0) {
        for (int i = 0; i < array_size; i++) {
            array[i] += extreme_el;
        }
    }
}

void RadixSort::countSort(std::vector<int>& array, int digit, bool order) {
    int array_size = array.size();
    int i{}, base = 10;
    std::vector<int> sorted_digit(array_size, 0);
    std::vector<int> count_numbers(base, 0);

    for (i = 0; i < array_size; i++) {
        count_numbers[(array[i] / digit) % 10]++;
    }

    for (i = 1; i < base; i++) {
        count_numbers[i] += count_numbers[i - 1];
    }

    if (order) {
        for (i = array_size - 1; i >= 0; i--) {
            sorted_digit[count_numbers[(array[i] / digit) % 10] - 1] = array[i];
            count_numbers[(array[i] / digit) % 10]--;
        }
    } else {
        for (i = 0; i < array_size; i++) {
            sorted_digit[array_size - count_numbers[(array[i] / digit) % 10]] =
             array[i];
            count_numbers[(array[i] / digit) % 10]--;
        }
    }

    for (i = 0; i < array_size; i++) {
        array[i] = sorted_digit[i];
    }
}

int RadixSort::getMaximumOrMinimum(std::vector<int>& array) {
    int array_size = array.size();
    int tmp_max = array[0];
    int tmp_min = array[0];
    bool is_negatives = array[0] < 0;
    for (int i = 1; i < array_size; i++) {
        if (tmp_max < array[i]) {
            tmp_max = array[i];
        }
        if (tmp_min > array[i]) {
            tmp_min = array[i];
        }
        if (array[i] < 0) {
            is_negatives = true;
        }
    }
    return is_negatives == true ? tmp_min : tmp_max;
}
