// Copyright 2024 Ivanchenko Aleksei

#include "include/metrics.h"

#include <cmath>

void checkSize(const std::vector<float>&v1, const std::vector<float>&v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("vectors have different sizes");
}
float metrics::l1(const std::vector<float>&v1, const std::vector<float>&v2) {
    checkSize(v1, v2);
    float res = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        res += std::abs(v1[i] - v2[i]);
    }
    return res;
}
float metrics::l2(const std::vector<float>&v1, const std::vector<float>&v2) {
    checkSize(v1, v2);
    float res = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        res += std::pow(std::abs(v1[i] - v2[i]), 2);
    }
    return std::pow(res, 1.0 / 2);
}
float metrics::l3(const std::vector<float>&v1, const std::vector<float>&v2) {
    checkSize(v1, v2);
    float res = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        res += std::pow(std::abs(v1[i] - v2[i]), 3);
    }
    return std::pow(res, 1.0 / 3);
}
float metrics::l4(const std::vector<float>&v1, const std::vector<float>&v2) {
    checkSize(v1, v2);
    float res = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        res += std::pow(std::abs(v1[i] - v2[i]), 4);
    }
    return std::pow(res, 1.0 / 4);
}
float metrics::linf(const std::vector<float>&v1, const std::vector<float>&v2) {
    checkSize(v1, v2);
    float res = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        res = std::max(res, std::abs(v1[i] - v2[i]));
    }
    return res;
}
