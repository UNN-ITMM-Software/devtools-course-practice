// Copyright 2021 Vlasov Maksim

#ifndef MODULES_QSORT_INCLUDE_QSORTER_H_
#define MODULES_QSORT_INCLUDE_QSORTER_H_

#include <string>

namespace QSort {

class Sorter {
 public:
    Sorter() = default;
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;

 private:
    std::string help(const std::string& filename) const;
};

}  // namespace QSort

#endif  // MODULES_QSORT_INCLUDE_QSORTER_H_
