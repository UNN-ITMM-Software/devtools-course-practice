// Copyright 2024 Novostroev Ivan

#include <gtest/gtest.h>
#include "include/linked_list.h"
#include "include/SinglLinkedList.h"

TEST(LinkedListTest, TestConstructor) {
    LinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());
}

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

TEST(LinkedListTest, CopyAssignmentOperator) {
    LinkedList<int> list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    LinkedList<int> list2;
    list2 = list1;

    ASSERT_EQ(list1.size(), list2.size());
    ASSERT_FALSE(list2.isEmpty());
}

TEST(LinkedListTest, CopyAssignmentOperator_EmptyList) {
    LinkedList<int> list1;
    LinkedList<int> list2;
    list2 = list1;

    ASSERT_EQ(list1.size(), list2.size());
    ASSERT_TRUE(list2.isEmpty());
}

TEST(LinkedListTest, MoveAssignmentOperator) {
    LinkedList<int> list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    LinkedList<int> list2;
    list2 = std::move(list1);

    ASSERT_EQ(list2.size(), 3);
    ASSERT_TRUE(list1.isEmpty());
}

TEST(LinkedListTest, MoveAssignmentOperator_EmptyList) {
    LinkedList<int> list1;
    LinkedList<int> list2;
    list2 = std::move(list1);

    ASSERT_EQ(list2.size(), 0);
    ASSERT_TRUE(list1.isEmpty());
    ASSERT_TRUE(list2.isEmpty());
}

TEST(LinkedListTest, RemoveFromEmptyList) {
    LinkedList<int> list;
    ASSERT_FALSE(list.remove(1));
}

TEST(LinkedListTest, RemoveNonExistentElement) {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    ASSERT_FALSE(list.remove(3));
}

TEST(LinkedListTest, AddToNonEmptyList) {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    ASSERT_EQ(list.size(), 3);
    list.add(4);
    ASSERT_EQ(list.size(), 4);
}

TEST(LinkedListTest, RemoveOnlyElement) {
    LinkedList<int> list;
    list.add(1);
    ASSERT_TRUE(list.remove(1));
    ASSERT_TRUE(list.isEmpty());
}

TEST(LinkedListTest, CopyEmptyList) {
    LinkedList<int> list1;
    LinkedList<int> list2(list1);
    ASSERT_TRUE(list2.isEmpty());
}

TEST(LinkedListTest, MoveEmptyList) {
    LinkedList<int> list1;
    LinkedList<int> list2(std::move(list1));
    ASSERT_TRUE(list1.isEmpty());
    ASSERT_TRUE(list2.isEmpty());
}

TEST(SinglLinkedListTest, PushBackTest) {
    SinglLinkedList app;
    app.runApp(3, new const char* [3]{"app", "--push_back", "Rickroll"});
    auto output = app.runApp(2, new const char* [2]{"app", "--print"});
    ASSERT_EQ(output.back(), "Rickroll");
}

TEST(SinglLinkedListTest, PushFrontTest) {
    SinglLinkedList app;
    app.runApp(3, new const char* [3]{"app", "--push_front", "Rickroll"});
    auto output = app.runApp(2, new const char* [2]{"app", "--print"});
    ASSERT_EQ(output.front(), "Rickroll");
}
