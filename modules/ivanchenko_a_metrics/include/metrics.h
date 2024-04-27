// Copyright 2024 Ivanchenko Aleksei

#pragma once

#include <stdexcept>
#include <vector>

namespace metrics {
    float l1(const std::vector<float>&v1, const std::vector<float>&v2);
    float l2(const std::vector<float>&v1, const std::vector<float>&v2);
    float l3(const std::vector<float>&v1, const std::vector<float>&v2);
    float l4(const std::vector<float>&v1, const std::vector<float>&v2);
    float linf(const std::vector<float>&v1, const std::vector<float>&v2);
}
