// Copyright 2024 Filatov Maxim
#ifndef MODULES_FILATOV_M_DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H_
#define MODULES_FILATOV_M_DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H_

#include <iostream>
#include <ostream>
#include "DoubleLinkedListIterator.h"
#include "Node.h"

template <class T> class iterator;
template <class T> class CNode;
template <class T> class CList;

template <class T>
class CList {
    friend class CNode<T>;
 private:
    CNode<T>* head;
    CNode<T>* tail;

 public:
    CList();
    CList(std::initializer_list<T> init_list);
    ~CList();
    void push_back(T value);
    void push_front(T value);
    void pop_front();
    void pop_back();
    void clearHeadAndTail();
    void insert(T _data, int index);
    void erase(int index);
    void reverse();
    void clear();
    bool isEmpty() const;
    size_t size();
    CNode<T>* front();
    CNode<T>* back();
    CNode<T>* operator[] (int index);
    iterator<T> begin() const;
    iterator<T> end() const;
};

#endif  // MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_
