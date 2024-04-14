// Copyright 2024 Filatov Maxim
#ifndef MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_NODE_H_
#define MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_NODE_H_

#include "DoubleLinkedList.h"

template <class T>
class CNode {
    friend class CList<T>;
 private:
    T data;
    CNode<T>* next;
    CNode<T>* prev;
 public:
    explicit CNode(T value);
    ~CNode();
    void set_next(CNode<T>* next_node);
    void set_prev(CNode<T>* prev_node);
    CNode<T>* get_next_node();
    CNode<T>* get_prev_node();
    void set_data(T _data);
    T get_data();
    T check_data() const;
    void print();
    void del_next();
    void del_prev();
    void operator = (CNode<T>* node);
};

#endif  // MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_NODE_H_
