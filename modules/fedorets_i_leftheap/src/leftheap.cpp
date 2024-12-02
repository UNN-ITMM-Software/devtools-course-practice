// Copyright 2024 Fedorets Ilya

#include "include/leftheap.h"

LeftistHeap::Node* LeftistHeap::deepCopy(const Node* node) {
  return node ? new Node(node) : nullptr;
}

LeftistHeap::Node* LeftistHeap::merge(Node* h1, Node* h2) {
  if (h1 == nullptr) return h2;
  if (h2 == nullptr) return h1;

  if (h1->data > h2->data) {
    std::swap(h1, h2);
  }

  h1->right = merge(h1->right, h2);

  if (h1->left == nullptr ||
      (h1->right != nullptr && h1->right->rank > h1->left->rank)) {
    std::swap(h1->left, h1->right);
  }

  h1->rank = (h1->right ? h1->right->rank : 0) + 1;

  return h1;
}

void LeftistHeap::deleteNode(Node* node) {
  if (node == nullptr) return;
  deleteNode(node->left);
  deleteNode(node->right);
  delete node;
}

LeftistHeap& LeftistHeap::operator=(const LeftistHeap& other) {
  if (this != &other) {
    deleteNode(root);

    root = deepCopy(other.root);
  }
  return *this;
}

LeftistHeap& LeftistHeap::operator=(LeftistHeap&& other) noexcept {
  if (this != &other) {
    deleteNode(root);

    root = other.root;
    other.root = nullptr;
  }
  return *this;
}

void LeftistHeap::insert(int val) {
  Node* newNode = new Node(val);
  root = merge(root, newNode);
}

void LeftistHeap::merge(LeftistHeap& other) {
  root = merge(root, other.root);
  other.root = nullptr;
}

int LeftistHeap::deleteMin() {
  if (root == nullptr) {
    throw std::runtime_error("Heap is empty");
  }

  int minVal = root->data;
  Node* oldRoot = root;
  root = merge(root->left, root->right);
  delete oldRoot;

  return minVal;
}

bool LeftistHeap::isEmpty() const { return root == nullptr; }

int LeftistHeap::findMin() const {
  if (root == nullptr) {
    throw std::runtime_error("Heap is empty");
  }
  return root->data;
}

int LeftistHeap::size() const { return countNodes(root); }
int LeftistHeap::countNodes(Node* node) const {
  if (node == nullptr) return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}
