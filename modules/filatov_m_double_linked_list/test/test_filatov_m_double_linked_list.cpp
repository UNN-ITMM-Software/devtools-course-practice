// Copyright 2024 Filatov Maxim

#include <gtest/gtest.h>
#include <iostream>
#include "include/DoubleLinkedList.h"

TEST(Filatov_Maxim_List_tests, can_create) {
    ASSERT_NO_THROW(CList<int>());
}

TEST(Filatov_Maxim_List_tests, can_push_back) {
    ASSERT_NO_THROW(CList<int>().push_back(1));
}

TEST(Filatov_Maxim_List_tests, can_push_front) {
    ASSERT_NO_THROW(CList<int>().push_front(1));
}

TEST(Filatov_Maxim_List_tests, can_front) {
    CList<int> l;
    l.push_back(1);
    ASSERT_NO_THROW(l.front());
}

TEST(Filatov_Maxim_List_tests, correctly_front) {
    CList<int> l;
    l.push_back(5);
    l.push_back(1);
    l.push_back(1);
    EXPECT_EQ((l.front())->get_data(), 5);
}

TEST(Filatov_Maxim_List_tests, can_back) {
    CList<int> l;
    l.push_back(1);
    ASSERT_NO_THROW(l.back());
}

TEST(Filatov_Maxim_List_tests, correctly_back) {
    CList<int> l;
    l.push_back(1);
    l.push_back(1);
    l.push_back(5);
    EXPECT_EQ((l.back())->get_data(), 5);
}

TEST(Filatov_Maxim_List_tests, correctly_push_back) {
    CList<int> l;
    l.push_back(2);
    EXPECT_EQ((l.front())->get_data(), 2);
}

TEST(Filatov_Maxim_List_tests, correctly_push_front) {
    CList<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_front(3);
    EXPECT_EQ((l.front())->get_data(), 3);
}

TEST(Filatov_Maxim_List_tests, can_size) {
    ASSERT_NO_THROW(CList<int>().size());
}

TEST(Filatov_Maxim_List_tests, correctly_size) {
    CList<int> l;
    size_t size = 3;
    l.push_back(2);
    l.push_back(2);
    l.push_front(3);
    EXPECT_EQ(l.size(), size);
}

TEST(Filatov_Maxim_List_tests, can_clear_head_and_teil) {
    ASSERT_NO_THROW(CList<int>().clearHeadAndTail());
}

TEST(Filatov_Maxim_List_tests, correctly_clear_head_and_teil) {
    CList<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_front(3);
    l.clearHeadAndTail();
    EXPECT_EQ(l.isEmpty(), true);
}

TEST(Filatov_Maxim_List_tests, can_erase) {
    CList<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    ASSERT_NO_THROW(a.erase(0));
}

TEST(Filatov_Maxim_List_tests, correctly_erase) {
    CList<int> l;
    size_t size = 2;
    l.push_back(2);
    l.push_back(2);
    l.push_front(3);
    l.erase(1);
    EXPECT_EQ(l.size(), size);
}

TEST(Filatov_Maxim_List_tests, can_get_index) {
    CList<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    ASSERT_NO_THROW(a[0]);
}

TEST(Filatov_Maxim_List_tests, correctly_get_index) {
    CList<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    int a = l[2]->get_data();
    EXPECT_EQ(a, 3);
}

TEST(Filatov_Maxim_List_tests, can_empty) {
    CList<int> a;
    ASSERT_NO_THROW(a.isEmpty());
}

TEST(Filatov_Maxim_List_tests, correctly_empty) {
    CList<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    EXPECT_NE(l.isEmpty(), true);
    l.clearHeadAndTail();
    EXPECT_EQ(l.isEmpty(), true);
}

TEST(Filatov_Maxim_List_tests, can_reverse) {
    CList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ASSERT_NO_THROW(l.reverse());
}

TEST(Filatov_Maxim_List_tests, correctly_reverse) {
    CList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.reverse();
    EXPECT_EQ(l.front()->get_data(), 3);
    EXPECT_EQ(l.back()->get_data(), 1);
    EXPECT_EQ(l[1]->get_data(), 2);
}

TEST(Filatov_Maxim_List_tests, can_insert) {
    CList<int> l;
    l.push_back(1);
    l.push_back(3);
    ASSERT_NO_THROW(l.insert(2, 1));
}

TEST(Filatov_Maxim_List_tests, correctly_insert) {
    CList<int> l;
    size_t size1 = 2;
    size_t size2 = 3;
    l.push_back(1);
    l.push_back(3);
    EXPECT_EQ(l.size(), size1);
    ASSERT_NO_THROW(l.insert(2, 1));
    EXPECT_EQ(l.size(), size2);
    EXPECT_EQ(l.front()->get_data(), 1);
    EXPECT_EQ(l.back()->get_data(), 3);
    EXPECT_EQ(l[1]->get_data(), 2);
}

TEST(Filatov_Maxim_List_tests, can_clear) {
    CList<int> l;
    l.push_back(1);
    l.push_back(3);
    ASSERT_NO_THROW(l.clear());
}

TEST(Filatov_Maxim_List_tests, correctly_clear) {
    CList<int> l;
    l.push_back(1);
    l.push_back(3);
    l.clear();
    EXPECT_EQ(l.isEmpty(), true);
}

TEST(List_iterator_tests, can_begin) {
    CList<int> l;
    l.push_back(1);
    l.push_back(3);
    ASSERT_NO_THROW(l.begin());
}

TEST(List_iterator_tests, can_end) {
    CList<int> l;
    l.push_back(1);
    l.push_back(3);
    ASSERT_NO_THROW(l.end());
}

TEST(List_iterator_tests, can_iterator) {
    CList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ASSERT_NO_THROW(for (const auto& element : l));
}

TEST(List_iterator_tests, correctly_iterator) {
    CList<int> l;
    bool f1, f2, f3;
    f1 = f2 = f3 = false;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    for (const auto& element : l) {
        if (element.check_data() == 1) f1 = !f1;
        else if (element.check_data() == 1 && f1) ADD_FAILURE();
        else if (element.check_data() == 2) f2 = !f2;
        else if (element.check_data() == 2 && f2) ADD_FAILURE();
        else if (element.check_data() == 3) f3 = !f3;
        else if (element.check_data() == 3 && f3) ADD_FAILURE();
    }
    EXPECT_EQ(f1, true);
    EXPECT_EQ(f2, true);
    EXPECT_EQ(f3, true);
}
