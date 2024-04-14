// Copyright 2024 kutarin Alexandr

#include "include/deque.h"
#include <stdexcept>

Deque::Deque() : front_(nullptr), back_(nullptr) {}

Deque::~Deque() {
    while (!empty()) {
        pop_front();
    }
}

void Deque::push_front(int value) {
    Node* new_node = new Node{value, front_, nullptr};
    if (front_) {
        front_->prev = new_node;
    } else {
        back_ = new_node;
    }
    front_ = new_node;
}

void Deque::push_back(int value) {
    Node* new_node = new Node{value, nullptr, back_};
    if (back_) {
        back_->next = new_node;
    } else {
        front_ = new_node;
    }
    back_ = new_node;
}

int Deque::pop_front() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    int value = front_->value;
    Node* old_front = front_;
    front_ = front_->next;
    if (front_) {
        front_->prev = nullptr;
    } else {
        back_ = nullptr;
    }
    delete old_front;
    return value;
}

int Deque::pop_back() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    int value = back_->value;
    Node* old_back = back_;
    back_ = back_->prev;
    if (back_) {
        back_->next = nullptr;
    } else {
        front_ = nullptr;
    }
    delete old_back;
    return value;
}

bool Deque::empty() const {
    return front_ == nullptr;
}
