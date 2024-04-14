// Copyright 2024 Filatov Maxim

#include "include/DoubleLinkedListIterator.h"

template <class T>
iterator<T>::iterator() {}

template <class T>
iterator<T>::iterator(CNode<T>* ptr) : ptr(ptr) {}

template <class T>
iterator<T>::~iterator() {}

template <class T>
iterator<T> iterator<T>::operator++() {
    ptr = ptr->get_next_node();
    return *this;
}

template <class T>
bool iterator<T>::operator!=(const iterator<T>& other) const {
    return ptr != other.ptr;
}

template <class T>
CNode<T>& iterator<T>::operator*() {
    return *ptr;
}
