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

TEST(Kistrimova_StackTest, can_handle_stack_overflow) {
    Stack<int> stack(2);
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.current_size());

    // Попытка добавить элемент в уже заполненный стек
    ASSERT_NO_THROW(stack.push(3));
    EXPECT_EQ(3, stack.current_size());
    EXPECT_EQ(3, stack.show_top());
    EXPECT_EQ(1, stack.getMin());
}

TEST(Kistrimova_StackTest, throws_when_create_stack_with_negative_size) {
    // Попытка создать стек с отрицательным размером
    ASSERT_ANY_THROW(Stack<int> stack(-1));
}

// Тесты для типа данных double
TEST(Kistrimova_StackTest, can_handle_double_data_type) {
    Stack<double> stack(3);
    stack.push(1.1);
    stack.push(2.2);
    stack.push(3.3);
    EXPECT_EQ(false, stack.isEmpty());
    EXPECT_DOUBLE_EQ(3.3, stack.show_top());
    EXPECT_DOUBLE_EQ(1.1, stack.getMin());

    double popped = stack.pop();
    EXPECT_DOUBLE_EQ(3.3, popped);
    EXPECT_DOUBLE_EQ(2.2, stack.show_top());
    EXPECT_DOUBLE_EQ(1.1, stack.getMin());

    popped = stack.pop();
    EXPECT_DOUBLE_EQ(2.2, popped);
    EXPECT_DOUBLE_EQ(1.1, stack.show_top());
    EXPECT_DOUBLE_EQ(1.1, stack.getMin());

    popped = stack.pop();
    EXPECT_DOUBLE_EQ(1.1, popped);
    EXPECT_EQ(true, stack.isEmpty());
}

// Тесты для типа данных std::string
TEST(Kistrimova_StackTest, can_handle_string_data_type) {
    Stack<std::string> stack(3);
    stack.push("Hello");
    stack.push("World");
    stack.push("!");
    EXPECT_EQ(false, stack.isEmpty());
    EXPECT_EQ("!", stack.show_top());
    EXPECT_EQ("!", stack.getMin());

    std::string popped = stack.pop();
    EXPECT_EQ("!", popped);
    EXPECT_EQ("World", stack.show_top());
    EXPECT_EQ("Hello", stack.getMin());

    popped = stack.pop();
    EXPECT_EQ("World", popped);
    EXPECT_EQ("Hello", stack.show_top());
    EXPECT_EQ("Hello", stack.getMin());

    popped = stack.pop();
    EXPECT_EQ("Hello", popped);
    EXPECT_EQ(true, stack.isEmpty());
}
