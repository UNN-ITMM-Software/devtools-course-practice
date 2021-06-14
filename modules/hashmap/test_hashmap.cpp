// Copyright 2021 Tareev Daniil

#include <gtest/gtest.h>
#include "include/hashmap.h"

TEST(HashMapTest, can_create_hashnode) {
    ASSERT_NO_THROW((hashnode<int, int>(1, 1)));
}

TEST(HashMapTest, can_create_hash_map) {
    ASSERT_NO_THROW(hashmap<>());
}

TEST(HashMapTest, can_create_hash_with_template_params) {
    ASSERT_NO_THROW((hashmap<int, double>()));
}

TEST(HashMapTest, can_get_elems_max_size) {
    hashmap<const char*, double> map(10);

    ASSERT_EQ(10, map.max_size());
}


TEST(HashMapTest, insertion_test) {
    hashmap<int, double> map(10);

    map.insert(15, 6.5);

    ASSERT_DOUBLE_EQ(6.5, map[15]);
}

TEST(HashMapTest, repeatable_insertion_test) {
    hashmap<int, double> map(1);

    map.insert(15, 6.5);
    map.insert(15, 6.5);

    ASSERT_DOUBLE_EQ(6.5, map[15]);
}

TEST(HashMapTest, multiple_insertion_test) {
    hashmap<int, int> map(5);

    map.insert(13, 5);
    map.insert(23, 7);

    ASSERT_EQ(5, map[13]);
}

TEST(HashMapTest, get_count_of_elems) {
    hashmap<int, int> map(2);

    map.insert(1, 2);
    map.insert(3, 4);

    ASSERT_EQ(2, map.size());
}

TEST(HashMapTest, change_size_on_insertion) {
    hashmap<int, int> map(100);

    map.insert(1, 1);

    ASSERT_EQ(1, map.size());
}

TEST(HashMapTest, insert_more_than_capacity) {
    hashmap<int, int> map(1);

    map.insert(1, 1);
    map.insert(2, 2);
    auto f1 = map[1] == 1;
    auto f2 = map[2] == 2;

    ASSERT_TRUE(f1 && f2);
}

TEST(HashMapTest, get_elem_from_hashmap_stringkey) {
    hashmap<const char*, int> map(5);

    map.insert("Mick", 15);

    ASSERT_EQ(15, map["Mick"]);
}

TEST(HashMapTest, get_elem_from_hashmap_intkey) {
    hashmap<int, int> map(1);
    map.insert(15, 10);

    ASSERT_EQ(10, map[15]);
}
TEST(HashMapTest, delete_node_from_hashmap) {
    hashmap<const char*, int> map(10);
    map.insert("Nick", 15);
    map.insert("Ilya", 20);

    map.remove("Nick");

    ASSERT_EQ(1, map.size());
}

TEST(HashMapTest, chain_delete_node_from_hashmap) {
    hashmap<int, int> map(5);
    map.insert(13, 15);
    map.insert(23, 20);

    map.remove(23);

    ASSERT_EQ(1, map.size());
}

TEST(HashMapTest, delete_node_from_hashmap_check_for_ne) {
    hashmap<const char*, int> map(4);
    map.insert("Nick", 15);
    map.insert("Ilya", 20);

    map.remove("Nick");

    ASSERT_NE(15, map["Nick"]);
}