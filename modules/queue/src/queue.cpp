// Copyright 2021 Tkachev Alexey

#include <string>

#include "include/queue.h"

Queue::Queue(): first(nullptr), last(nullptr) {}

Queue::~Queue() {
    delete first;
}

bool Queue::isEmpty() const {
    return (this->last == nullptr);
}

double Queue::getLastData() const {
    if (this->isEmpty()) {
        throw std::exception();
    }

    return this->last->getData();
}

void Queue::append(double data) {
    Node* new_node = new Node();
    new_node->setDada(data);

    if (this->isEmpty()) {
        this->first = this->last = new_node;
    } else {
        this->last->setNext(new_node);
        this->last = new_node;
    }
}

double Queue::getFirstData() const {
    if (this->isEmpty()) {
        throw std::exception();
    }

    return this->first->getData();
}

void Queue::removeFirst() {
    if (this->first == nullptr) {
        throw std::exception();
    }

    this->first = this->first->getNext();
}

Queue& Queue::operator=(const Queue& other) {
    if (this == &other) {
        return *this;
    }

    if (other.isEmpty()) {
        delete this->first;
        this->first = this->last = nullptr;
        return *this;
    }

    if (!this->isEmpty()) {
        delete this->first;
    }

    this->first = new Node();
    this->last = new Node();
    this->first = new Node(*other.first);
    this->last = new Node(*other.last);

    Node* other_first_next = other.first->getNext();

    Node* this_first = this->first;

    while (other_first_next) {
        this_first->setNext(new Node(*other_first_next));
        this_first = new Node(*other_first_next);
        other_first_next = other_first_next->getNext();
    }

    return *this;
}

unsigned int Queue::getSize() const {
    unsigned int size = 1;
    Node* current = this->first;

    while (current) {
        size++;
        current = current->getNext();
    }

    return size;
}

std::string Queue::toStringData() const {
    if (this->isEmpty()) {
        return " ";
    }

    Node* current = this->first;

    std::string string_queue;

    while (current) {
        string_queue += std::to_string(current->getData()) + " ";
        current = current->getNext();
    }

    return string_queue;
}
