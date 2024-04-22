// Copyright 2024 Videneva Ekaterina

#include <gtest/gtest.h>

#include "include/euler_function.h"

TEST(Videneva_EulerFunctionTest, throw_if_not_positive_number) {
  // Assert
  EXPECT_ANY_THROW(euler_function(-1));
}

TEST(Videneva_EulerFunctionTest, number_is_one_test) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 1;
  actual = euler_function(1);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, simple_numbers_test1) {
  // Arrange
  std::vector<int64_t> simple_numbers{2,   3,   5,   7,   11,  13,  17, 19,
                                  23,  29,  31,  37,  41,  53,  83, 89,
                                  113, 131, 173, 179, 191, 233, 239};

  for (size_t i = 0; i < simple_numbers.size(); ++i) {
    // Act
    int64_t simple_number = simple_numbers[i];
    int64_t expected = simple_number - 1;  // fi(p) = p - 1
    int64_t actual = euler_function(simple_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, simple_numbers_test2) {
  // Arrange
  std::vector<int64_t> simple_numbers{1801, 1951, 2269, 2437, 2791, 3169,
                                  3571, 4219, 4447, 5167, 5419, 6211};

  for (size_t i = 0; i < simple_numbers.size(); ++i) {
    // Act
    int64_t simple_number = simple_numbers[i];
    int64_t expected = simple_number - 1;  // fi(p) = p - 1
    int64_t actual = euler_function(simple_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, simple_numbers_test3) {
  // Arrange
  std::vector<int64_t> simple_numbers{37633, 43201, 47629, 60493, 63949, 65713,
                                  69313, 73009, 76801, 84673, 106033};

  for (size_t i = 0; i < simple_numbers.size(); ++i) {
    // Act
    int64_t simple_number = simple_numbers[i];
    int64_t expected = simple_number - 1;  // fi(p) = p - 1
    int64_t actual = euler_function(simple_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, degree_of_simple_number_test1) {
  // Arrange
  std::vector<int64_t> simple_numbers{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  for (size_t i = 0; i < simple_numbers.size(); ++i) {
    // Act
    int64_t degree_of_simple_number = pow(simple_numbers[i], 2);  // a = p1^2
    int64_t expected = pow(simple_numbers[i], 2) -
                   simple_numbers[i];  // fi(a) = fi(p1^2) = (p1^2-p1)
    int64_t actual = euler_function(degree_of_simple_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, degree_of_simple_number_test2) {
  // Arrange
  std::vector<int64_t> simple_numbers{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  for (size_t i = 0; i < simple_numbers.size(); ++i) {
    // Act
    int64_t degree_of_simple_number = pow(simple_numbers[i], 3);  // a = p1^3
    int64_t expected = pow(simple_numbers[i], 3) -
                   pow(simple_numbers[i], 2);  // fi(a) = fi(p1^3) = p^3 - p^2
    int64_t actual = euler_function(degree_of_simple_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, composite_numbers_test1) {
  // Arrange
  std::vector<int64_t> simple_numbers1{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  std::vector<int64_t> simple_numbers2{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

  for (size_t i = 0; i < simple_numbers1.size(); ++i) {
    // Act
    int64_t composite_number = simple_numbers1[i] * simple_numbers2[i];  // a =
                                                                     // p1*p2
    int64_t expected =
        (simple_numbers1[i] - 1) *
        (simple_numbers2[i] - 1);  // fi(a) = fi(p1*p2) = (p1-1)*(p2-1)
    int64_t actual = euler_function(composite_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, composite_numbers_test2) {
  // Arrange
  std::vector<int64_t> simple_numbers1{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  std::vector<int64_t> simple_numbers2{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2};

  for (size_t i = 0; i < simple_numbers1.size(); ++i) {
    // Act
    int64_t composite_number =
        simple_numbers1[i] * pow(simple_numbers2[i], 2);  // a = p1*p2^2
    int64_t expected =
        (simple_numbers1[i] - 1) *
        (pow(simple_numbers2[i], 2) -
         simple_numbers2[i]);  // fi(a) = fi(p1*p2^2) = (p1-1)*(p2^2-p2)
    int64_t actual = euler_function(composite_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, composite_numbers_test3) {
  // Arrange
  std::vector<int64_t> simple_numbers1{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  std::vector<int64_t> simple_numbers2{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2};

  for (size_t i = 0; i < simple_numbers1.size(); ++i) {
    // Act
    int64_t composite_number = pow(simple_numbers1[i], 3) *
                           pow(simple_numbers2[i], 2);  // a = p1^3*p2^2
    int64_t expected =
        (pow(simple_numbers1[i], 3) - pow(simple_numbers1[i], 2)) *
        (pow(simple_numbers2[i], 2) -
         simple_numbers2[i]);  // fi(a) = fi(p1^3*p2^2) = (p1^3-p1^2)*(p2^2-p2)
    int64_t actual = euler_function(composite_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

TEST(Videneva_EulerFunctionTest, composite_numbers_test4) {
  // Arrange
  std::vector<int64_t> simple_numbers1{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  std::vector<int64_t> simple_numbers2{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2};
  std::vector<int64_t> simple_numbers3{5, 7, 11, 13, 17, 19, 23, 29, 31, 2, 3};

  for (size_t i = 0; i < simple_numbers1.size(); ++i) {
    // Act
    int64_t composite_number = simple_numbers1[i] * simple_numbers2[i] *
                           simple_numbers3[i];  // a = p1*p2*p3
    int64_t expected = (simple_numbers1[i] - 1) * (simple_numbers2[i] - 1) *
                   (simple_numbers3[i] -
                    1);  // fi(a) = fi(p1*p2*p3) = (p1-1)*(p2-1)*(p3-1)
    int64_t actual = euler_function(composite_number);
    // Assert
    ASSERT_EQ(expected, actual);
  }
}

// answers are calculated by online service
TEST(Videneva_EulerFunctionTest, big_number_test1) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 69754744080;
  actual = euler_function(210474803646);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, big_number_test2) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 68719476736;
  actual = euler_function(137438953472);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, big_number_test3) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 5583927744000;
  actual = euler_function(12367723468232);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, big_number_test4) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 1858216258560000;
  actual = euler_function(4645583927744000);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, big_number_test5) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 31927748229000;
  actual = euler_function(95783244687012);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, random_test1) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 47974320;
  actual = euler_function(60058265);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, random_test2) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 5391360;
  actual = euler_function(13272154);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, random_test3) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 80307498;
  actual = euler_function(80307499);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, random_test4) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 29948288;
  actual = euler_function(56567985);
  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(Videneva_EulerFunctionTest, random_test5) {
  // Arrange
  int64_t expected, actual;
  // Act
  expected = 27516120;
  actual = euler_function(45401631);
  // Assert
  EXPECT_EQ(expected, actual);
}
