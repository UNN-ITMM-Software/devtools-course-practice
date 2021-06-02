// Copyright 2021 Gruzdeva Diana

#include "include/stack.h"

Stack::Stack() {
  top = nullptr;
}

Stack::~Stack() {
  while (!isEmpty()) {
    pop();
  }
}

double Stack::peek() {
  if (!isEmpty()) {
    return top->data;
  } else {
    throw "Stack is empty";
  }
}

void Stack::pop() {
  if (!isEmpty()) {
    NodeStack *tmp;
    tmp = top;
    top = top->next;
    tmp->next = nullptr;
    tmp = nullptr;
  } else {
    throw "Stack is empty";
  }
}

void Stack::push(const double &element) {
  if (top == nullptr) {
    top = new NodeStack;
    top->next = nullptr;
    top->data = element;
  } else {
    NodeStack *tmp = new NodeStack;
    tmp->data = element;
    tmp->next = top;
    top = tmp;
  }
}

bool Stack::isEmpty() {
  return (top == nullptr);
}
