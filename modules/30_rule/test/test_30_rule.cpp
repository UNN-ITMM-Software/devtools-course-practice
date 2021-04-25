// Copyright 2021 Maksim Shagov

#include <gtest/gtest.h>

#include <tuple>
#include <vector>
#include "include/30_rule.h"

TEST(Maksim_Shagov_Cell_Auto, can_throw_ex_zero_size) {
    ASSERT_ANY_THROW(CellularAuto(0, 0));
}

TEST(Maksim_Shagov_Cell_Auto, can_throw_ex_zero_size_with_state) {
    std::vector<CellState> state;
    ASSERT_ANY_THROW(CellularAuto(0, 0, state));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_cell_class) {
    ASSERT_NO_THROW(CellularAuto(1, 1));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_cell_class_from_vector) {
    std::vector<CellState> state {CellState::DEAD, CellState::ALIVE,
                                                   CellState::DEAD};
    ASSERT_NO_THROW(CellularAuto(1, 3, state));
}

TEST(Maksim_Shagov_Cell_Auto, can_iterate_5_times) {
    std::vector<CellState> state {CellState::DEAD, CellState::ALIVE,
                                                   CellState::DEAD};
    CellularAuto automat(1, 3, state);
    ASSERT_NO_THROW(automat.iterate(5));
}

TEST(Maksim_Shagov_Cell_Auto, can_create_2_equal_auto) {
    std::vector<CellState> state {CellState::DEAD, CellState::DEAD,
                                                   CellState::DEAD};
    CellularAuto automat(1, 3, state);
    CellularAuto automat2(1, 3, state);

    ASSERT_EQ(automat.get_state(), automat2.get_state());
}

TEST(Maksim_Shagov_Cell_Auto, can_use_001_rule) {
    std::vector<CellState> state {CellState::DEAD, CellState::DEAD,
                                                   CellState::ALIVE};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {CellState::DEAD, CellState::ALIVE, CellState::DEAD};

    ASSERT_EQ(state, automat.get_state()[1]);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_010_rule) {
    std::vector<CellState> state {CellState::DEAD, CellState::ALIVE,
                                                   CellState::DEAD};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {CellState::DEAD, CellState::ALIVE, CellState::DEAD};

    ASSERT_EQ(state, automat.get_state()[1]);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_011_rule) {
    std::vector<CellState> state {CellState::DEAD, CellState::ALIVE,
                                                   CellState::ALIVE};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {CellState::DEAD, CellState::ALIVE, CellState::DEAD};

    ASSERT_EQ(state, automat.get_state()[1]);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_100_rule) {
    std::vector<CellState> state {CellState::ALIVE, CellState::DEAD,
                                                    CellState::DEAD};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {CellState::DEAD, CellState::ALIVE, CellState::DEAD};

    ASSERT_EQ(state, automat.get_state()[1]);
}

TEST(Maksim_Shagov_Cell_Auto, can_use_111_rule) {
    std::vector<CellState> state {CellState::ALIVE, CellState::ALIVE,
                                                    CellState::ALIVE};
    CellularAuto automat(2, 3, state);
    automat.iterate(1);
    state = {CellState::DEAD, CellState::DEAD, CellState::DEAD};

    ASSERT_EQ(state, automat.get_state()[1]);
}

TEST(Maksim_Shagov_Cell_Auto, classic_seq_for_rule_30) {
    std::vector<CellState> state
    {CellState::DEAD, CellState::DEAD,  CellState::DEAD,
     CellState::DEAD, CellState::ALIVE, CellState::DEAD,
     CellState::DEAD, CellState::DEAD,  CellState::DEAD};
    CellularAuto automat(2, 9, state);
    automat.iterate(1);
    state[3] = CellState::ALIVE;
    state[4] = CellState::ALIVE;
    state[5] = CellState::ALIVE;

    ASSERT_EQ(state, automat.get_state()[1]);
}
