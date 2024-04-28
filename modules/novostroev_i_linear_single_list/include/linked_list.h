// Copyright 2024 Novostroev Ivan

#ifndef MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_
#define MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
 public:
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList(LinkedList<T>&& other);
    LinkedList<T>& operator=(const LinkedList<T>& other);
    LinkedList<T>& operator=(LinkedList<T>&& other);
    ~LinkedList();

    void add(T data);
    void display();
    bool isEmpty();
    int size();
    void clear();
    bool remove(T data);

 private:
    Node<T>* head;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr) {
    for (Node<T>* node = other.head; node != nullptr; node = node->next) {
        add(node->data);
    }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) : head(other.head) {
    other.head = nullptr;
}

// template <typename T>
// LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
//     if (this != &other) {
//         clear();
//         for (Node<T>* node = other.head; node != nullptr; node = node->next) {
//             add(node->data);
//         }
//     }
//     return *this;
// }

// template <typename T>
// LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) {
//     if (this != &other) {
//         clear();
//         head = other.head;
//         other.head = nullptr;
//     }
//     return *this;
// }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::add(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::display() {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
int LinkedList<T>::size() {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
bool LinkedList<T>::remove(T data) {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return false;
    } else {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        return true;
    }
}

#endif  // MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_

