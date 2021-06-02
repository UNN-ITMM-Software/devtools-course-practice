// Copyright 2021 Zoreev Mikhail
#ifndef MODULES_BINARY_SEARCH_INCLUDE_SEARCH_ENGINE_H_
#define MODULES_BINARY_SEARCH_INCLUDE_SEARCH_ENGINE_H_

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "include/binary_search.h"

class SearchEngine {
 public:
    SearchEngine() = default;
    /**
     * @brief Functor override
     * @param argc Number of command line arguments
     * @param argv argv Command line arguments
     * @param retcode
     * @return Output expression
     */
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;

 private:
    std::string help(const std::string& filename) const;
};

#endif  // MODULES_BINARY_SEARCH_INCLUDE_SEARCH_ENGINE_H_
