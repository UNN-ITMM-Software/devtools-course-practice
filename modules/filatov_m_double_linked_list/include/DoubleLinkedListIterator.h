// Copyright 2024 Filatov Maxim
#ifndef MODULES_FILATOV_M_DOUBLE_LINKED_LIST_DOUBLELINKEDLISTITERATOR_H_
#define MODULES_FILATOV_M_DOUBLE_LINKED_LIST_DOUBLELINKEDLISTITERATOR_H_

#include "DoubleLinkedList.h"

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

#endif  // MODULES_FILATOV_M_DOUBLE_LINKED_LIST_DOUBLELINKEDLISTITERATOR_H_
