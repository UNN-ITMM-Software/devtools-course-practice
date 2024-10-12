// Copyright 2024 Mironov Ilya

#include "include/stats.h"

#include <cmath>
#include <numeric>

namespace stats {

float moment(const std::vector<float>& data, size_t k, float mu) {
    float result = 0.0f;
    for (auto& x : data) {
        result += std::pow(x - mu, k);
    }
    return result / data.size();
}
float mean(const std::vector<float>& data) {
    return moment(data, 1, 0.0f);
}
float var_base(const std::vector<float>& data) {
    return moment(data, 2, mean(data));
}
float var(const std::vector<float>& data) {
    float result1 = 0.0f;
    float result2 = 0.0f;
    const auto size = data.size();
    for (auto& x : data) {
        result1 += x * x;
        result2 += x;
    }
    return result1 / size - (result2 / size) * (result2 / size);
}
}  // namespace stats
