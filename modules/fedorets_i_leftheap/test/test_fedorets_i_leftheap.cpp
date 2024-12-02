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

// Test default constructor and isEmpty
TEST_F(LeftistHeapTest, DefaultConstructor) { EXPECT_TRUE(heap.isEmpty()); }

// Test inserting a single element
TEST_F(LeftistHeapTest, InsertSingleElement) {
  heap.insert(5);
  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.findMin(), 5);
}

// Test inserting multiple elements
TEST_F(LeftistHeapTest, InsertMultipleElements) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  EXPECT_FALSE(heap.isEmpty());
  EXPECT_EQ(heap.findMin(), 1);
}

// Test deleteMin operation
TEST_F(LeftistHeapTest, DeleteMin) {
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Elements should be deleted in ascending order
  std::vector<int> sortedElements = elements;
  std::sort(sortedElements.begin(), sortedElements.end());

  for (int expectedMin : sortedElements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

// Test findMin on empty heap throws exception
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

// Test deleteMin on empty heap throws exception
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

// Test heap merge operation
TEST_F(LeftistHeapTest, MergeHeaps) {
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);

  LeftistHeap heap2;
  heap2.insert(7);
  heap2.insert(1);

  heap1.merge(heap2);

  // heap2 should now be empty
  EXPECT_TRUE(heap2.isEmpty());

  // Verify merged heap maintains correct order
  EXPECT_EQ(heap1.deleteMin(), 1);
  EXPECT_EQ(heap1.deleteMin(), 3);
  EXPECT_EQ(heap1.deleteMin(), 5);
  EXPECT_EQ(heap1.deleteMin(), 7);
  EXPECT_TRUE(heap1.isEmpty());
}

// Test repeated insertions and deletions
TEST_F(LeftistHeapTest, RepeatedInsertDelete) {
  std::vector<int> elements = {10, 5, 15, 3, 7, 12, 20};

  // Insert all elements
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Delete half the elements
  for (size_t i = 0; i < elements.size() / 2; ++i) {
    heap.deleteMin();
  }

  // Verify remaining elements are in correct order
  std::vector<int> remainingElements = {10, 12, 15, 20};
  for (int expectedElem : remainingElements) {
    EXPECT_EQ(heap.deleteMin(), expectedElem);
  }

  EXPECT_TRUE(heap.isEmpty());
}

// Test large number of elements
TEST_F(LeftistHeapTest, LargeNumberOfElements) {
  const int NUM_ELEMENTS = 10000;

  // Insert elements in random order
  std::vector<int> elements;
  for (int i = 0; i < NUM_ELEMENTS; ++i) {
    int val = rand() % 100000;
    elements.push_back(val);
    heap.insert(val);
  }

  // Sort the original vector to compare with heap deletion order
  std::sort(elements.begin(), elements.end());

  // Delete and verify order
  for (int expectedMin : elements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

// Test heap with duplicate elements
TEST_F(LeftistHeapTest, DuplicateElements) {
  std::vector<int> elements = {5, 5, 3, 3, 7, 7, 1, 1};

  for (int elem : elements) {
    heap.insert(elem);
  }

  // Verify deletion order maintains stability
  std::vector<int> sortedElements = elements;
  std::sort(sortedElements.begin(), sortedElements.end());

  for (int expectedMin : sortedElements) {
    EXPECT_EQ(heap.deleteMin(), expectedMin);
  }

  EXPECT_TRUE(heap.isEmpty());
}

// Test move semantics with merge
TEST_F(LeftistHeapTest, MoveSemantics) {
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);

  LeftistHeap heap2;
  heap2.insert(7);
  heap2.insert(1);

  // Store original minimum values
  int min1 = heap1.findMin();
  int min2 = heap2.findMin();

  // Merge heaps
  heap1.merge(heap2);

  // Verify merged heap
  EXPECT_FALSE(heap1.isEmpty());
  EXPECT_TRUE(heap2.isEmpty());

  // Verify minimum is the smallest of the two original heaps
  EXPECT_EQ(heap1.findMin(), std::min(min1, min2));
}

// Test edge case with alternating insertions and deletions
TEST_F(LeftistHeapTest, AlternatingInsertDelete) {
  std::vector<int> sequence = {5, 3, 7, 1, 9};

  for (size_t i = 0; i < sequence.size(); ++i) {
    heap.insert(sequence[i]);

    if (i % 2 == 1) {
      // Delete every other insertion
      int min = heap.deleteMin();
      EXPECT_TRUE(min <= sequence[i]);
    }
  }

  // Verify remaining elements
  while (!heap.isEmpty()) {
    heap.deleteMin();
  }
}

// Performance test for many insertions
TEST_F(LeftistHeapTest, PerformanceInsertions) {
  const int LARGE_NUM = 100000;

  // Measure time for large number of insertions
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < LARGE_NUM; ++i) {
    heap.insert(rand() % 1000000);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();

  // Ensure insertions completed within reasonable time
  EXPECT_LT(duration, 1000);  // Less than 1 second

  // Verify heap is not empty after large insertions
  EXPECT_FALSE(heap.isEmpty());
}

// Test copy constructor (if implemented)
TEST_F(LeftistHeapTest, CopyConstructor) {
  // Insert initial elements
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Create a copy
  LeftistHeap heapCopy = heap;
  EXPECT_EQ(heap.findMin(), 1);
  // Verify copy maintains same elements
  EXPECT_EQ(heapCopy.findMin(), 1);

  // Delete from copy should not affect original
  heapCopy.deleteMin();
  EXPECT_EQ(heap.findMin(), 1);
}

// Stress test with mixed operations
TEST_F(LeftistHeapTest, StressTest) {
  const int OPERATIONS = 10000;
  std::vector<int> insertedElements;

  for (int i = 0; i < OPERATIONS; ++i) {
    int operation = rand() % 3;

    switch (operation) {
      case 0:  // Insert
      {
        int val = rand() % 100000;
        heap.insert(val);
        insertedElements.push_back(val);
        break;
      }
      case 1:  // Delete min (if not empty)
      {
        if (!heap.isEmpty()) {
          heap.deleteMin();
        }
        break;
      }
      case 2:  // Find min (if not empty)
      {
        if (!heap.isEmpty()) {
          int min = heap.findMin();
          EXPECT_TRUE(min >= 0);
        }
        break;
      }
    }
  }
}

// Benchmark test for merge operation
TEST_F(LeftistHeapTest, MergeBenchmark) {
  LeftistHeap heap1, heap2;
  const int NUM_ELEMENTS = 5000;

  // Populate first heap
  for (int i = 0; i < NUM_ELEMENTS; ++i) {
    heap1.insert(rand() % 100000);
  }

  // Populate second heap
  for (int i = 0; i < NUM_ELEMENTS; ++i) {
    heap2.insert(rand() % 100000);
  }

  // Measure merge time
  auto start = std::chrono::high_resolution_clock::now();

  heap1.merge(heap2);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();

  // Verify merge completed
  EXPECT_TRUE(heap2.isEmpty());
  EXPECT_FALSE(heap1.isEmpty());

  // Ensure merge was relatively quick
  EXPECT_LT(duration, 100);  // Less than 100 ms
}

// Test copy constructor maintains heap property
TEST_F(LeftistHeapTest, CopyConstructorMaintainsHeapProperty) {
  // Insert elements
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Create a copy
  LeftistHeap heapCopy(heap);

  // Verify copy has same elements in same order
  EXPECT_EQ(heapCopy.findMin(), 1);

  // Delete from copy should not affect original
  heapCopy.deleteMin();
  EXPECT_EQ(heap.findMin(), 1);
}

// Test move constructor transfers ownership
TEST_F(LeftistHeapTest, MoveConstructorTransfersOwnership) {
  // Insert elements
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Store original minimum
  int originalMin = heap.findMin();

  // Move construct
  LeftistHeap movedHeap(std::move(heap));

  // Original heap should be empty
  EXPECT_TRUE(heap.isEmpty());

  // Moved heap should have original elements
  EXPECT_EQ(movedHeap.findMin(), originalMin);
}

// Test move assignment operator
TEST_F(LeftistHeapTest, MoveAssignmentOperator) {
  LeftistHeap sourceHeap;
  sourceHeap.insert(5);
  sourceHeap.insert(3);
  sourceHeap.insert(7);

  LeftistHeap destinationHeap;

  // Store original minimum from source
  int originalMin = sourceHeap.findMin();

  // Move assign
  destinationHeap = std::move(sourceHeap);

  // Source heap should now be empty
  EXPECT_TRUE(sourceHeap.isEmpty());

  // Destination heap should have original elements
  EXPECT_EQ(destinationHeap.findMin(), originalMin);
}

// Test copy assignment with different sized heaps
TEST_F(LeftistHeapTest, CopyAssignmentDifferentSizes) {
  // Create first heap
  LeftistHeap heap1;
  heap1.insert(5);
  heap1.insert(3);
  heap1.insert(7);

  // Create second heap with different elements
  LeftistHeap heap2;
  heap2.insert(1);
  heap2.insert(9);

  // Copy assign
  heap2 = heap1;

  // Verify heap2 now has same elements as heap1
  EXPECT_EQ(heap2.findMin(), 3);

  // Original heap1 remains unchanged
  EXPECT_EQ(heap1.findMin(), 3);

  // Verify sizes match
  EXPECT_EQ(heap1.size(), heap2.size());
}

// Test self-assignment handling
TEST_F(LeftistHeapTest, SelfAssignmentHandling) {
  // Insert some elements
  std::vector<int> elements = {5, 3, 7, 1, 9};
  for (int elem : elements) {
    heap.insert(elem);
  }

  // Store original minimum
  int originalMin = heap.findMin();

  // Self-assignment (should not modify heap)
  heap = heap;

  // Verify heap remains unchanged
  EXPECT_EQ(heap.findMin(), originalMin);
}

// Complex scenario: Multiple copy and move operations
TEST_F(LeftistHeapTest, ComplexCopyMoveScenario) {
  // Create initial heap
  LeftistHeap heap1;
  heap1.insert(10);
  heap1.insert(5);
  heap1.insert(15);

  // Copy construct
  LeftistHeap heap2(heap1);

  // Move construct
  LeftistHeap heap3(std::move(heap1));

  // Copy assign
  LeftistHeap heap4;
  heap4.insert(100);
  heap4 = heap2;

  // Move assign
  LeftistHeap heap5;
  heap5 = std::move(heap2);

  // Verify heap properties
  EXPECT_EQ(heap3.findMin(), 5);
  EXPECT_EQ(heap4.findMin(), 5);
  EXPECT_EQ(heap5.findMin(), 5);

  // Original heaps should be in expected states
  EXPECT_TRUE(heap1.isEmpty());
  EXPECT_TRUE(heap2.isEmpty());
}
