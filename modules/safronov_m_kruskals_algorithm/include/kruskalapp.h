// Copyright 2024 Safronov Mikhail

#ifndef MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_KRUSKALAPP_H_
#define MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_KRUSKALAPP_H_

#include <string>

class KruskalApp {
 public:
    std::string Help(const std::string& app_name,
                     const std::string& message = "");
    bool Validate(int argc, char* argv[]);
    std::string Parse(int argc, char* argv[]);
};

#endif  // MODULES_SAFRONOV_M_KRUSKALS_ALGORITHM_INCLUDE_KRUSKALAPP_H_
