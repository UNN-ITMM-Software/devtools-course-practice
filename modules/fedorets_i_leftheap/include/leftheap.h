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

    explicit Node(int val) : data(val), rank(1), left(nullptr), right(nullptr) {}

    // Copy constructor for Node
    explicit Node(const Node* other)
        : data(other->data), rank(other->rank), left(nullptr), right(nullptr) {
      if (other->left) left = new Node(other->left);
      if (other->right) right = new Node(other->right);
    }
  };

  Node* root;

  // Deep copy helper
  Node* deepCopy(const Node* node) { return node ? new Node(node) : nullptr; }

  // Merge helper function
  Node* merge(Node* h1, Node* h2) {
    if (h1 == nullptr) return h2;
    if (h2 == nullptr) return h1;

    // Ensure h1 has smaller root
    if (h1->data > h2->data) {
      std::swap(h1, h2);
    }

    // Merge right subtree
    h1->right = merge(h1->right, h2);

    // Swap children if necessary to maintain leftist property
    if (h1->left == nullptr ||
        (h1->right != nullptr && h1->right->rank > h1->left->rank)) {
      std::swap(h1->left, h1->right);
    }

    // Update rank
    h1->rank = (h1->right ? h1->right->rank : 0) + 1;

    return h1;
  }

  // Recursive delete helper
  void deleteNode(Node* node) {
    if (node == nullptr) return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
  }

 public:
  // Default constructor
  LeftistHeap() : root(nullptr) {}

  // Copy constructor
  LeftistHeap(const LeftistHeap& other) : root(deepCopy(other.root)) {}

  // Move constructor
  LeftistHeap(LeftistHeap&& other) noexcept : root(other.root) {
    other.root = nullptr;
  }

  // Copy assignment operator
  LeftistHeap& operator=(const LeftistHeap& other) {
    if (this != &other) {
      // Delete existing nodes
      deleteNode(root);

      // Deep copy
      root = deepCopy(other.root);
    }
    return *this;
  }

  // Move assignment operator
  LeftistHeap& operator=(LeftistHeap&& other) noexcept {
    if (this != &other) {
      // Delete existing nodes
      deleteNode(root);

      // Move root
      root = other.root;
      other.root = nullptr;
    }
    return *this;
  }

  // Destructor
  ~LeftistHeap() { deleteNode(root); }

  // Insert a new element
  void insert(int val) {
    Node* newNode = new Node(val);
    root = merge(root, newNode);
  }

  // Merge with another heap
  void merge(LeftistHeap& other) {
    root = merge(root, other.root);
    other.root = nullptr;
  }

  // Delete minimum element
  int deleteMin() {
    if (root == nullptr) {
      throw std::runtime_error("Heap is empty");
    }

    int minVal = root->data;
    Node* oldRoot = root;
    root = merge(root->left, root->right);
    delete oldRoot;

    return minVal;
  }

  // Check if heap is empty
  bool isEmpty() const { return root == nullptr; }

  // Peek at minimum element
  int findMin() const {
    if (root == nullptr) {
      throw std::runtime_error("Heap is empty");
    }
    return root->data;
  }

  // Optional: Method to get current heap size
  int size() const { return countNodes(root); }

 private:
  // Helper method to count nodes recursively
  int countNodes(Node* node) const {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
  }
};

#endif  // MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_
