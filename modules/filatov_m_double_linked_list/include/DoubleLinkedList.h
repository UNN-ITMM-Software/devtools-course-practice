// Copyright 2024 Filatov Maxim

#ifndef MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_
#define MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_


#include <iostream>
#include <ostream>

template <class T> class iterator;
template <class T> class DoubleLinkedNode;
template <class T> class DoubleLinkedList;

template <class T>
class iterator {
 public:
    iterator();
    explicit iterator(DoubleLinkedNode<T>* ptr);
    ~iterator();
    iterator operator++();
    bool operator!=(const iterator& other) const;
    DoubleLinkedNode<T>& operator*();

 private:
    DoubleLinkedNode<T>* ptr;
};

template <class T>
class DoubleLinkedList {
    friend class DoubleLinkedNode<T>;
 private:
    DoubleLinkedNode<T>* head;
    DoubleLinkedNode<T>* tail;

 public:
    DoubleLinkedList();
    DoubleLinkedList(std::initializer_list<T> init_list);
    ~DoubleLinkedList();
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
    DoubleLinkedNode<T>* front();
    DoubleLinkedNode<T>* back();
    DoubleLinkedNode<T>* operator[] (int index);
    iterator<T> begin() const;
    iterator<T> end() const;
};

template <class T>
class DoubleLinkedNode {
    friend class DoubleLinkedList<T>;
 private:
    T data;
    DoubleLinkedNode<T>* next;
    DoubleLinkedNode<T>* prev;
 public:
    explicit DoubleLinkedNode(T value);
    ~DoubleLinkedNode();
    void set_next(DoubleLinkedNode<T>* next_node);
    void set_prev(DoubleLinkedNode<T>* prev_node);
    DoubleLinkedNode<T>* get_next_node();
    DoubleLinkedNode<T>* get_prev_node();
    void set_data(T _data);
    T get_data();
    T check_data() const;
    void print();
    void del_next();
    void del_prev();
    void operator = (DoubleLinkedNode<T>* node);
};

template <class T>
iterator<T>::iterator() {}

