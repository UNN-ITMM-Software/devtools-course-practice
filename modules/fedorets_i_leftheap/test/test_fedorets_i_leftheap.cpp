// Copyright 2024 Fedorets Ilya

#include <gtest/gtest.h>

#include <algorithm>
#include <chrono>
#include <vector>

#include "include/leftheap.h"

class LeftistHeapTest : public ::testing::Test {
 protected:
  LeftistHeap heap;
};

TEST_F(LeftistHeapTest, DefaultConstructor) { EXPECT_TRUE(heap.isEmpty()); }

TEST_F(LeftistHeapTest, InsertSingleElement) {
  heap.insert(5);
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.findMin(), 5);
}

TEST_F(LeftistHeapTest, InsertMultipleElements) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.findMin(), 1);
}

TEST_F(LeftistHeapTest, DeleteMin) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  std::vector<int> sortedElements = elements;
  std::sort(sortedElements.begin(), sortedElements.end());

  for (int expectedMin : sortedElements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

TEST_F(LeftistHeapTest, FindMinOnEmptyHeapThrows) {
  EXPECT_THROW(
      {
        try {
          heap.findMin();
        } catch (const std::runtime_error& e) {
          EXPECT_STREQ(e.what(), "Heap is empty");
          throw;
        }
      },
      std::runtime_error);
}

TEST_F(LeftistHeapTest, DeleteMinOnEmptyHeapThrows) {
  EXPECT_THROW(
      {
        try {
          heap.deleteMin();
        } catch (const std::runtime_error& e) {
          EXPECT_STREQ(e.what(), "Heap is empty");
          throw;
        }
      },
      std::runtime_error);
}

TEST_F(LeftistHeapTest, MergeHeaps) {
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);

  LeftistHeap heap2;
  heap2.insert(7);
  heap2.insert(1);

  heap1.merge(heap2);

  EXPECT_TRUE(heap2.isEmpty());

  EXPECT_EQ(heap1.deleteMin(), 1);
  EXPECT_EQ(heap1.deleteMin(), 3);
  EXPECT_EQ(heap1.deleteMin(), 5);
  EXPECT_EQ(heap1.deleteMin(), 7);
  EXPECT_TRUE(heap1.isEmpty());
}

TEST_F(LeftistHeapTest, RepeatedInsertDelete) {
  std::vector<int> elements = {10, 5, 15, 3, 7, 12, 20};

  for (int elem : elements) {
    heap.insert(elem);
  }

  for (size_t i = 0; i < elements.size() / 2; ++i) {
    heap.deleteMin();
  }

  std::vector<int> remainingElements = {10, 12, 15, 20};
  for (int expectedElem : remainingElements) {
    EXPECT_EQ(heap.deleteMin(), expectedElem);
  }

  EXPECT_TRUE(heap.isEmpty());
}

TEST_F(LeftistHeapTest, LargeNumberOfElements) {
  const int NUM_ELEMENTS = 10000;

  std::vector<int> elements;
  for (int i = 0; i < NUM_ELEMENTS; ++i) {
    int val = rand() % 100000;
    elements.push_back(val);
    heap.insert(val);
  }

  std::sort(elements.begin(), elements.end());

  for (int expectedMin : elements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

TEST_F(LeftistHeapTest, DuplicateElements) {
  std::vector<int> elements = {5, 5, 3, 3, 7, 7, 1, 1};

  for (int elem : elements) {
    heap.insert(elem);
  }

  std::vector<int> sortedElements = elements;
  std::sort(sortedElements.begin(), sortedElements.end());

  for (int expectedMin : sortedElements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

TEST_F(LeftistHeapTest, MoveSemantics) {
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);

  LeftistHeap heap2;
  heap2.insert(7);
  heap2.insert(1);

  int min1 = heap1.findMin();
  int min2 = heap2.findMin();

  heap1.merge(heap2);

  EXPECT_FALSE(heap1.isEmpty());
  EXPECT_TRUE(heap2.isEmpty());

  EXPECT_EQ(heap1.findMin(), std::min(min1, min2));
}

TEST_F(LeftistHeapTest, AlternatingInsertDelete) {
  std::vector<int> sequence = {5, 3, 7, 1, 9};

  for (size_t i = 0; i < sequence.size(); ++i) {
    heap.insert(sequence[i]);

    if (i % 2 == 1) {
      int min = heap.deleteMin();
      EXPECT_TRUE(min <= sequence[i]);
    }
  }

  while (!heap.isEmpty()) {
    heap.deleteMin();
  }
}

TEST_F(LeftistHeapTest, CopyConstructor) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  LeftistHeap heapCopy = heap;
  EXPECT_EQ(heap.findMin(), 1);

  EXPECT_EQ(heapCopy.findMin(), 1);

  heapCopy.deleteMin();
  EXPECT_EQ(heap.findMin(), 1);
}

TEST_F(LeftistHeapTest, CopyConstructorMaintainsHeapProperty) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  LeftistHeap heapCopy(heap);

  EXPECT_EQ(heapCopy.findMin(), 1);

  heapCopy.deleteMin();
  EXPECT_EQ(heap.findMin(), 1);
}

TEST_F(LeftistHeapTest, MoveConstructorTransfersOwnership) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  int originalMin = heap.findMin();

  LeftistHeap movedHeap(std::move(heap));

  EXPECT_TRUE(heap.isEmpty());

  EXPECT_EQ(movedHeap.findMin(), originalMin);
}

TEST_F(LeftistHeapTest, MoveAssignmentOperator) {
  LeftistHeap sourceHeap;
  sourceHeap.insert(5);
  sourceHeap.insert(3);
  sourceHeap.insert(7);

  LeftistHeap destinationHeap;

  int originalMin = sourceHeap.findMin();

  destinationHeap = std::move(sourceHeap);

  EXPECT_TRUE(sourceHeap.isEmpty());

  EXPECT_EQ(destinationHeap.findMin(), originalMin);
}

TEST_F(LeftistHeapTest, CopyAssignmentDifferentSizes) {
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);
  heap1.insert(7);

  LeftistHeap heap2;
  heap2.insert(1);
  heap2.insert(9);

  heap2 = heap1;

  EXPECT_EQ(heap2.findMin(), 3);

  EXPECT_EQ(heap1.findMin(), 3);

  EXPECT_EQ(heap1.size(), heap2.size());
}

TEST_F(LeftistHeapTest, SelfAssignmentHandling) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  int originalMin = heap.findMin();

  heap = heap;

  EXPECT_EQ(heap.findMin(), originalMin);
}

TEST_F(LeftistHeapTest, ComplexCopyMoveScenario) {
  LeftistHeap heap1;
  heap1.insert(10);
  heap1.insert(5);
  heap1.insert(15);

  LeftistHeap heap2(heap1);

  LeftistHeap heap3(std::move(heap1));

  LeftistHeap heap4;
  heap4.insert(100);
  heap4 = heap2;

  LeftistHeap heap5;
  heap5 = std::move(heap2);

  EXPECT_EQ(heap3.findMin(), 5);
  EXPECT_EQ(heap4.findMin(), 5);
  EXPECT_EQ(heap5.findMin(), 5);

  EXPECT_TRUE(heap1.isEmpty());
  EXPECT_TRUE(heap2.isEmpty());
}
