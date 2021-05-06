// Copyright 2021 Gruzdeva Diana

#include <gtest/gtest.h>

#include "include/stack.h"

TEST(Gruzdeva_Diana_Stack, Constructor) {
  ASSERT_NO_THROW(Stack A);
}

TEST(Gruzdeva_Diana_Stack, Push) {
  Stack stack;

  double element = 5.0;

  ASSERT_NO_THROW(stack.push(element));
}

TEST(Gruzdeva_Diana_Stack, Peek) {
  Stack stack;
  double element = 5.0;

  stack.push(element);

  ASSERT_EQ(element, stack.peek());
}

TEST(Gruzdeva_Diana_Stack, PeekThrow) {
  Stack stack;
  double element = 5.0;

  stack.push(element);
  stack.pop();

  ASSERT_ANY_THROW(stack.peek());
}

TEST(Gruzdeva_Diana_Stack, PopNoThrow) {
  Stack stack;
  double element = 5.0;

  stack.push(element);

  ASSERT_NO_THROW(stack.pop());
}

TEST(Gruzdeva_Diana_Stack, PopThrow) {
  Stack stack;

  ASSERT_ANY_THROW(stack.pop());
}

TEST(Gruzdeva_Diana_Stack, Pop) {
  Stack stack;
  double firstElement = 5.0;
  double secondElement = 10.0;

  stack.push(secondElement);
  stack.push(firstElement);
  stack.pop();

  ASSERT_EQ(secondElement, stack.peek());
}

TEST(Gruzdeva_Diana_Stack, Empty) {
  Stack stack;

  ASSERT_EQ(true, stack.isEmpty());
}
