// Copyright 2021 Kirillov Konstantin

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <tuple>
#include "include/largest_subseq.h"

typedef testing::TestWithParam<std::tuple<int, int, int, int, int, int>>
    Kirillov_Largest_Subseq_Param;


TEST_P(Kirillov_Largest_Subseq_Param, largest_subseq) {
    std::vector<int> seqVec;
    std::vector<int> algAnsNlogN;
    std::vector<int> algAnsN2;
    seqVec.push_back(std::get<0>(GetParam()));
    seqVec.push_back(std::get<1>(GetParam()));
    seqVec.push_back(std::get<2>(GetParam()));
    seqVec.push_back(std::get<3>(GetParam()));
    seqVec.push_back(std::get<4>(GetParam()));
    seqVec.push_back(std::get<5>(GetParam()));
    Sequential seq(seqVec);
    algAnsNlogN = seq.getLargSubseq("NlogN");
    algAnsN2 = seq.getLargSubseq("N2");

    ASSERT_EQ(algAnsNlogN.size(), algAnsN2.size());
}

INSTANTIATE_TEST_CASE_P(/**/, Kirillov_Largest_Subseq_Param,
    testing::Combine(
        testing::Values(7, 3, 5), testing::Values(-2, -5, -7),
        testing::Values(1, 2, 3), testing::Values(5, 8, 9),
        testing::Values(-5, -10, -15), testing::Values(10, -3, 0)
));
