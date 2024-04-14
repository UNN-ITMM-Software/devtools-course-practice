// Copyright 2024 kutarin Alexandr

#ifndef MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
#define MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_

struct Node {
    int value;
    Node* next;
    Node* prev;
};

class Deque {
public:
    Deque();
    ~Deque();
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    bool empty() const;
private:
    Node* front_;
    Node* back_;
};

#endif  // MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
