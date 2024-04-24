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
    LinkedList() : head(nullptr) {}
    LinkedList(const LinkedList<T>& other) : head(nullptr) {
        for (Node<T>* node = other.head; node != nullptr; node = node->next) {
            add(node->data);
        }
    }
    LinkedList(LinkedList<T>&& other) : head(other.head) {
        other.head = nullptr;
    }
    ~LinkedList() {
        clear();
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    bool isEmpty() {
        return head == nullptr;

    }
    int size() {
        int count = 0;
        Node<T>* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool remove(T data) {
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

 private:
    Node<T>* head;
};

#endif  // MODULES_NOVOSTROEV_I_LINEAR_SINGLE_LIST_INCLUDE_LINKED_LIST_H_
