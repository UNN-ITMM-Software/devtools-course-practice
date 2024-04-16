// Copyright 2024 Bodrov Daniil

#ifndef MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H_
#define MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H_

#include <limits>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T> struct FibonacciHeapNode {
  T key;
  FibonacciHeapNode<T> *parent;
  FibonacciHeapNode<T> *child;
  FibonacciHeapNode<T> *left;
  FibonacciHeapNode<T> *right;
  int degree;
  bool marked;

  explicit FibonacciHeapNode(const T &key)
      : key(key), parent(nullptr), child(nullptr), left(this), right(this),
        degree(0), marked(false) {}
};

template <typename T> class FibonacciHeap {
 public:
  FibonacciHeap();
  ~FibonacciHeap();

  bool empty() const;
  const T &minimum() const;
  FibonacciHeapNode<T> *insert(const T &key);
  void merge(FibonacciHeap<T> *other);
  T extractMin();
  void decreaseKey(FibonacciHeapNode<T> *node, const T &newKey);
  void deleteNode(FibonacciHeapNode<T> *node);

 private:
  FibonacciHeapNode<T> *minNode;
  std::size_t size;

  void consolidate();
  void link(FibonacciHeapNode<T> *child, FibonacciHeapNode<T> *parent);
  void cut(FibonacciHeapNode<T> *node, FibonacciHeapNode<T> *parent);
  void cascadingCut(FibonacciHeapNode<T> *node);
  void clear(FibonacciHeapNode<T>* heapNode);
};

template <typename T>
FibonacciHeap<T>::FibonacciHeap() : minNode(nullptr), size(0) {}

template <typename T>
FibonacciHeap<T>::~FibonacciHeap() {
  clear(minNode);
}

template <typename T> bool FibonacciHeap<T>::empty() const {
  return minNode == nullptr;
}

template <typename T> const T &FibonacciHeap<T>::minimum() const {
  return minNode->key;
}

template <typename T>
FibonacciHeapNode<T> *FibonacciHeap<T>::insert(const T &key) {
  FibonacciHeapNode<T> *newNode = new FibonacciHeapNode<T>(key);
  if (minNode == nullptr) {
    minNode = newNode;
  } else {
    minNode->left->right = newNode;
    newNode->left = minNode->left;
    minNode->left = newNode;
    newNode->right = minNode;
    if (key < minNode->key)
      minNode = newNode;
  }
  size++;
  return newNode;
}

template <typename T>
void FibonacciHeap<T>::merge(FibonacciHeap<T> *other) {
  // Пока other не пуста, перемещаем элементы из other в основную кучу
  while (!other->empty()) {
    // Извлекаем минимальный узел из other
    FibonacciHeapNode<T> *otherMin = other->minNode;

    // Удаляем минимальный узел из other
    if (other->minNode == other->minNode->right) {
      other->minNode = nullptr;
    } else {
      other->minNode->left->right = other->minNode->right;
      other->minNode->right->left = other->minNode->left;
      other->minNode = other->minNode->right;
    }
    other->size--;

    // Добавляем извлеченный узел в основную кучу
    if (minNode == nullptr) {
      minNode = otherMin;
      minNode->left = minNode->right = minNode;
    } else {
      otherMin->left = minNode;
      otherMin->right = minNode->right;
      minNode->right->left = otherMin;
      minNode->right = otherMin;
      if (otherMin->key < minNode->key) {
        minNode = otherMin;
      }
    }
    size++;
  }
}


template <typename T> T FibonacciHeap<T>::extractMin() {
  FibonacciHeapNode<T> *oldMin = minNode;
  if (oldMin == nullptr)
    return T();

  if (oldMin->child != nullptr) {
    FibonacciHeapNode<T> *child = oldMin->child;
    do {
      FibonacciHeapNode<T> *nextChild = child->right;
      minNode->left->right = child;
      child->left = minNode->left;
      minNode->left = child;
      child->right = minNode;
      child->parent = nullptr;
      child = nextChild;
    } while (child != oldMin->child);
  }
  oldMin->left->right = oldMin->right;
  oldMin->right->left = oldMin->left;
  if (oldMin == oldMin->right) {
    minNode = nullptr;
  } else {
    minNode = oldMin->right;
    consolidate();
  }
  T minKey = oldMin->key;
  delete oldMin;
  size--;
  return minKey;
}

