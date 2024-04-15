// Copyright 2024 kutarin Alexandr

#ifndef MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
#define MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class Deque {
 public:
    Deque();
    Deque(const Deque& other);
    ~Deque();
    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();
    bool empty() const;
    size_t size() const;
 private:
    Node<T>* front_;
    Node<T>* back_;
    size_t size_;
};

#endif  // MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
