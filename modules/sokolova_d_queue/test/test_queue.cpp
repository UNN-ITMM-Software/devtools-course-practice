// Copyright 2024 Sokolova Daria

#include <gtest/gtest.h>
#include "include/queue.h"

TEST(SokolovaDaria_QueueTest, CanEnqueueElement) {
    Queue<int> q;
    q.enqueue(10);
    EXPECT_EQ(q.front(), 10);
}
TEST(SokolovaDaria_QueueTest,
    CanEnqueueAndDequeueElement) {
    Queue<int> q(1);
    q.enqueue(10);
    EXPECT_TRUE(q.isFull());
    q.dequeue();
    EXPECT_TRUE(q.isEmpty());
}

TEST(SokolovaDaria_QueueTest,
    ThrowsExceptionFrontOrBackOfEmptyQueue) {
    Queue<std::string> q;

    EXPECT_THROW(q.front(), std::runtime_error);
    EXPECT_THROW(q.back(), std::runtime_error);
}

TEST(SokolovaDaria_QueueTest, IsEmptyInitially) {
    Queue<char> q;

    EXPECT_TRUE(q.isEmpty());
}

TEST(SokolovaDaria_QueueTest,
    IsFullAfterEnqueueToCapacity) {
    Queue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);

    EXPECT_TRUE(q.isFull());
}

TEST(SokolovaDaria_QueueTest,
    SizeIncreasesAfterEnqueue) {
    Queue<std::string> q;
    q.enqueue("one");
    q.enqueue("two");
    size_t actualSize = 2;

    EXPECT_EQ(q.size(), actualSize);
}

TEST(SokolovaDaria_QueueTest, CanCopyQueue) {
    Queue<float> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    Queue<float> q2 = q1;

    EXPECT_EQ(q1.size(), q2.size());
    EXPECT_EQ(q1.front(), q2.front());
    EXPECT_EQ(q1.back(), q2.back());
}

TEST(SokolovaDaria_QueueTest,
    CanAssignQueues) {
    Queue<int> q1;
    q1.enqueue(100);
    q1.enqueue(200);
    size_t actualSize = 2;

    Queue<int> q2;
    q2 = q1;

    EXPECT_EQ(q2.size(), actualSize);
    EXPECT_EQ(q2.front(), 100);
    EXPECT_EQ(q2.back(), 200);
}

