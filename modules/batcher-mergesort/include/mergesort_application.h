// Copyright 2021 Zaitsev Andrey

#ifndef MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_APPLICATION_H_
#define MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_APPLICATION_H_

#include <string>

class MergeSortApplication {
 public:
     MergeSortApplication() = default;
     std::string operator()(int argc, const char* argv[]) const;
 private:
     std::string help(const std::string& filename) const;
     int checkPositiveNumber(const char* argv) const;
     bool checkDegreeOfTwo(int number) const;
};

#endif  // MODULES_BATCHER_MERGESORT_INCLUDE_MERGESORT_APPLICATION_H_
