// Copyright 2024 Skotin Alexander

#include <gtest/gtest.h>
#include "include/hashmap.h"

TEST(HashMapTest, CanInsertAndFindElement) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    EXPECT_EQ(map.find(1), "One");
}

TEST(HashMapTest, ReturnsExceptionForNotFound) {
    HashMap<int, std::string> map;
    EXPECT_THROW(map.find(2), std::out_of_range);
}

TEST(HashMapTest, CanRemoveElement) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.remove(1);
    EXPECT_THROW(map.find(1), std::out_of_range);
}

TEST(HashMapTest, IsEmptyAfterCreation) {
    HashMap<int, std::string> map;
    EXPECT_TRUE(map.empty());
}

TEST(HashMapTest, IsNotEmptyAfterInsertion) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    EXPECT_FALSE(map.empty());
}

TEST(HashMapTest, SizeIsCorrectAfterInsertions) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(2, "Two");
    EXPECT_EQ(map.getSize(), 2);
}

TEST(HashMapTest, CanUpdateValueByKey) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(1, "New One");
    EXPECT_EQ(map.find(1), "New One");
}

TEST(HashMapTest, CanBeCleared) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.clear();
    EXPECT_TRUE(map.empty());
}

TEST(HashMapTest, HandlesCollisionsCorrectly) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(2, "Two");
    EXPECT_EQ(map.find(1), "One");
    EXPECT_EQ(map.find(2), "Two");
}
