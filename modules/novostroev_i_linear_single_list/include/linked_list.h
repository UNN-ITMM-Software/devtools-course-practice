// Copyright 2024 Novostroev Ivan

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

#endif // LINKED_LIST_H
