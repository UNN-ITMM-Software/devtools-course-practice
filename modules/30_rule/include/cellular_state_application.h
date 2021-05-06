// Copyright 2021 Gogov Vladislav

#ifndef MODULES_30_RULE_INCLUDE_CELLULAR_STATE_APPLICATION_H_
#define MODULES_30_RULE_INCLUDE_CELLULAR_STATE_APPLICATION_H_

#include <string>

class CellularStateApplication {
 public:
    CellularStateApplication() = default;
    std::string operator()(int argc, const char* argv[]) const;

 private:
    std::string help(const std::string& filename) const;
};

#endif  // MODULES_30_RULE_INCLUDE_CELLULAR_STATE_APPLICATION_H_
