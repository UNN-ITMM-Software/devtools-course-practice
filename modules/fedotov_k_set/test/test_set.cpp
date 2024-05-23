// Copyright 2024 Fedotov Kirill

#include <gtest/gtest.h>
#include "include/set.h"

TEST(SetTest, AddElements) {
    Set set;
    set.add(1);
    set.add(2);
    set.add(3);

    EXPECT_TRUE(set.contains(1));
    EXPECT_TRUE(set.contains(2));
    EXPECT_TRUE(set.contains(3));
    EXPECT_FALSE(set.contains(4));
}

TEST(SetTest, RemoveElements) {
    Set set;
    set.add(1);
    set.add(2);
    set.add(3);

    set.remove(2);

    EXPECT_TRUE(set.contains(1));
    EXPECT_FALSE(set.contains(2));
    EXPECT_TRUE(set.contains(3));
}

// Объединение множеств
TEST(SetTest, UnionWith) {
    Set set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);

    Set unionSet = set1.unionWith(set2);

    EXPECT_TRUE(unionSet.contains(1));
    EXPECT_TRUE(unionSet.contains(2));
    EXPECT_TRUE(unionSet.contains(3));
    EXPECT_TRUE(unionSet.contains(4));
    EXPECT_TRUE(unionSet.contains(5));
}

// Разность множеств
TEST(SetTest, IntersectWith) {
    Set set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);

    Set intersectSet = set1.intersectWith(set2);

    EXPECT_FALSE(intersectSet.contains(1));
    EXPECT_FALSE(intersectSet.contains(2));
    EXPECT_TRUE(intersectSet.contains(3));
    EXPECT_FALSE(intersectSet.contains(4));
    EXPECT_FALSE(intersectSet.contains(5));
}

TEST(SetTest, Print) {
    Set set;
    set.add(1);
    set.add(2);
    set.add(3);

    testing::internal::CaptureStdout();
    set.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "{ 1 2 3 }\n");
}
