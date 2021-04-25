// Copyright 2021 Maksim Shagov

#ifndef MODULES_30_RULE_INCLUDE_30_RULE_H_
#define MODULES_30_RULE_INCLUDE_30_RULE_H_

#include <vector>

enum class CellState {
    DEAD,
    ALIVE
};

class CellularAuto {
 public:
    CellularAuto(const unsigned int rows, const unsigned int cols);
    CellularAuto(const unsigned int rows, const unsigned int cols,
                 const std::vector<CellState>& states);
    ~CellularAuto() = default;

    const std::vector<std::vector<CellState>>& get_state() const;

    void iterate(const unsigned int iterations);

 private:
    std::vector<std::vector<CellState>> state;
    unsigned int cols = 0;
    unsigned int rows = 0;

    CellState rules(const int row, const int col) const;
};

#endif  // MODULES_30_RULE_INCLUDE_30_RULE_H_