template <class T>
iterator<T>::iterator(DoubleLinkedNode<T>* ptr) : ptr(ptr) {}

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
DoubleLinkedNode<T>& iterator<T>::operator*() {
    return *ptr;
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> init_list) {
    head = nullptr;
    tail = nullptr;
    for (auto element : init_list) {
        this->push_back(element);
    }
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {}

template <class T>
size_t DoubleLinkedList<T>::size() {
    if (head == nullptr) {
        return 0;
    }
    int size = 0;
    DoubleLinkedNode<T>* tmp = head;
    for (; tmp != NULL && tmp != nullptr;
    tmp = tmp->get_next_node()) {
        ++size;
    }
    return size;
}

template <class T>
void DoubleLinkedList<T>::push_back(T value) {
    DoubleLinkedNode<T>* new_node = new DoubleLinkedNode<T>(value);
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
void DoubleLinkedList<T>::push_front(T value) {
    DoubleLinkedNode<T>* new_node = new DoubleLinkedNode<T>(value);
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
void DoubleLinkedList<T>::pop_back() {
    if (head == tail) {
        throw std::logic_error("Head = tail");
    } else if (isEmpty()) {
        throw std::logic_error("List is empty");
    }
    DoubleLinkedNode<T>* tmp = (*this)[size() - 2];
    delete tail;
    tail = tmp;
    tail->next = nullptr;
}

template <class T>
void DoubleLinkedList<T>::clearHeadAndTail() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void DoubleLinkedList<T>::pop_front() {
    if (head != tail) {
        DoubleLinkedNode<T>* tmp = head;
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
DoubleLinkedNode<T>* DoubleLinkedList<T>::front() {
    return head;
}

template <class T>
DoubleLinkedNode<T>* DoubleLinkedList<T>::back() {
    return tail;
}

template <class T>
void DoubleLinkedList<T>::insert(T _data, int index) {
    if (index < 0) {
        throw std::out_of_range("out of range");
    }
    if (index == 0) {
        push_front(_data);
        return;
    }
    if (static_cast<size_t>(index) == size()) {
        push_back(_data);
        return;
    }
    if (static_cast<size_t>(index) > size()) {
        throw std::out_of_range("out of range");
    }
    DoubleLinkedNode<T>* tmp = new DoubleLinkedNode<T>(_data);
    DoubleLinkedNode<T>* post = (*this)[index];
    DoubleLinkedNode<T>* pre = (*this)[index - 1];
    pre->set_next(tmp);
    tmp->set_next(post);
    tmp->set_prev(pre);
    post->set_prev(tmp);
}

template <class T>
void DoubleLinkedList<T>::erase(int index) {
    if (index < 0) {
        throw std::out_of_range("out of range");
    }
    if (index == 0) {
        pop_front();
        return;
    }
    if (static_cast<size_t>(index) == size() - 1) {
        pop_back();
        return;
    }
    if (static_cast<size_t>(index) >= size() - 1) {
        throw std::out_of_range("out of range");
    }
    DoubleLinkedNode<T>* del_elem = (*this)[index];
    DoubleLinkedNode<T>* pre = del_elem->get_prev_node();
    DoubleLinkedNode<T>* post = del_elem->get_next_node();
    pre->set_next(post);
    if (post) {
        post->set_prev(pre);
    }
    delete del_elem;
}

template <class T>
void DoubleLinkedList<T>::reverse() {
    DoubleLinkedNode<T>* current = head;
    DoubleLinkedNode<T>* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        tail = head;
        head = temp->prev;
    }
}

template <class T>
DoubleLinkedNode<T>* DoubleLinkedList<T>::operator[] (int index) {
    DoubleLinkedNode<T>* tmp = head;
    int tmp_index = 0;
    for (; tmp_index < index; tmp = tmp->get_next_node()) {
        ++tmp_index;
    }
    return tmp;
}

template <class T>
void DoubleLinkedList<T>::clear() {
    for (DoubleLinkedNode<T>* node = head, *del_node = head; node != nullptr;
        node = node->get_next_node(),
        (*del_node).set_next(nullptr),
        del_node = node) {}
    clearHeadAndTail();
}

template <class T>
bool DoubleLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
iterator<T> DoubleLinkedList<T>::begin() const {
    return iterator<T>(head);
}

template <class T>
iterator<T> DoubleLinkedList<T>::end() const {
    return iterator<T>(tail->get_next_node());
}

template <class T>
DoubleLinkedNode<T>::DoubleLinkedNode(T value) : data(value), next(nullptr) {}

template <class T>
DoubleLinkedNode<T>::~DoubleLinkedNode() {}

template <class T>
void DoubleLinkedNode<T>::set_next(DoubleLinkedNode<T>* next_node) {
    next = next_node;
}

template <class T>
void DoubleLinkedNode<T>::set_prev(DoubleLinkedNode<T>* prev_node) {
    prev = prev_node;
}

template <class T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::get_next_node() {
    return next;
}

template <class T>
DoubleLinkedNode<T>* DoubleLinkedNode<T>::get_prev_node() {
    return prev;
}

template <class T>
void DoubleLinkedNode<T>::set_data(T _data) {
    data = _data;
}

template <class T>
T DoubleLinkedNode<T>::check_data() const {
    return data;
}

template <class T>
T DoubleLinkedNode<T>::get_data() {
    return data;
}

template <class T>
void DoubleLinkedNode<T>::print() {
    std::cout << data;
}

template <class T>
void DoubleLinkedNode<T>::del_next() {
    delete next;
    next = nullptr;
}

template <class T>
void DoubleLinkedNode<T>::operator = (DoubleLinkedNode<T>* node) {
    data = node->get_data();
    next = node->get_next_node();
    prev = node->get_prev_node();
}

#endif  // MODULES_FILATOV_M_DOUBLE_LINKED_LIST_INCLUDE_DOUBLELINKEDLIST_H_
