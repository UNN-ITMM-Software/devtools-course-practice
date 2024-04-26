// Copyright 2024 Konovalov Igor

#include <gtest/gtest.h>
#include <random>
#include "include/konovalov_i_euler_f.h"


TEST(Konovalov_Igor_Euler_Funcion, throws_when_negative_number_is_given) {
    EXPECT_ANY_THROW(EulerFunction::euler(-5));
}

TEST(Konovalov_Igor_Euler_Funcion, naive_throws_when_negative_number_is_given) {
  EXPECT_ANY_THROW(EulerFunction::euler_naive(-5));
}

TEST(Konovalov_Igor_Euler_Funcion, naive_returns_1_when_given_1) {
  EXPECT_EQ(1, EulerFunction::euler_naive(1));
}

TEST(Konovalov_Igor_Euler_Funcion, returns_1_when_given_1) {
  EXPECT_EQ(1, EulerFunction::euler(1));
}

TEST(Konovalov_Igor_Euler_Funcion, returns_1_when_given_2) {
  EXPECT_EQ(1, EulerFunction::euler(2));
}

TEST(Konovalov_Igor_Euler_Funcion, returns_2_when_given_6) {
  EXPECT_EQ(2, EulerFunction::euler_naive(6));
}

TEST(Konovalov_Igor_Euler_Funcion, returns_400_when_given_1000) {
  EXPECT_EQ(400, EulerFunction::euler(1000));
}

TEST(Konovalov_Igor_Euler_Funcion, gives_same_result_as_naive_impl) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000);
  for (int i = 0; i < 20; i++) {
    int in = dist6(rng);
    ASSERT_EQ(EulerFunction::euler_naive(in), EulerFunction::euler(in));
  }
}

