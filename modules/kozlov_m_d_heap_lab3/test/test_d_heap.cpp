// Copyright 2024 Kozlov Mikhail

#include <gtest/gtest.h>
#include <limits>
#include "include/Heap.h"

// Test case for default constructor
TEST(Kozlov_heap_test, DefaultConstructor) {
  Heap<5> heap;
  EXPECT_EQ(heap.size(), uint64_t(0));
}

// Test case for pushing elements
TEST(Kozlov_heap_test, Push) {
  Heap<5> heap;
  heap.push(10);
  heap.push(20);
  heap.push(15);
  EXPECT_EQ(heap.size(), uint64_t(3));
  EXPECT_DOUBLE_EQ(heap.top(), 20);
}

// Test case for popping elements
TEST(Kozlov_heap_test, Pop) {
  Heap<5> heap;
  heap.push(10);
  heap.push(20);
  heap.push(15);
  heap.pop();
  EXPECT_EQ(heap.size(), uint64_t(2));
  EXPECT_DOUBLE_EQ(heap.top(), 15);
}

// Test case for top method
TEST(Kozlov_heap_test, Top) {
  Heap<5> heap;
  heap.push(10);
  heap.push(20);
  heap.push(15);
  EXPECT_DOUBLE_EQ(heap.top(), 20);
}

// Test case for checking heap overflow
TEST(Kozlov_heap_test, Overflow) {
  Heap<3> heap;
  heap.push(10);
  heap.push(20);
  heap.push(15);
  EXPECT_THROW(heap.push(25), std::logic_error);
}

// Test case for checking empty heap pop
TEST(Kozlov_heap_test, EmptyPop) {
  Heap<3> heap;
  EXPECT_THROW(heap.pop(), std::logic_error);
}

TEST(Kozlov_heap_test, EmptyConstruct) {
  std::vector<double> a(0);
  EXPECT_NO_THROW(Heap<3> heap(a));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
