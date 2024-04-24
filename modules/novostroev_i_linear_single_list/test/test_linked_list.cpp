// Copyright 2024 Novostroev Ivan

#include <gtest/gtest.h>
#include "include/linked_list.h"

TEST(LinkedListTest, Add) {
    LinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    list.add(1);
    ASSERT_EQ(list.size(), 1);
    list.add(2);
    ASSERT_EQ(list.size(), 2);
}

TEST(LinkedListTest, Display) {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);

    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    list.display();

    std::cout.rdbuf(prevcoutbuf);

    std::string output = buffer.str();

    ASSERT_EQ(output, "3 2 1 \n");
}

TEST(LinkedListTest, IsEmpty) {
    LinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());
    list.add(1);
    ASSERT_FALSE(list.isEmpty());
}

TEST(LinkedListTest, Size) {
    LinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    list.add(1);
    ASSERT_EQ(list.size(), 1);
    list.add(2);
    ASSERT_EQ(list.size(), 2);
}

TEST(LinkedListTest, Clear) {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.clear();
    ASSERT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, Remove) {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    ASSERT_TRUE(list.remove(1));
    ASSERT_FALSE(list.remove(3));
    ASSERT_EQ(list.size(), 1);
}

TEST(LinkedListTest, AddToEmptyList) {
    LinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());
    list.add(1);
    ASSERT_FALSE(list.isEmpty());
    ASSERT_EQ(list.size(), 1);
}

TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    LinkedList<int> list2(list1);

    ASSERT_EQ(list1.size(), list2.size());
}

TEST(LinkedListTest, MoveConstructor) {
    LinkedList<int> list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    LinkedList<int> list2(std::move(list1));

    ASSERT_EQ(list2.size(), 3);
    ASSERT_TRUE(list1.isEmpty());
}
