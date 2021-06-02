// Copyright 2021 Kirillov Konstantin

#ifndef MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQ_H_
#define MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQ_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>

class GeneralSubseq {
 private:
    std::vector <int> m_first_seq;
    std::vector <int> m_second_seq;
    std::vector<int> findGenLargSubseq(std::vector <int> m_first_seq,
     std::vector <int> m_second_seq);

 public:
    explicit GeneralSubseq(std::vector <int> firstSeq,
     std::vector <int> secondSeq);
    std::vector<int> getLargSubseq();
};

#endif  // MODULES_GENERAL_SUBSEQ_INCLUDE_GENERALSUBSEQ_H_
