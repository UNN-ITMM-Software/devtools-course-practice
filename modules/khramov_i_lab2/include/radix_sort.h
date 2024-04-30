// Copyright 2024 Khramov Ivan

#ifndef MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_
#define MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_

#include <vector>
#include <memory>
#include <type_traits>
#include <stdexcept>
#include <random>

template<typename T, typename =
 typename std::enable_if<std::is_integral<T>::value>::type>
class RadixSort {
 public:
  static void radixSort(std::vector<T>& array, bool order = true) {
    int array_size = array.size();
    int i{};
    if (array_size == 0) {
        throw std::invalid_argument("The array is empty. Nothing to sort.");
    }

    T extreme_el = RadixSort<T>::getMaximumOrMinimum(array);
    T shift = 0;

    if (extreme_el < 0) {
        shift = extreme_el;
        for (i = 0; i < array_size; i++) {
            array[i] += -(shift);
        }
        extreme_el = RadixSort<T>::getMaximumOrMinimum(array);
    }

    for (int digit = 1; abs(extreme_el) / digit > 0; digit *= 10) {
        RadixSort<T>::countSort(array, digit, order);
    }

    if (shift != 0) {
        for (i = 0; i < array_size; i++) {
            array[i] += shift;
        }
    }
  }

  static std::vector<T> getRandomVector(int sz) {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::vector<T> vec(sz);
    for (int  i = 0; i < sz; i++) { vec[i] = gen() % 100; }
    return vec;
  }

 private:
  static void countSort(std::vector<T>& array, int digit, bool order) {
    int array_size = array.size();
    int i{};
    const int base = 10;
    std::vector<T> sorted_digit(array_size, 0);
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

  static T getMaximumOrMinimum(std::vector<T>& array) {
    int array_size = array.size();
    T tmp_max = array[0];
    T tmp_min = array[0];
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
};

#endif  // MODULES_KHRAMOV_I_LAB2_INCLUDE_RADIX_SORT_H_
