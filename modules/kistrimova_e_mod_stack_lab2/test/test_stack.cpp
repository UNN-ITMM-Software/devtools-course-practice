// Copyright 2024 Kistrimova Ekaterina

#include <gtest/gtest.h>

#include <utility>

#include "include/stack.h"

TEST(Kistrimova_StackTest, throws_when_show_empty_stack_top) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    ASSERT_ANY_THROW(stack.show_top());
}

TEST(Kistrimova_StackTest, throws_when_pop_empty_stack) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    ASSERT_ANY_THROW(stack.pop());
}

TEST(Kistrimova_StackTest, throws_when_get_min_from_empty_stack) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    ASSERT_ANY_THROW(stack.getMin());
}

TEST(Kistrimova_StackTest, can_push_and_pop) {
    Stack<int> stack(3);
    stack.push(1);
    EXPECT_EQ(false, stack.isEmpty());
    EXPECT_EQ(1, stack.show_top());
    EXPECT_EQ(1, stack.getMin());

    int popped = stack.pop();
    EXPECT_EQ(1, popped);
    EXPECT_EQ(true, stack.isEmpty());
}

TEST(Kistrimova_StackTest, can_track_min_element) {
    Stack<int> stack(3);
    stack.push(2);
    stack.push(1);
    stack.push(3);
    EXPECT_EQ(1, stack.getMin());

    stack.pop();
    EXPECT_EQ(1, stack.getMin());

    stack.pop();
    EXPECT_EQ(2, stack.getMin());
}

TEST(Kistrimova_StackTest, can_create_stack_with_custom_size) {
    Stack<int> stack(10);
    EXPECT_EQ(true, stack.isEmpty());
}

TEST(Kistrimova_StackTest, can_push_and_pop_multiple_elements) {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(false, stack.isEmpty());
    EXPECT_EQ(3, stack.show_top());
    EXPECT_EQ(1, stack.getMin());

    int popped = stack.pop();
    EXPECT_EQ(3, popped);
    EXPECT_EQ(2, stack.show_top());
    EXPECT_EQ(1, stack.getMin());

    popped = stack.pop();
    EXPECT_EQ(2, popped);
    EXPECT_EQ(1, stack.show_top());
    EXPECT_EQ(1, stack.getMin());

    popped = stack.pop();
    EXPECT_EQ(1, popped);
    EXPECT_EQ(true, stack.isEmpty());
}
