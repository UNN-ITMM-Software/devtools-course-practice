// Copyright 2021 Kirillov Konstantin

#ifndef MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_H_
#define MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>

class Sequential {
 private:
    std::vector <int> m_seq;
    std::vector<int> findLargSubseqNlogN(std::vector <int> m_seq);
    std::vector<int> findLargSubseqN2(std::vector <int> m_seq);

 public:
    explicit Sequential(std::vector <int> seq);
    std::vector<int> getLargSubseq(std::string name);
};

#endif  // MODULES_LARGEST_SUBSEQ_INCLUDE_LARGEST_SUBSEQ_H_
