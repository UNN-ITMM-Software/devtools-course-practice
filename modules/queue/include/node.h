// Copyright 2021 Tkachev Alexey

#ifndef MODULES_QUEUE_INCLUDE_NODE_H_
#define MODULES_QUEUE_INCLUDE_NODE_H_

class Node {
 private:
    double data;
    Node* next;

 public:
    Node();
    ~Node();

    void setDada(const double& data_);
    void setNext(Node* next);

    double getData() const;
    Node* getNext() const;
};

#endif  // MODULES_QUEUE_INCLUDE_NODE_H_
