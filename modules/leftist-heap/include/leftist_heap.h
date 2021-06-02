// Copyright 2021 Zhbanova Nadezhda

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_

class Node {
 public:
  explicit Node(const int key);
  static Node* merge(Node* x, Node* y);

  int key, dist;
  Node* left, * right;
};

class LeftistHeap {
 public:
  LeftistHeap();
  ~LeftistHeap();
  LeftistHeap(const LeftistHeap& copy);
  LeftistHeap& operator= (const LeftistHeap& copy);
  bool isEmpty() const;
  void merge(LeftistHeap* other);
  void insert(const int key);
  int deleteMin();
  int findMin() const;
 private:
  Node* root;

  void freeNode(Node* node);
  Node* copyRecursive(Node* other);
  Node* copyHeap(Node* copyNode);
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
