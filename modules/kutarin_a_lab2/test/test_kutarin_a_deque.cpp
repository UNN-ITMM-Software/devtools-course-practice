// Copyright 2024 kutarin Alexandr

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "include/deque.h"

TEST(DequeTest, PushPopFront) {
    // Arrange
    Deque<int> dq;
    int value = 1;

    // Act
    dq.push_front(value);
    int pop_result = dq.pop_front();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, PushPopBack) {
    // Arrange
    Deque<int> dq;
    int value = 1;

    // Act
    dq.push_back(value);
    int pop_result = dq.pop_back();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, Empty) {
    // Arrange
    Deque<int> dq;

    // Act & Assert
    EXPECT_TRUE(dq.empty());

    // Act
    dq.push_back(1);

    // Assert
    EXPECT_FALSE(dq.empty());
}

TEST(DequeTest, PopEmpty) {
    // Arrange
    Deque<int> dq;

    // Act & Assert
    EXPECT_THROW(dq.pop_front(), std::runtime_error);
    EXPECT_THROW(dq.pop_back(), std::runtime_error);
}

TEST(DequeTest, PushFrontPopBack) {
    // Arrange
    Deque<int> dq;
    int value = 1;

    // Act
    dq.push_front(value);
    int pop_result = dq.pop_back();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, PushBackPopFront) {
    // Arrange
    Deque<int> dq;
    int value = 1;

    // Act
    dq.push_back(value);
    int pop_result = dq.pop_front();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, Order) {
    // Arrange
    Deque<int> dq;
    int value1 = 1;
    int value2 = 2;

    // Act
    dq.push_back(value1);
    dq.push_back(value2);
    int pop_result1 = dq.pop_front();
    int pop_result2 = dq.pop_front();

    // Assert
    EXPECT_EQ(pop_result1, value1);
    EXPECT_EQ(pop_result2, value2);
}

TEST(DequeTest, LargeAmount) {
    // Arrange
    Deque<int> dq;
    int n = 1000;

    // Act & Assert
    for (int i = 0; i < n; ++i) {
        dq.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(dq.pop_front(), i);
    }
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, Double) {
    // Arrange
    Deque<double> dq;
    double value = 1.5;

    // Act
    dq.push_front(value);
    double pop_result = dq.pop_front();

    // Assert
    EXPECT_DOUBLE_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, String) {
    // Arrange
    Deque<std::string> dq;
    std::string value = "test";

    // Act
    dq.push_back(value);
    std::string pop_result = dq.pop_back();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}

TEST(DequeTest, CopyConstructor) {
    // Arrange
    Deque<int> dq1;
    dq1.push_back(1);
    dq1.push_back(2);

    // Act
    Deque<int> dq2 = dq1;

    // Assert
    EXPECT_EQ(dq2.pop_front(), 1);
    EXPECT_EQ(dq2.pop_front(), 2);
    EXPECT_TRUE(dq2.empty());
}

TEST(DequeTest, MoveConstructor) {
    // Arrange
    Deque<int> dq1;
    dq1.push_back(1);
    dq1.push_back(2);

    // Act
    Deque<int> dq2 = std::move(dq1);

    // Assert
    EXPECT_EQ(dq2.pop_front(), 1);
    EXPECT_EQ(dq2.pop_front(), 2);
    EXPECT_TRUE(dq2.empty());
}

TEST(DequeTest, CopyAssignment) {
    // Arrange
    Deque<int> dq1;
    dq1.push_back(1);
    dq1.push_back(2);
    Deque<int> dq2;

    // Act
    dq2 = dq1;

    // Assert
    EXPECT_EQ(dq2.pop_front(), 1);
    EXPECT_EQ(dq2.pop_front(), 2);
    EXPECT_TRUE(dq2.empty());
}

TEST(DequeTest, MoveAssignment) {
    // Arrange
    Deque<int> dq1;
    dq1.push_back(1);
    dq1.push_back(2);
    Deque<int> dq2;

    // Act
    dq2 = std::move(dq1);

    // Assert
    EXPECT_EQ(dq2.pop_front(), 1);
    EXPECT_EQ(dq2.pop_front(), 2);
    EXPECT_TRUE(dq2.empty());
}
