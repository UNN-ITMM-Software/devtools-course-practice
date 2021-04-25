// Copyright 2021 Vodeneev Mikhail

#include <gtest/gtest.h>
#include<stack>

#include "include/hanoi_tower.h"


TEST(Vodeneev_Mikhail_HanoiTowerTest, First_test) {
    ASSERT_EQ(3, 1 + 2);
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, no_exception_during_empty_creation) {
    ASSERT_NO_THROW(Hanoi t);
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, No_exception_during_creation_with_param) {
    ASSERT_NO_THROW(Hanoi t(11));
}

TEST(Vodeneev_Mikhail_HanoiTowerTest,
    Exception_during_creation_with_negative_size) {
    ASSERT_THROW(Hanoi t(-2), int);
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, Get_Size) {
    Hanoi t(10);
    ASSERT_EQ(10, t.Size());
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, Get_Tower) {
    Hanoi t(10);
    std::stack<int> testA, testB = {}, testC = {};
    for (int i = 0; i < 10; i++)
        testA.push(i);
    ASSERT_EQ(testA, t.GetTowerA());
    ASSERT_EQ(testB, t.GetTowerB());
    ASSERT_EQ(testC, t.GetTowerC());
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, Ring) {
    Hanoi a(5);
    std::stack<int> testA = a.GetTowerA(),
        testB = a.GetTowerB(), testC = a.GetTowerC();

    a.ring(5, &testA, &testB, &testC);

    ASSERT_EQ(a.GetTowerA(), testB);
    ASSERT_EQ(a.GetTowerB(), testA);
    ASSERT_EQ(a.GetTowerC(), testC);
}

TEST(Vodeneev_Mikhail_HanoiTowerTest, Ring_with_null_size) {
    Hanoi a(0);
    std::stack<int> testA = a.GetTowerA(),
        testB = a.GetTowerB(), testC = a.GetTowerC();

    a.ring(0, &testA, &testB, &testC);

    ASSERT_EQ(a.GetTowerA(), testB);
    ASSERT_EQ(a.GetTowerB(), testA);
    ASSERT_EQ(a.GetTowerC(), testC);
}


