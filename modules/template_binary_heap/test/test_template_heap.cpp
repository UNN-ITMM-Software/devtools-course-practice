// Copyright 2021 Ikromov Inom

#include <gtest/gtest.h>
#include "include/template_heap.h"


TEST(THeap, Can_create_int_heap) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(THeap<int>());
}

TEST(THeap, Can_create_double_heap) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(THeap<double>());
}

TEST(THeap, Can_create_char_heap) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(THeap<char>());
}

TEST(THeap, Can_insert_value) {
  // Arrange
  THeap<int> a;

  // Act, Assert
  ASSERT_NO_THROW(a.Push(3));
}

TEST(THeap, Cam_remove_value) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);

  // Assert
  ASSERT_NO_THROW(a.Remove());
}

TEST(THeap, Cam_insert_and_remove_value) {
  // Arrange
  THeap<int> a;
  int k;

  // Act
  a.Push(5);
  k = a.Remove();

  // Assert
  ASSERT_EQ(5, k);
}

TEST(THeap, Remove_from_empty_heap) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);
  int k = a.Remove();

  // Assert
  ASSERT_ANY_THROW(a.Remove());
}

TEST(THeap, Can_print_heap) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);
  a.Push(8);
  a.Push(10);

  // Assert
  ASSERT_NO_THROW(a.PrintHeap());
}

TEST(THeap, Can_get_size) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);
  a.Push(8);
  a.Push(10);

  // Assert
  ASSERT_EQ(3, a.GetSize());
}

TEST(THeap, Can_use_copy_ctor) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);
  a.Push(8);
  THeap<int> b(a);

  // Assert
  for (size_t i = 0; i < a.GetSize(); i++) {
    ASSERT_EQ(a.Remove(), b.Remove());
  }
}

TEST(THeap, Can_use_assignment_operator) {
  // Arrange
  THeap<int> a;
  THeap<int> b;

  // Act
  a.Push(5);
  a.Push(8);
  b = a;

  // Assert
  for (size_t i = 0; i < a.GetSize(); i++) {
    ASSERT_EQ(a.Remove(), b.Remove());
  }
}

TEST(Theap, Test_for_cov1) {
  // Arrange
  THeap<int> a;

  // Act
  a.Push(5);
  a.Push(28);
  a.Push(17);
  a.Push(8);

  a.Remove();
  a.Remove();
  a.Remove();
  a.Remove();

  // Assert
  ASSERT_ANY_THROW(a.Remove());
}