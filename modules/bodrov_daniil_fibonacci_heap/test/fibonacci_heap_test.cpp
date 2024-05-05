// Copyright 2024 Bodrov Daniil

#include <gtest/gtest.h>
#include <algorithm>

#include "include/fibonacci_heap.h"

TEST(Bodrov_Daniil_FibonacciHeapTest, EmptyHeap) {
  FibonacciHeap<int> heap;
  ASSERT_TRUE(heap.empty());
}

TEST(Bodrov_Daniil_FibonacciHeapTest, OneElementNoChildren) {
  FibonacciHeap<int> heap;
  heap.insert(42);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 42);
  ASSERT_EQ(heap.extractMin(), 42);
  ASSERT_TRUE(heap.empty());
}

TEST(Bodrov_Daniil_FibonacciHeapTest, OneElementOneChild) {
  FibonacciHeap<int> heap;
  heap.insert(42);
  heap.insert(24);

  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 24);
  ASSERT_EQ(heap.extractMin(), 24);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 42);
  ASSERT_EQ(heap.extractMin(), 42);
  ASSERT_TRUE(heap.empty());
}

TEST(Bodrov_Daniil_FibonacciHeapTest, ManyElements) {
  FibonacciHeap<int> heap;
  heap.insert(42);
  heap.insert(24);
  heap.insert(16);
  heap.insert(32);

  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 16);
  ASSERT_EQ(heap.extractMin(), 16);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 24);
  ASSERT_EQ(heap.extractMin(), 24);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 32);
  ASSERT_EQ(heap.extractMin(), 32);
  ASSERT_FALSE(heap.empty());
  ASSERT_EQ(heap.minimum(), 42);
  ASSERT_EQ(heap.extractMin(), 42);
  ASSERT_TRUE(heap.empty());
}


TEST(Bodrov_Daniil_FibonacciHeapTest, BasicOperations) {
  FibonacciHeap<int> heap;
  ASSERT_TRUE(heap.empty());

  heap.insert(5);
  heap.insert(10);
  heap.insert(3);
  heap.insert(7);

  ASSERT_EQ(heap.minimum(), 3);

  int min = heap.extractMin();

  ASSERT_EQ(min, 3);
  ASSERT_EQ(heap.minimum(), 5);
}

TEST(Bodrov_Daniil_FibonacciHeapTest, DecreaseKey) {
  FibonacciHeap<int> heap;
  FibonacciHeapNode<int> *node1 = heap.insert(5);
  FibonacciHeapNode<int> *node2 = heap.insert(10);
  FibonacciHeapNode<int> *node3 = heap.insert(7);

  heap.decreaseKey(node3, 2);
  ASSERT_EQ(heap.minimum(), 2);

  heap.decreaseKey(node1, 1);
  ASSERT_EQ(heap.minimum(), 1);

  heap.decreaseKey(node2, 0);
  ASSERT_EQ(heap.minimum(), 0);
}

TEST(Bodrov_Daniil_FibonacciHeapTest, Merge) {
  FibonacciHeap<int> heap1;
  heap1.insert(5);
  heap1.insert(3);
  heap1.insert(7);

  FibonacciHeap<int> heap2;
  heap2.insert(2);
  heap2.insert(8);
  heap2.insert(4);

  heap1.merge(&heap2);

  ASSERT_EQ(heap1.minimum(), 2);
  ASSERT_EQ(heap1.extractMin(), 2);
  ASSERT_EQ(heap1.minimum(), 3);
  ASSERT_EQ(heap1.extractMin(), 3);
  ASSERT_EQ(heap1.minimum(), 4);
  ASSERT_EQ(heap1.extractMin(), 4);
  ASSERT_EQ(heap1.minimum(), 5);
  ASSERT_EQ(heap1.extractMin(), 5);
  ASSERT_EQ(heap1.minimum(), 7);
  ASSERT_EQ(heap1.extractMin(), 7);
  ASSERT_EQ(heap1.minimum(), 8);
  ASSERT_EQ(heap1.extractMin(), 8);
  ASSERT_TRUE(heap1.empty());
}

TEST(Bodrov_Daniil_FibonacciHeapTest, DeleteNode) {
  FibonacciHeap<int> heap;
  FibonacciHeapNode<int> *node1 = heap.insert(5);
  FibonacciHeapNode<int> *node2 = heap.insert(10);
  FibonacciHeapNode<int> *node3 = heap.insert(3);
  FibonacciHeapNode<int> *node4 = heap.insert(7);

  heap.deleteNode(node3);

  ASSERT_EQ(heap.minimum(), 5);
  ASSERT_EQ(heap.extractMin(), 5);
  ASSERT_EQ(heap.minimum(), 7);
  ASSERT_EQ(heap.extractMin(), 7);
  ASSERT_EQ(heap.minimum(), 10);
  ASSERT_EQ(heap.extractMin(), 10);
  ASSERT_TRUE(heap.empty());
}
