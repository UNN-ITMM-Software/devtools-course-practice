// Copyright 2024 Dostavalov Semyon
#ifndef MODULES_DOSTAVALOV_S_KNUTH_MORRIS_PRATT_INCLUDE_KMP_H_
#define MODULES_DOSTAVALOV_S_KNUTH_MORRIS_PRATT_INCLUDE_KMP_H_

#include <vector>
#include <string>

namespace KnuthMorrisPratt {
    std::vector<int> computePrefixFunction(const std::string& pattern);
    std::vector<int> findPattern(const std::string& text,
        const std::string& pattern);
}

#endif  // MODULES_DOSTAVALOV_S_KNUTH_MORRIS_PRATT_INCLUDE_KMP_H_
