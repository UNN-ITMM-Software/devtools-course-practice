// Copyright 2021 Kirillov Konstantin
#include "include/largest_subseq.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

Sequential::Sequential(std::vector <int> seq)
    :
    m_seq(seq) {
}

std::vector<int> Sequential::findLargSubseqNlogN(std::vector <int> fSec) {
    int n = fSec.size();
    std::vector<int> d(n+1), pos(n+1), prev(n);
    int length = 0;
    pos[0] = -1;
    d[0] = -std::numeric_limits<int>::max();

    for (int i = 1; i < n+1; i ++) {
        d[i] = std::numeric_limits<int>::max();
    }

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), fSec[i]) - d.begin();
        if (d[j - 1] < fSec[i] && fSec[i] < d[j]) {
            d[j] = fSec[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = std::max(length, j);
        }
    }

    std::vector<int> answer;
    int i = pos[length];
    if (length == 1) {
        answer.push_back(fSec[0]);
    } else {
        while (i != -1) {
            answer.push_back(fSec[i]);
            i = prev[i];
        }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}


std::vector<int> Sequential::findLargSubseqN2(std::vector <int> fSec) {
    int n = fSec.size();
    std::vector<int> d(n + 1), prev(n);
    d[0] = -std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (fSec[j] < fSec[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }

    std::vector<int> answer;
    int pos = 0;
    int length = d[0];

    for (int i = 0; i < n; i++) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    if (length == 1) {
        answer.push_back(fSec[0]);
    } else {
        while (pos != -1) {
            answer.push_back(fSec[pos]);
            pos = prev[pos];
        }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}

std::vector<int> Sequential::getLargSubseq(std::string name) {
    std::vector<int> answer;
    if (name == "NlogN") {
        answer = findLargSubseqNlogN(Sequential::m_seq);
    } else if (name == "N2") {
        answer = findLargSubseqN2(Sequential::m_seq);
    }
    return answer;
}
