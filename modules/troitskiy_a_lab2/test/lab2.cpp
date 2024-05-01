// Copyright 2024 Troitskiy Alexander

#include "include/lab2.h"
#include <gtest/gtest.h>
#include <limits>

TEST(Troitskiy_A_Lab2Test, Push_Pop_Top) {
  Heap<10> heap;
  heap.push(5);
  heap.push(10);
  heap.push(3);
  heap.push(7);

  EXPECT_EQ(heap.top(), 10);

  heap.pop();
  EXPECT_EQ(heap.top(), 7);

  heap.pop();
  EXPECT_EQ(heap.top(), 5);

  heap.push(15);
  EXPECT_EQ(heap.top(), 15);
}

TEST(Troitskiy_A_Lab2Test, ConstructFromVector) {
  std::vector<double> vec = {8, 2, 6, 1, 9};
  Heap<5> heap(vec);

  EXPECT_EQ(heap.top(), 9);

  heap.pop();
  EXPECT_EQ(heap.top(), 8);
}

TEST(Troitskiy_A_Lab2Test, EmptyHeapTop) {
  Heap<5> heap;
  EXPECT_THROW(heap.top(), std::logic_error);
}

TEST(Troitskiy_A_Lab2Test, PushPopAlternating) {
    Heap<5> heap;
    heap.push(10);
    heap.push(5);
    heap.pop();
    heap.push(8);

    EXPECT_EQ(heap.top(), 8);
}

TEST(Troitskiy_A_Lab2Test, PopFromEmptyHeap) {
    Heap<10> heap;
    EXPECT_THROW(heap.pop(), std::logic_error);
}

