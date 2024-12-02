// Copyright 2024 Fedorets Ilya

#ifndef MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_
#define MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_

#include <algorithm>
#include <iostream>

class LeftistHeap {
 private:
  struct Node {
    int data;
    int rank;
    Node* left;
    Node* right;

    explicit Node(int val)
        : data(val), rank(1), left(nullptr), right(nullptr) {}

    explicit Node(const Node* other)
        : data(other->data), rank(other->rank), left(nullptr), right(nullptr) {
      if (other->left) left = new Node(other->left);
      if (other->right) right = new Node(other->right);
    }
  };

  Node* root;

  Node* deepCopy(const Node* node);
  Node* merge(Node* h1, Node* h2);
  void deleteNode(Node* node);

 public:
  LeftistHeap() : root(nullptr) {}

  LeftistHeap(const LeftistHeap& other) : root(deepCopy(other.root)) {}

  LeftistHeap(LeftistHeap&& other) noexcept : root(other.root) {
    other.root = nullptr;
  }

  LeftistHeap& operator=(const LeftistHeap& other);
  LeftistHeap& operator=(LeftistHeap&& other) noexcept;

  ~LeftistHeap() { deleteNode(root); }

  void insert(int val);
  void merge(LeftistHeap& other);
  int deleteMin();
  bool isEmpty() const;
  int findMin() const;
  int size() const;

 private:
  int countNodes(Node* node) const;
};

#endif  // MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_
