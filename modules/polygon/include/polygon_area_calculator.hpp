// Copyright 2021 Rustamov Azer

#ifndef MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_HPP_
#define MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_HPP_

#include <string>
#include "include/polygon.h"

namespace Polygon {

class PolygonAreaCalculator {
 public:
    PolygonAreaCalculator() = default;
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;
 private:
    std::string help(const std::string& filename) const;
};

}  // namespace Polygon

#endif  // MODULES_POLYGON_INCLUDE_POLYGON_AREA_CALCULATOR_HPP_
