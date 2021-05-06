// Copyright 2021 Tkachev Alexey

#include "include/node.h"

Node::Node(): data(0.0), next(nullptr) {}

Node::~Node() {
    delete this->next;
}

double Node::getData() const {
    return this->data;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setDada(const double& data_) {
    this->data = data_;
}

void Node::setNext(Node* next_) {
    this->next = next_;
}
