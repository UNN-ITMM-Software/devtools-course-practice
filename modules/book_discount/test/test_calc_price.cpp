// Copyright 2021 Tyurmina Alexandra

#include <gtest/gtest.h>

#include <tuple>
#include "include/calculate_price.h"

TEST(CalculatePrice,
  Do_Throw_When_Create_Basket_With_Negative_Value) {
  ASSERT_ANY_THROW(CalculatePrice(1, -2, 3, 4, 5));
}

TEST(CalculatePrice, Can_Create_Basket_With_Zero_Value) {
  ASSERT_NO_THROW(CalculatePrice(0, 0, 0, 0, 0));
}

typedef testing::TestWithParam<std::tuple<int, int,
  int, int, int, double>> Param;
TEST_P(Param, parametr) {
  int b1 = std::get<0>(GetParam());
  int b2 = std::get<1>(GetParam());
  int b3 = std::get<2>(GetParam());
  int b4 = std::get<3>(GetParam());
  int b5 = std::get<4>(GetParam());
  double price = std::get<5>(GetParam());

  CalculatePrice res(b1, b2, b3, b4, b5);

  ASSERT_EQ(price, res.TotalSum());
}

INSTANTIATE_TEST_CASE_P(/**/, Param, testing::Values(
  std::make_tuple(7, 0, 0, 0, 0, 56.0),
  std::make_tuple(0, 0, 4, 0, 0, 32.0),
  std::make_tuple(7, 1, 0, 0, 0, 63.2),
  std::make_tuple(5, 4, 3, 2, 1, 100.4),
  std::make_tuple(0, 0, 2, 1, 0, 23.2),
  std::make_tuple(1, 0, 0, 0, 0, 8.0),
  std::make_tuple(1, 1, 0, 0, 0, 15.2),
  std::make_tuple(1, 1, 1, 0, 0, 21.6),
  std::make_tuple(1, 1, 1, 1, 0, 25.6),
  std::make_tuple(1, 1, 1, 1, 1, 30.0)
));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
