// Copyright 2024 kutarin Alexandr

#include <gtest/gtest.h>
#include <iostream>
#include "include/deque.h"

TEST(DequeTest, PushPopFront) {
    // Arrange
    Deque dq;
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
    Deque dq;
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
    Deque dq;

    // Act & Assert
    EXPECT_TRUE(dq.empty());

    // Act
    dq.push_back(1);

    // Assert
    EXPECT_FALSE(dq.empty());
}

TEST(DequeTest, PopEmpty) {
    // Arrange
    Deque dq;

    // Act & Assert
    EXPECT_THROW(dq.pop_front(), std::runtime_error);
    EXPECT_THROW(dq.pop_back(), std::runtime_error);
}

TEST(DequeTest, PushFrontPopBack) {
    // Arrange
    Deque dq;
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
    Deque dq;
    int value = 1;

    // Act
    dq.push_back(value);
    int pop_result = dq.pop_front();

    // Assert
    EXPECT_EQ(pop_result, value);
    EXPECT_TRUE(dq.empty());
}
