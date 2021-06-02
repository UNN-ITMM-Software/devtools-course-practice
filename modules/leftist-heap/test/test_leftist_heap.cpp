// Copyright 2021 Zhbanova Nadezhda

#include <gtest/gtest.h>

#include <string>

#include "include/leftist_heap.h"

TEST(NodeTest, Can_Create) {
  // Arrange
  Node node(7);

  // Act & Assert
  EXPECT_EQ(7, node.key);
  EXPECT_EQ(NULL, node.left);
  EXPECT_EQ(NULL, node.right);
}

TEST(NodeTest, Can_Merge) {
  // Arrange
  Node xHeap(2);
  Node yHeap(6);

  // Act
  Node* zHeap = Node::merge(&xHeap, &yHeap);

  // Assert
  EXPECT_EQ(2, zHeap->key);
  EXPECT_EQ(6, zHeap->left->key);
}

TEST(LeftistHeapTest, Can_Create_Is_Empty) {
  // Arrange
  LeftistHeap Heap;

  // Act & Assert
  EXPECT_TRUE(Heap.isEmpty());
}

TEST(LeftistHeapTest, Can_Copy_Big_Heap) {
  // Arrange
  LeftistHeap xHeap;
  for (int i = 0; i < 100; ++i) {
    xHeap.insert(i);
  }

  // Act
  LeftistHeap yHeap;
  yHeap = xHeap;

  // Assert
  for (int i = 0; i < 100; ++i) {
    EXPECT_EQ(i, yHeap.deleteMin());
  }
}

TEST(LeftistHeapTest, Copy_Constructors_Is_Operator_Copy) {
  // Arrange
  LeftistHeap xHeap;

  // Act
  xHeap.insert(19);
  xHeap.insert(6);
  LeftistHeap yHeap = xHeap;
  LeftistHeap zHeap(xHeap);

  // Assert
  EXPECT_EQ(yHeap.deleteMin(), zHeap.deleteMin());
  EXPECT_EQ(yHeap.deleteMin(), zHeap.deleteMin());
  EXPECT_EQ(yHeap.isEmpty(), zHeap.isEmpty());
}

TEST(LeftistHeapTest, Can_Merge) {
  // Arrange
  LeftistHeap xHeap, yHeap;

  // Act
  xHeap.insert(20);
  yHeap.insert(50);
  xHeap.merge(&yHeap);

  // Assert
  EXPECT_EQ(20, xHeap.deleteMin());
  EXPECT_EQ(50, xHeap.deleteMin());
}

TEST(LeftistHeapTest, Can_Insert_And_Find_Min) {
  // Arrange
  LeftistHeap Heap;

  // Act
  Heap.insert(5);
  Heap.insert(1);
  Heap.insert(3);

  // Assert
  EXPECT_EQ(1, Heap.findMin());
}

TEST(LeftistHeapTest, Can_Insert_And_Delete_Min) {
  // Arrange
  LeftistHeap Heap;

  // Act
  Heap.insert(10);
  Heap.insert(4);
  Heap.insert(8);

  // Assert
  EXPECT_EQ(4, Heap.deleteMin());
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Find_Min_In_Empty_Heap) {
  // Arrange
  LeftistHeap Heap;

  // Act & Assert
  EXPECT_THROW(Heap.findMin(), std::string);
}

TEST(LeftistHeapTest, Can_Throw_Exception_When_Delete_Min_In_Empty_Heap) {
  // Arrange
  LeftistHeap Heap;

  // Act & Assert
  EXPECT_THROW(Heap.deleteMin(), std::string);
}

TEST(LeftistHeapTest, Heap_Is_Empty_After_Inserting_And_Deleting_Min) {
  // Arrange
  LeftistHeap Heap;

  // Act
  Heap.insert(17);
  Heap.deleteMin();

  // Assert
  EXPECT_TRUE(Heap.isEmpty());
}
