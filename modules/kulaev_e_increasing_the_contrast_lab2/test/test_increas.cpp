// Copyright 2024 Kulaev Zhenya

#include <gtest/gtest.h>

#include "include/increasing_cont.h"


TEST(Kulaev_Zhenya_increasing_test, Test_one) {
  const size_t m = 4;
  const size_t n = 4;
  const int new_min = 0;
  const int new_max = 255;

  std::vector<int> image{10,  50, 100, 150, 200, 16,  0, 54,
                             122, 89, 100, 0,   1,   255, 4, 5};

  std::vector<int> copyimage{ 10,  50, 100, 150, 200, 16,  0, 54,
                           122, 89, 100, 0,   1,   255, 4, 5};

  int old_min = *std::min_element(image.begin(), image.end());
  int old_max = *std::max_element(image.begin(), image.end());

  increase_contrast(image, old_min, old_max, new_min, new_max);

  ASSERT_EQ(image, copyimage);
}

TEST(Kulaev_Zhenya_increasing_test, Test_two) {
  const size_t m = 4;
  const size_t n = 4;
  const int new_min = 0;
  const int new_max = 254;

  std::vector<int> image{10,  50, 100, 150, 200, 16,  0, 54,
                             122, 89, 100, 0,   1,   255, 4, 5};

  std::vector<int> copyimage{ 9, 49, 99, 149, 199, 15, 0, 53,
                                121, 88, 99, 0, 0, 254, 3, 4};

  int old_min = *std::min_element(image.begin(), image.end());
  int old_max = *std::max_element(image.begin(), image.end());

  increase_contrast(image, old_min, old_max, new_min, new_max);

  ASSERT_EQ(image, copyimage);
}

TEST(Kulaev_Zhenya_increasing_test, Test_three) {
  const size_t m = 4;
  const size_t n = 4;
  const int new_min = 0;
  const int new_max = 4;

  std::vector<int> image{10, 50, 100, 150, 200, 16,  0, 54,
                             122, 89, 100, 0,   1,   255, 4, 5};

  std::vector<int> copyimage{ 0, 0, 1, 2, 3, 0, 0, 0,
                              1, 1, 1, 0, 0, 4, 0, 0};

  int old_min = *std::min_element(image.begin(), image.end());
  int old_max = *std::max_element(image.begin(), image.end());

  increase_contrast(image, old_min, old_max, new_min, new_max);

  ASSERT_EQ(image, copyimage);
}

TEST(Kulaev_Zhenya_increasing_test, Test_four) {
  const size_t m = 5;
  const size_t n = 4;
  const int new_min = 0;
  const int new_max = 255;

  std::vector<int> image{10,  50, 100, 150, 200, 16,  0, 54,
                             122, 89, 100, 0,   1,   255, 4, 5,
                             5, 1, 42, 12};

  std::vector<int> copyimage{ 10, 50, 100, 150, 200, 16, 0, 54,
                            122, 89, 100, 0, 1, 255, 4, 5,
                            5, 1, 42, 12};

  int old_min = *std::min_element(image.begin(), image.end());
  int old_max = *std::max_element(image.begin(), image.end());

  increase_contrast(image, old_min, old_max, new_min, new_max);

  ASSERT_EQ(image, copyimage);
}

TEST(Kulaev_Zhenya_increasing_test, Test_five) {
  const size_t m = 2;
  const size_t n = 8;
  const int new_min = 0;
  const int new_max = 64;

  std::vector<int> image{10,  50, 100, 150, 200, 16,  0, 54,
                             122, 89, 100, 0,   1,   255, 4, 5};

  std::vector<int> copyimage{2, 12, 25, 37, 50, 4, 0, 13,
                                30, 22, 25, 0,  0, 64, 1, 1};

  int old_min = *std::min_element(image.begin(), image.end());
  int old_max = *std::max_element(image.begin(), image.end());

  increase_contrast(image, old_min, old_max, new_min, new_max);

  ASSERT_EQ(image, copyimage);
}

TEST(Kulaev_Zhenya_increasing_test, Test_empty) {
  const size_t m = 1;
  const size_t n = 4;
  const int new_min = 0;
  const int new_max = 122;

  std::vector<int> image{};

  ASSERT_NO_THROW(increase_contrast(image, 0, 0, new_min, new_max));
}
