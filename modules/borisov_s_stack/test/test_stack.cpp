// Copyright 2024 Borisov Saveliy

#include <gtest/gtest.h>

#include <utility>

#include "include/stack.h"

TEST(Borisov_StackTest, can_create_stack_with_positive_length) {
    ASSERT_NO_THROW(Stack<int> stack(3));
}

TEST(Borisov_StackTest, throws_when_create_stack_with_negative_length) {
    ASSERT_ANY_THROW(Stack<int> stack(-3));
}

TEST(Borisov_StackTest, throws_when_create_stack_with_zero_length) {
    ASSERT_ANY_THROW(Stack<int> stack(0));
}

TEST(Borisov_StackTest, can_show_stack_top) {
    Stack<int> stack(3);

    stack.push(5);

    EXPECT_EQ(5, stack.show_top());
    EXPECT_EQ(false, stack.isEmpty());
}

TEST(Borisov_StackTest, throws_when_show_empty_stack_top) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    ASSERT_ANY_THROW(stack.show_top());
}

TEST(Borisov_StackTest, can_push_int_elem) {
    Stack<int> stack(3);

    stack.push(5);

    EXPECT_EQ(5, stack.show_top());
}

TEST(Borisov_StackTest, can_push_double_elem) {
    Stack<double> stack(3);

    stack.push(3.14);

    ASSERT_DOUBLE_EQ(stack.show_top(), 3.14);
}

TEST(Borisov_StackTest, can_push_elem_into_full_stack) {
    Stack<int> stack(1);
    stack.push(1);
    EXPECT_EQ(true, stack.isFull());
    stack.push(2);
    EXPECT_EQ(2, stack.show_top());
}

TEST(Borisov_StackTest, can_pop_elem) {
    Stack<int> stack(2);

    stack.push(1);
    stack.push(2);

    EXPECT_EQ(2, stack.pop());
    EXPECT_EQ(1, stack.show_top());
    EXPECT_EQ(1, stack.pop());
    EXPECT_EQ(true, stack.isEmpty());
}

TEST(Borisov_StackTest, throws_when_pop_elem_from_empty_stack) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    ASSERT_ANY_THROW(stack.pop());
}

TEST(Borisov_StackTest, can_check_stack_is_empty) {
    Stack<int> stack(3);
    EXPECT_EQ(true, stack.isEmpty());
    stack.push(1);
    EXPECT_EQ(false, stack.isEmpty());
}

TEST(Borisov_StackTest, can_check_stack_is_full) {
    Stack<int> stack(1);
    EXPECT_EQ(false, stack.isFull());
    stack.push(1);
    EXPECT_EQ(true, stack.isFull());
}

TEST(Borisov_StackTest, can_get_current_stack_size) {
    Stack<int> stack(3);
    EXPECT_EQ(0, stack.current_size());
    stack.push(1);
    EXPECT_EQ(1, stack.current_size());
}

TEST(Borisov_StackTest, can_clear_stack) {
    Stack<int> stack(3);
    stack.push(1);
    EXPECT_EQ(false, stack.isEmpty());
    stack.clear();
    EXPECT_EQ(true, stack.isEmpty());
}

TEST(Borisov_StackTest, can_copy_stack) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2 = stack1;

    EXPECT_EQ(stack1.pop(), stack2.pop());
    EXPECT_EQ(stack1.pop(), stack2.pop());
}

TEST(Borisov_StackTest, can_assign_stack) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2(5);
    stack2 = stack1;

    EXPECT_EQ(stack1.pop(), stack2.pop());
    EXPECT_EQ(stack1.pop(), stack2.pop());
}

TEST(Borisov_StackTest, can_move_stack) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2(std::move(stack1));

    EXPECT_EQ(true, stack1.isEmpty());
    EXPECT_EQ(2, stack2.pop());
    EXPECT_EQ(1, stack2.pop());
}

TEST(Borisov_StackTest, can_assign_move_stack) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2(5);
    stack2 = std::move(stack1);

    EXPECT_EQ(true, stack1.isEmpty());
    EXPECT_EQ(2, stack2.pop());
    EXPECT_EQ(1, stack2.pop());
}

TEST(Borisov_StackTest, eq_oper_returns_true_for_eq_stacks) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2 = stack1;

    EXPECT_TRUE(stack1 == stack2);
}

TEST(Borisov_StackTest, eq_oper_returns_false_for_uneq_stacks) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2(3);
    stack2.push(1);
    stack2.push(3);

    EXPECT_FALSE(stack1 == stack2);
}

TEST(Borisov_StackTest, ineq_oper_returns_true_for_uneq_stacks) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2(3);
    stack2.push(1);
    stack2.push(3);

    EXPECT_TRUE(stack1 != stack2);
}

TEST(Borisov_StackTest, ineq_oper_returns_false_for_eq_stacks) {
    Stack<int> stack1(3);
    stack1.push(1);
    stack1.push(2);

    Stack<int> stack2 = stack1;

    EXPECT_FALSE(stack1 != stack2);
}
