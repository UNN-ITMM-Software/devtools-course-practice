// Copyright 2024 kutarin Alexandr

#ifndef MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
#define MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_

#include <cstddef>
#include <stdexcept>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class Deque {
 public:
    Deque();
    Deque(const Deque& other);
    Deque(Deque&& other) noexcept;
    ~Deque();
    void push_front(T value);
    void push_back(T value);
    Deque& operator=(const Deque& other);
    Deque& operator=(Deque&& other) noexcept;
    T pop_front();
    T pop_back();
    bool empty() const;
    size_t size() const;
 private:
    Node<T>* front_;
    Node<T>* back_;
    size_t size_;
};

template <typename T>
Deque<T>::Deque(const Deque<T>& other) : front_(nullptr),
 back_(nullptr), size_(0) {
    Node<T>* current = other.front_;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

template <typename T>
Deque<T>::Deque() : front_(nullptr), back_(nullptr) {}

template <typename T>
Deque<T>::Deque(Deque<T>&& other) noexcept : front_(other.front_),
 back_(other.back_), size_(other.size_) {
    other.front_ = nullptr;
    other.back_ = nullptr;
    other.size_ = 0;
}

template <typename T>
Deque<T>::~Deque() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void Deque<T>::push_front(T value) {
    Node<T>* new_node = new Node<T>{value, front_, nullptr};
    if (front_) {
        front_->prev = new_node;
    } else {
        back_ = new_node;
    }
    front_ = new_node;
}

template <typename T>
void Deque<T>::push_back(T value) {
    Node<T>* new_node = new Node<T>{value, nullptr, back_};
    if (back_) {
        back_->next = new_node;
    } else {
        front_ = new_node;
    }
    back_ = new_node;
}

template <typename T>
T Deque<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    T value = front_->value;
    Node<T>* old_front = front_;
    front_ = front_->next;
    if (front_) {
        front_->prev = nullptr;
    } else {
        back_ = nullptr;
    }
    delete old_front;
    return value;
}

template <typename T>
T Deque<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    T value = back_->value;
    Node<T>* old_back = back_;
    back_ = back_->prev;
    if (back_) {
        back_->next = nullptr;
    } else {
        front_ = nullptr;
    }
    delete old_back;
    return value;
}

template <typename T>
bool Deque<T>::empty() const {
    return front_ == nullptr;
}

template <typename T>
size_t Deque<T>::size() const {
    return size_;
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other) {
    if (this != &other) {
        while (!empty()) {
            pop_front();
        }
        Node<T>* current = other.front_;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& other) noexcept {
    if (this != &other) {
        while (!empty()) {
            pop_front();
        }
        front_ = other.front_;
        back_ = other.back_;
        size_ = other.size_;
        other.front_ = nullptr;
        other.back_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

#endif  // MODULES_KUTARIN_A_LAB2_INCLUDE_DEQUE_H_
