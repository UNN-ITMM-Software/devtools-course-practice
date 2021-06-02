// Copyright 2021 Kirillov Konstantin

#include "include/GeneralSubseq.h"
#include <algorithm>
#include <vector>

GeneralSubseq::GeneralSubseq(std::vector <int> firstSeq,
std::vector <int> secondSeq)
    :
    m_first_seq(firstSeq),
    m_second_seq(secondSeq) {
    }

std::vector<int> GeneralSubseq::findGenLargSubseq(std::vector<int> a,
std::vector<int> b) {
    int firstSize = a.size();
    int secondSize = b.size();
    std::vector<int>answer;
    std::vector<std::vector <int>> L(firstSize + 1,
     std::vector<int>(secondSize + 1));
    for (int i = firstSize - 1; i >= 0; i--) {
        for (int j = secondSize - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                L[i][j] = L[i + 1][j + 1] + 1;
            } else {
                L[i][j] = std::max(L[i + 1][j], L[i][j + 1]);
            }
        }
    }

    for (int i = 0, j = 0; i < firstSize && j < secondSize && L[i][j] != 0; ) {
        if (a[i] == b[j]) {
            answer.push_back(a[i]);
            i++;
            j++;
        } else {
            if (L[i][j] == L[i + 1][j]) {
                i++;
            } else {
                j++;
            }
        }
    }
    return answer;
}

std::vector<int> GeneralSubseq::getLargSubseq() {
    std::vector<int>answer = findGenLargSubseq(m_first_seq, m_second_seq);
    return answer;
}
