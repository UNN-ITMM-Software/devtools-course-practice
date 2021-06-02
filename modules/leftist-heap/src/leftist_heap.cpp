// Copyright 2021 Zhbanova Nadezhda

#include "include/leftist_heap.h"

#include <string>

Node::Node(const int _key)
  : key(_key), dist(0), left(NULL), right(NULL) {}

Node* Node::merge(Node* x, Node* y) {
  if (x == NULL) {
    return y;
  }
  if (y == NULL) {
    return x;
  }

  if (x->key > y->key) {
    Node* temp = x;
    x = y;
    y = temp;
  }

  x->right = merge(x->right, y);

  if (x->left == NULL) {
    x->left = x->right;
    x->right = NULL;
  } else {
    if (x->left->dist < x->right->dist) {
      Node* temp = x->left;
      x->left = x->right;
      x->right = temp;
    }
    x->dist = x->right->dist + 1;
  }
  return x;
}

LeftistHeap::LeftistHeap() : root(NULL) {}

LeftistHeap::~LeftistHeap() {
  freeNode(root);
}

LeftistHeap::LeftistHeap(const LeftistHeap& copy) {
  root = copyHeap(copy.root);
}

LeftistHeap& LeftistHeap::operator= (const LeftistHeap& copy) {
  root = copyHeap(copy.root);
  return *this;
}

bool LeftistHeap::isEmpty() const {
  return (root == NULL);
}

void LeftistHeap::freeNode(Node* node) {
  if (node) {
    if (node->left) {
      freeNode(node->left);
    }
    if (node->right) {
      freeNode(node->right);
    }
    delete node;
    node = NULL;
  }
}

Node* LeftistHeap::copyHeap(Node* copyNode) {
  return copyRecursive(copyNode);
}

Node* LeftistHeap::copyRecursive(Node* other) {
  if (other == NULL) {
    return NULL;
  }

  Node* newNode = new Node(other->key);
  newNode->dist = other->dist;

  newNode->left = copyRecursive(other->left);
  newNode->right = copyRecursive(other->right);

  return newNode;
}

void LeftistHeap::merge(LeftistHeap* other) {
  root = Node::merge(root, other->root);

  other->root = NULL;
}

void LeftistHeap::insert(const int _key) {
  Node* newNode = new Node(_key);
  root = Node::merge(root, newNode);
}

int LeftistHeap::findMin() const {
  if (root) {
    return root->key;
  } else {
    throw std::string("Heap is empty.");
  }
}

int LeftistHeap::deleteMin() {
  if (root) {
    Node* _left = root->left;
    Node* _right = root->right;
    int keyValue = root->key;
    delete root;
    root = Node::merge(_left, _right);
    return keyValue;
  } else {
    throw std::string("Heap is empty.");
  }
}
