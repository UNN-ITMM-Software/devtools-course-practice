// Copyright 2021 Zoreev Mikhail

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_

#include <algorithm>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <cassert>

namespace RadixSort {
    /**
     * Sorts vector elements in range [begin, end)
     * @param begin Iterator to begin element
     * @param end Iterator to end element
     */
    template <typename ElementType>
    void radixSort(typename std::vector<ElementType>::iterator begin,
                   typename std::vector<ElementType>::iterator end) {
        assert(begin < end);
        static_assert(std::is_integral<ElementType>::value,
                "ElementType must be integral");

        std::vector<ElementType> temp(std::distance(begin, end));
        for (size_t i = 0; i < sizeof(ElementType); i++) {
            size_t count[256] = {};
            for (auto j = begin; j < end; j++) {
                count[*((unsigned char*) &*j + i)]++;
            }
            size_t offset[256] = {};
            if ((i != sizeof(ElementType) - 1) ||
                !std::is_signed<ElementType>::value) {
                for (size_t j = 1; j < 256; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
            } else {
                for (size_t j = 129; j < 256; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
                offset[0] = offset[255] + count[255];
                for (size_t j = 1; j < 128; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
            }
            for (auto j = begin; j < end; j++) {
                temp[offset[*((unsigned char*) &*j + i)]++] = *j;
            }
            std::copy(temp.begin(), temp.end(), begin);
        }
    }

    template <typename ElementType>
    std::vector<ElementType> getRandomVector(size_t size) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<ElementType>
                distribution(std::numeric_limits<ElementType>::min(),
                             std::numeric_limits<ElementType>::max());
        std::vector<ElementType> result(size);

        for (size_t i = 0; i < size; i++) {
            result[i] = distribution(generator);
        }
        return  result;
    }
}  // namespace RadixSort

#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
