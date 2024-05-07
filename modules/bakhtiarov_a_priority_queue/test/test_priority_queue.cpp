// Copyright 2024 Bakhtiarov Alexander

#include <gtest/gtest.h>
#include "include/priority_queue.h"

TEST(CListTest, TestSize) {
    CList<int> list;
    ASSERT_EQ(static_cast<int>(list.size()), 0);
    list.push_back(1);
    ASSERT_EQ(static_cast<int>(list.size()), 1);
}

TEST(CListTest, TestPushBack) {
    CList<int> list;
    list.push_back(1);
    ASSERT_EQ(list.back()->get_data(), 1);
    list.push_back(2);
    ASSERT_EQ(list.back()->get_data(), 2);
}

TEST(CListTest, TestPushFront) {
    CList<int> list;
    list.push_front(1);
    ASSERT_EQ(list.front()->get_data(), 1);
    list.push_front(2);
    ASSERT_EQ(list.front()->get_data(), 2);
}

TEST(CListTest, TestPopBack) {
    CList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    ASSERT_EQ(list.back()->get_data(), 1);
}

TEST(CListTest, TestPopFront) {
    CList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    ASSERT_EQ(list.front()->get_data(), 1);
}

TEST(CListTest, TestReverse) {
    CList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.reverse();
    ASSERT_EQ(list.front()->get_data(), 2);
    ASSERT_EQ(list.back()->get_data(), 1);
}

TEST(CListTest, TestIsEmpty) {
    CList<int> list;
    ASSERT_TRUE(list.isEmpty());
    list.push_back(1);
    ASSERT_FALSE(list.isEmpty());
}

TEST(CNodeTest, TestConstructor) {
    CNode<int> node(1);
    ASSERT_EQ(node.get_data(), 1);
    ASSERT_EQ(node.get_next_node(), nullptr);
}

TEST(CNodeTest, TestSetNext) {
    CNode<int> node1(1);
    CNode<int> node2(2);
    node1.set_next(&node2);
    ASSERT_EQ(node1.get_next_node(), &node2);
}

TEST(CNodeTest, TestSetData) {
    CNode<int> node(1);
    node.set_data(2);
    ASSERT_EQ(node.get_data(), 2);
}

TEST(CNodeTest, TestPrint) {
    CNode<int> node(1);
    testing::internal::CaptureStdout();
    node.print();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1");
}

TEST(CNodeTest, TestOperatorEqual) {
    CNode<int> node1(1);
    CNode<int> node2(2);
    node1 = &node2;
    ASSERT_EQ(node1.get_data(), 2);
    ASSERT_EQ(node1.get_next_node(), nullptr);
}

TEST(TQueue_on_listTest, TestConstructor) {
    TQueue_on_list<int> queue(3);
    ASSERT_EQ(queue.get_size(), 3);
    ASSERT_EQ(queue.get_real_size(), 0);
}

TEST(TQueue_on_listTest, TestPush) {
    TQueue_on_list<int> queue(3);
    queue.push(1);
    ASSERT_EQ(queue.get_real_size(), 1);
    ASSERT_EQ(queue.front(), 1);
    ASSERT_EQ(queue.back(), 1);
}

TEST(TQueue_on_listTest, TestPop) {
    TQueue_on_list<int> queue(3);
    queue.push(1);
    queue.push(2);
    queue.pop();
    ASSERT_EQ(queue.get_real_size(), 1);
    ASSERT_EQ(queue.front(), 2);
}

TEST(TQueue_on_listTest, TestFrontBack) {
    TQueue_on_list<int> queue(3);
    queue.push(1);
    queue.push(2);
    ASSERT_EQ(queue.front(), 1);
    ASSERT_EQ(queue.back(), 2);
}

TEST(TQueue_on_listTest, TestIsFull) {
    TQueue_on_list<int> queue(3);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    ASSERT_TRUE(queue.isFull());
}

TEST(TQueue_on_listTest, TestIsEmpty) {
    TQueue_on_list<int> queue(3);
    ASSERT_TRUE(queue.isEmpty());
    queue.push(1);
    ASSERT_FALSE(queue.isEmpty());
}

TEST(TQueue_insertTest, PushAndPopTest) {
    TQueue_insert<int> queue(5);
    std::pair<int, int> value(1, 1);

    ASSERT_TRUE(queue.isEmpty());
    ASSERT_FALSE(queue.isFull());

    queue.push(value);
    ASSERT_FALSE(queue.isEmpty());
    ASSERT_EQ(queue.front(), value);
    ASSERT_EQ(queue.back(), value);

    queue.pop();
    ASSERT_TRUE(queue.isEmpty());
}

TEST(TQueue_insertTest, IsFullTest) {
    TQueue_insert<int> queue(2);
    std::pair<int, int> value1(1, 1);
    std::pair<int, int> value2(2, 2);

    queue.push(value1);
    queue.push(value2);
    ASSERT_TRUE(queue.isFull());

    EXPECT_THROW(queue.push(std::pair<int, int>(3, 3)), std::string);
}

TEST(TQueue_insertTest, FrontAndBackTest) {
    TQueue_insert<int> queue(3);
    std::pair<int, int> value1(1, 1);
    std::pair<int, int> value2(2, 2);
    std::pair<int, int> value3(3, 3);

    queue.push(value1);
    queue.push(value2);
    queue.push(value3);

    ASSERT_EQ(queue.front(), value3);
    ASSERT_EQ(queue.back(), value1);
}

TEST(TQueue_insertTest, SizeTest) {
    TQueue_insert<int> queue(3);
    std::pair<int, int> value1(1, 1);
    std::pair<int, int> value2(2, 2);

    queue.push(value1);
    queue.push(value2);

    ASSERT_EQ(queue.get_size(), 3);
    ASSERT_EQ(queue.get_real_size(), 2);
}
