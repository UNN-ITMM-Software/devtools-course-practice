// Copyright 2024 Martynov Aleksandr


#include <gtest/gtest.h>
#include "include/tmatrix.h"

TEST(TDynamicMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix) {
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one) {
    TDynamicMatrix<int> m(5), m1(m);
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory) {
    TDynamicMatrix<int> m(5), m1(m);
    m1[0][0] = 5;
    EXPECT_NE(m1[0][0], m[0][0]);
}

TEST(TDynamicMatrix, can_get_size) {
    TDynamicMatrix<int> m(5);
    EXPECT_EQ((size_t)5, m[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element) {
    TDynamicMatrix<int> m(5);
    m[0][0] = 5;
    EXPECT_EQ((int)5, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index) {
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m[-1][0] = 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index) {
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m[8][0] = 5);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself) {
    TDynamicMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) {
    TDynamicMatrix<int> m(5), m1(5);
    m[0][0] = 5;
    m1 = m;
    EXPECT_EQ((int)5, m1[0][0]);
}


TEST(TDynamicMatrix, can_assign_matrices_of_different_size) {
    TDynamicMatrix<int> m(5), m1(2);
    m1 = m;
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true) {
    TDynamicMatrix<int> m(5), m1;
    m1 = m;
    EXPECT_EQ(true, m1 == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true) {
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal) {
    TDynamicMatrix<int> m(5), m1(2);
    EXPECT_EQ(false, m1 == m);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size) {
    TDynamicMatrix<int> m(5), m1(5), m2;
    m[0][0] = 5;
    m1[0][1] = 2;
    m2 = m + m1;
    EXPECT_EQ((int)5, m2[0][0]);
    EXPECT_EQ((int)2, m2[0][1]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size) {
    TDynamicMatrix<int> m(5), m1(2);
    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size) {
    TDynamicMatrix<int> m(5), m1(5), m2;
    m[0][0] = 5;
    m1[0][0] = 4;
    m[0][1] = 5;
    m1[0][1] = 2;
    m2 = m - m1;
    EXPECT_EQ((int)1, m2[0][0]);
    EXPECT_EQ((int)3, m2[0][1]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size) {
    TDynamicMatrix<int> m(5), m1(2);
    ASSERT_ANY_THROW(m - m1);
}
TEST(TDynamicMatrix, can_find_determinant) {
  size_t size = 3;
  TDynamicMatrix<double> m(size);
  for (size_t q = 0; q < size; q++) {
    for (size_t w = 0; w < size; w++) {
      m[q][w] = q+w+1;
    }
  }
  m[0][0] = 2.0;
  EXPECT_DOUBLE_EQ(m.findDeterm(m), -1.0);
}
TEST(TDynamicMatrix, can_find_inverse) {
  size_t size = 3;
  TDynamicMatrix<double> m(size);
  TDynamicMatrix<double> mat(size);
  for (size_t q = 0; q < size; q++) {
    for (size_t w = 0; w < size; w++) {
      m[q][w] = q + w + 1;
    }
  }

  mat[0][0] = 6.0;
  mat[0][1] = 11.0;
  mat[0][2] = 5.0;
  mat[1][0] = 8.0;
  mat[1][1] = 3.0;
  mat[1][2] = 2.0;
  mat[2][0] = 1.0;
  mat[2][1] = 4.0;
  mat[2][2] = 7.0;

  m = mat.findInverse(mat);
  EXPECT_DOUBLE_EQ(m[0][0], -13.0/371.0);
}
TEST(TDynamicMatrix, inverse_matrix_with_null_determ) {
  size_t size = 3;
  TDynamicMatrix<double> m(size);
  TDynamicMatrix<double> mat(size);
  for (size_t q = 0; q < size; q++) {
    for (size_t w = 0; w < size; w++) {
      m[q][w] = q + w + 1;
      mat[q][w] = 1;
    }
  }
  ASSERT_ANY_THROW(mat.findInverse(mat));
}
