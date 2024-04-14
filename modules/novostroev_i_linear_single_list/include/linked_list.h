// Copyright 2024 Novostroev Ivan

#ifndef MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_
#define MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_

struct Node {
    int data;
    Node* next;
};

class LinkedList {
 public:
    LinkedList();
    ~LinkedList();

    void add(int data);
    void display();
    bool isEmpty();
    int size();
    void clear();
    bool remove(int data);

 private:
    Node* head;
};

#endif // MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_