template <typename T>
void FibonacciHeap<T>::decreaseKey(FibonacciHeapNode<T> *node,
                                   const T &newKey) {
  if (newKey > node->key)
    return;
  node->key = newKey;
  FibonacciHeapNode<T> *parent = node->parent;
  if (parent != nullptr && node->key < parent->key) {
    cut(node, parent);
    cascadingCut(parent);
  }
  if (node->key < minNode->key)
    minNode = node;
}

template <typename T>
void FibonacciHeap<T>::deleteNode(FibonacciHeapNode<T> *node) {
  decreaseKey(node, std::numeric_limits<T>::min());
  extractMin();
}

template <typename T> void FibonacciHeap<T>::consolidate() {
  std::vector<FibonacciHeapNode<T> *> degreeTable(2 * size, nullptr);

  // Traverse the root list and merge trees with the same degree
  FibonacciHeapNode<T> *current = minNode;
  do {
    FibonacciHeapNode<T> *next = current->right;
    int degree = current->degree;
    while (degreeTable[degree] != nullptr) {
      FibonacciHeapNode<T> *other = degreeTable[degree];
      if (current->key > other->key)
        std::swap(current, other);
      link(other, current);
      degreeTable[degree] = nullptr;
      degree++;
    }
    degreeTable[degree] = current;
    current = next;
  } while (current != minNode);

  // Reconstruct the root list from the degree table
  minNode = nullptr;
  for (FibonacciHeapNode<T> *node : degreeTable) {
    if (node != nullptr) {
      if (minNode == nullptr) {
        minNode = node;
      } else {
        node->left->right = node->right;
        node->right->left = node->left;
        minNode->left->right = node;
        node->left = minNode->left;
        minNode->left = node;
        node->right = minNode;
        if (node->key < minNode->key)
          minNode = node;
      }
    }
  }
}

template <typename T>
void FibonacciHeap<T>::link(FibonacciHeapNode<T> *child,
                            FibonacciHeapNode<T> *parent) {
  // Remove child from root list
  child->left->right = child->right;
  child->right->left = child->left;

  // Make child a child of parent
  if (parent->child == nullptr) {
    parent->child = child;
    child->left = child;
    child->right = child;
  } else {
    child->left = parent->child;
    child->right = parent->child->right;
    parent->child->right->left = child;
    parent->child->right = child;
  }
  child->parent = parent;
  parent->degree++;
  child->marked = false;
}

template <typename T>
void FibonacciHeap<T>::cut(FibonacciHeapNode<T> *node,
                           FibonacciHeapNode<T> *parent) {
  if (node->right == node) {
    parent->child = nullptr;
  } else {
    node->left->right = node->right;
    node->right->left = node->left;

    if (parent->child == node)
      parent->child = node->right;
  }

  parent->degree--;
  node->left = minNode->left;
  node->right = minNode;
  minNode->left->right = node;
  minNode->left = node;

  node->parent = nullptr;
  node->marked = false;
}

template <typename T>
void FibonacciHeap<T>::cascadingCut(FibonacciHeapNode<T> *node) {
  FibonacciHeapNode<T> *parent = node->parent;
  if (parent != nullptr) {
    if (node->marked) {
      cut(node, parent);
      cascadingCut(parent);
    } else {
      node->marked = true;
    }
  }
}

template <typename T>
void FibonacciHeap<T>::clear(FibonacciHeapNode<T>* heapNode) {
    if (heapNode == nullptr) {
        return;
    }

    FibonacciHeapNode<T>* end = heapNode;
    do {
        clear(heapNode->child);

        FibonacciHeapNode<T>* right = heapNode->right;
        delete heapNode;
        heapNode = right;
    } while (heapNode != end);
}

#endif  // MODULES_BODROV_DANIIL_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_H_
