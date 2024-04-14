// Copyright 2024 Filatov Maxim

#include "include/Node.h"

template <class T>
CNode<T>::CNode(T value) : data(value), next(nullptr) {}

template <class T>
CNode<T>::~CNode() {}

template <class T>
void CNode<T>::set_next(CNode<T>* next_node) {
    next = next_node;
}

template <class T>
void CNode<T>::set_prev(CNode<T>* prev_node) {
    next = prev_node;
}

template <class T>
CNode<T>* CNode<T>::get_next_node() {
    return next;
}

template <class T>
CNode<T>* CNode<T>::get_prev_node() {
    return prev;
}

template <class T>
void CNode<T>::set_data(T _data) {
    data = _data;
}

template <class T>
T CNode<T>::check_data() const {
    return data;
}

template <class T>
T CNode<T>::get_data() {
    return data;
}

template <class T>
void CNode<T>::print() {
    std::cout << data;
}

template <class T>
void CNode<T>::del_next() {
    delete next;
    next = nullptr;
}

template <class T>
void CNode<T>::operator = (CNode<T>* node) {
    data = node->get_data();
    next = node->get_next_node();
    prev = node->get_prev_node();
}
