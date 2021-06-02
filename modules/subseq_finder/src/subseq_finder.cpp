// Copyright 2021 Tsvetkov Maxim

#include <algorithm>
#include <vector>
#include <iostream>
#include "include/subseq_finder.h"

SubseqFinder::SubseqFinder(const std::vector <int>& seq_1,
                           const std::vector <int>& seq_2):
                           seq_1(seq_1), seq_2(seq_2) {}

void SubseqFinder::findMaxSubseq(const std::vector<int>& a,
                                 const std::vector<int>& b,
                                 std::vector<int>* result) {
    int firstSize = a.size();
    int secondSize = b.size();
    std::vector<std::vector <int>> sequencer(firstSize + 1,
                                   std::vector<int>(secondSize + 1));
    for (int i = firstSize - 1; i >= 0; i--) {
        for (int j = secondSize - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                sequencer[i][j] = sequencer[i + 1][j + 1] + 1;
            } else {
                sequencer[i][j] = std::max(sequencer[i + 1][j],
                                           sequencer[i][j + 1]);
            }
        }
    }

    for (int i = 0, j = 0;
            i < firstSize && j < secondSize && sequencer[i][j] != 0;) {
        if (a[i] == b[j]) {
            result->push_back(a[i]);
            i++;
            j++;
        } else {
            if (sequencer[i][j] == sequencer[i + 1][j]) {
                i++;
            } else {
                j++;
            }
        }
    }
}

void SubseqFinder::getMaxSubseq(std::vector<int>* result) {
    findMaxSubseq(seq_1, seq_2, result);
}
