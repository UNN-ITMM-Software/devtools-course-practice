// Copyright 2021 Taktaev Artem

#ifndef MODULES_DHEAP_INCLUDE_DHEAP_APP_H_
#define MODULES_DHEAP_INCLUDE_DHEAP_APP_H_

#include <string>
class DheapApp {
 public:
    DheapApp() = default;
    std::string operator()(int argc, const char* argv[],
                           int* retcode = nullptr) const;

 private:
    std::string help(const std::string& filename) const;
};

#endif  // MODULES_DHEAP_INCLUDE_DHEAP_APP_H_
