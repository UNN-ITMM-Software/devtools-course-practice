// Copyright 2024 Filatov Maxim

#include "include/DoubleLinkedList.h"

template <class T>
CList<T>::CList() : head(nullptr), tail(nullptr) {}

template <class T>
CList<T>::CList(std::initializer_list<T> init_list) {
    head = nullptr;
    tail = nullptr;
    for (auto element : init_list) {
        this->push_back(element);
    }
}

template <class T>
CList<T>::~CList() {}

template <class T>
size_t CList<T>::size() {
    if (head == nullptr) {
        return 0;
    }
    int size = 0;
    CNode<T>* tmp = head;
    for (; tmp != NULL && tmp != nullptr;
    tmp = tmp->get_next_node()) {
        ++size;
    }
    return size;
}

template <class T>
void CList<T>::push_back(T value) {
    CNode<T>* new_node = new CNode<T>(value);
    if (!isEmpty()) {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
}

template <class T>
void CList<T>::push_front(T value) {
    CNode<T>* new_node = new CNode<T>(value);
    if (!isEmpty()) {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
}

template <class T>
void CList<T>::pop_back() {
    if (head == tail) {
        throw std::logic_error("Head = tail");
    } else if (isEmpty()) {
        throw std::logic_error("List is empty");
    }
    CNode<T>* tmp = (*this)[size() - 2];
    delete tail;
    tail = tmp;
    tail->next = nullptr;
}

template <class T>
void CList<T>::clearHeadAndTail() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void CList<T>::pop_front() {
    if (head != tail) {
        CNode<T>* tmp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete tmp;
    } else {
        clearHeadAndTail();
    }
}

template <class T>
CNode<T>* CList<T>::front() {
    return head;
}

template <class T>
CNode<T>* CList<T>::back() {
    return tail;
}

template <class T>
void CList<T>::insert(T _data, int index) {
    if (index < 0) {
        throw std::out_of_range("out of range");
    }
    if (index == 0) {
        push_front(_data);
        return;
    }
    if (index == size()) {
        push_back(_data);
        return;
    }
    if (index > size()) {
        throw std::out_of_range("out of range");
    }
    CNode<T>* tmp = new CNode<T>(_data);
    CNode<T>* post = (*this)[index];
    CNode<T>* pre = (*this)[index - 1];
    pre->set_next(tmp);
    tmp->set_next(post);
    tmp->set_prev(pre);
    post->set_prev(tmp);
}

template <class T>
void CList<T>::erase(int index) {
    if (index < 0) {
        throw std::out_of_range("out of range");
    }
    if (index == 0) {
        pop_front();
        return;
    }
    if (index == size() - 1) {
        pop_back();
        return;
    }
    if (index >= size() - 1) {
        throw std::out_of_range("out of range");
    }
    CNode<T>* del_elem = (*this)[index];
    CNode<T>* pre = (*this)[index - 1];
    CNode<T>* post = (*this)[index + 1];
    pre->set_next(post);
    if (post) {
        post->set_prev(pre);
    }
    delete del_elem;
}

template <class T>
void CList<T>::reverse() {
    CNode<T>* current = head;
    CNode<T>* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}

template <class T>
CNode<T>* CList<T>::operator[] (int index) {
    CNode<T>* tmp = head;
    int tmp_index = 0;
    for (; tmp_index < index; tmp = tmp->get_next_node()) {
        ++tmp_index;
    }
    return tmp;
}

template <class T>
void CList<T>::clear() {
    for (CNode<T>* node = head, *del_node = head; node != nullptr;
        node = node->get_next_node(),
        (*del_node).set_next(nullptr),
        del_node = node) {}
    clearHeadAndTail();
}

template <class T>
bool CList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
iterator<T> CList<T>::begin() const {
    return iterator<T>(head);
}

template <class T>
iterator<T> CList<T>::end() const {
    return iterator<T>(tail->get_next_node());
}
