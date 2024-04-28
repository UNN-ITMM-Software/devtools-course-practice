// Copyright 2024 Kiselev Igor

#ifndef MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_H_
#define MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_H_
#include <vector>
#include "Color.h"

class BillinearInterpolation {
 protected:
    std::vector<std::vector<Color>> source;
    Color Calculation(size_t x1, size_t y1, size_t x2, size_t y2);
 public:
    explicit BillinearInterpolation(std::vector<std::vector<Color>> sr);
    BillinearInterpolation(BillinearInterpolation&& bi);
    BillinearInterpolation(const BillinearInterpolation &bi);
    BillinearInterpolation& operator=(BillinearInterpolation&& bi);
    BillinearInterpolation& operator=(const BillinearInterpolation& bi);
    std::vector<std::vector<Color>> twoCore();
    std::vector<std::vector<Color>> threeCore();
};

#endif  // MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_BILLINEAR_INTERPOLATION_H_
