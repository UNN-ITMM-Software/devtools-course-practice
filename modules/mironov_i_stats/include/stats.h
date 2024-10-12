// Copyright 2024 Mironov Ilya

#pragma once

#include <vector>

namespace stats {
float moment(const std::vector<float>& data, size_t k, float mu);
float mean(const std::vector<float>& data);
float var_base(const std::vector<float>& data);
float var(const std::vector<float>& data);
}  // namespace stats
