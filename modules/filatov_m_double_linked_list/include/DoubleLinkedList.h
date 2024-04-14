// Copyright 2024 Filatov Maxim

#ifndef MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_
#define MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_


#include <iostream>
#include <ostream>

template <class T> class iterator;
template <class T> class CNode;
template <class T> class CList;

template <class T>
class iterator {
 public:
    iterator();
    explicit iterator(CNode<T>* ptr);
    ~iterator();
    iterator operator++();
    bool operator!=(const iterator& other) const;
    CNode<T>& operator*();

 private:
    CNode<T>* ptr;
};

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

#endif  // MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_
