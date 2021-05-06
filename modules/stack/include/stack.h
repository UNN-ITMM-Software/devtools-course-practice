//  Copyright 2021 Gruzdeva Diana

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

class NodeStack {
 public:
  double data;
  NodeStack* next;
};

class Stack {
 private:
  NodeStack* top;

 public:
  Stack();
  ~Stack();
  double peek();
  void pop();
  void push(const double &value);

  bool isEmpty();
};

#endif  // MODULES_STACK_INCLUDE_STACK_H_
