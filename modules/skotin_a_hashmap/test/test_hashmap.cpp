// Copyright 2024 Skotin Alexander

#include <gtest/gtest.h>
#include "include/hashmap.h"

TEST(Skotin_Alexander_HashMapTest, CanInsertAndFindElement) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    EXPECT_EQ(map.find(1), "One");
}

TEST(Skotin_Alexander_HashMapTest, ReturnsExceptionForNotFound) {
    HashMap<int, std::string> map;
    EXPECT_THROW(map.find(2), std::out_of_range);
}

TEST(Skotin_Alexander_HashMapTest, CanRemoveElement) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.remove(1);
    EXPECT_THROW(map.find(1), std::out_of_range);
}

TEST(Skotin_Alexander_HashMapTest, IsEmptyAfterCreation) {
    HashMap<int, std::string> map;
    EXPECT_TRUE(map.empty());
}

TEST(Skotin_Alexander_HashMapTest, IsNotEmptyAfterInsertion) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    EXPECT_FALSE(map.empty());
}

TEST(Skotin_Alexander_HashMapTest, SizeIsCorrectAfterInsertions) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(2, "Two");
    EXPECT_EQ(map.getSize(), 2u);
}

TEST(Skotin_Alexander_HashMapTest, CanUpdateValueByKey) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(1, "New One");
    EXPECT_EQ(map.find(1), "New One");
}

TEST(Skotin_Alexander_HashMapTest, CanBeCleared) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.clear();
    EXPECT_TRUE(map.empty());
}

TEST(Skotin_Alexander_HashMapTest, HandlesCollisionsCorrectly) {
    HashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(2, "Two");
    EXPECT_EQ(map.find(1), "One");
    EXPECT_EQ(map.find(2), "Two");
}

TEST(Skotin_Alexander_HashMapTest, CanHandleStringKeys) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.insert("banana", 2);
    EXPECT_EQ(map.find("apple"), 1);
    EXPECT_EQ(map.find("banana"), 2);
}

TEST(Skotin_Alexander_HashMapTest, ReturnsExceptionForNotFoundStringKey) {
    HashMap<std::string, int> map;
    EXPECT_THROW(map.find("cherry"), std::out_of_range);
}

TEST(Skotin_Alexander_HashMapTest, CanRemoveStringKey) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.remove("apple");
    EXPECT_THROW(map.find("apple"), std::out_of_range);
}

TEST(Skotin_Alexander_HashMapTest, IsEmptyAfterCreationWithStringKey) {
    HashMap<std::string, int> map;
    EXPECT_TRUE(map.empty());
}

TEST(Skotin_Alexander_HashMapTest, IsNotEmptyAfterInsertionWithStringKey) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    EXPECT_FALSE(map.empty());
}

TEST(Skotin_Alexander_HashMapTest, SizeIsCorrectAfterInsertionsWithStringKeys) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.insert("banana", 2);
    EXPECT_EQ(map.getSize(), 2u);
}

TEST(Skotin_Alexander_HashMapTest, CanUpdateValueByStringKey) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.insert("apple", 100);
    EXPECT_EQ(map.find("apple"), 100);
}

TEST(Skotin_Alexander_HashMapTest, HandlesCollisionsWithStringKeys) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("apple", 100);
    EXPECT_EQ(map.find("apple"), 100);
    EXPECT_EQ(map.find("banana"), 2);
}

TEST(Skotin_Alexander_HashMapTest, CanClearMapWithStringKeys) {
    HashMap<std::string, int> map;
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.clear();
    EXPECT_TRUE(map.empty());
}
