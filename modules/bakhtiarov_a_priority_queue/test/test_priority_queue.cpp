// Copyright 2024 Bakhtiarov Alexander

#include <gtest/gtest.h>
#include "include/priority_queue.h"

TEST(TQueueOnListTest, Constructor) {
    TQueue_on_list<int> queue;
    EXPECT_EQ(queue.get_size(), 0);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(TQueueInsertTest, Constructor) {
    TQueue_insert<int> queue;
    EXPECT_EQ(queue.get_size(), 0);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(TQueueOnListTest, PushAndPop) {
    TQueue_on_list<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    EXPECT_EQ(queue.get_real_size(), 3);
    queue.pop();
    EXPECT_EQ(queue.get_real_size(), 2);
    queue.pop();
    queue.pop();
    EXPECT_TRUE(queue.isEmpty());
}

TEST(TQueueOnListTest, Front) {
    TQueue_on_list<int> queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.front(), 1);
}

TEST(TQueueInsertTest, PushAndPop) {
    TQueue_insert<int> queue(5);
    queue.push({1, 3});
    queue.push({2, 2});
    queue.push({3, 1});
    EXPECT_EQ(queue.get_real_size(), 3);
    queue.pop();
    EXPECT_EQ(queue.get_real_size(), 2);
    queue.pop();
    queue.pop();
    EXPECT_TRUE(queue.isEmpty());
}

TEST(TQueueInsertTest, Front) {
    TQueue_insert<int> queue;
    queue.push({1, 3});
    queue.push({2, 2});
    EXPECT_EQ(queue.front().first, 2);
}
