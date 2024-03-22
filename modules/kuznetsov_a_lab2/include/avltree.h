// Copyright 2024 Kuznetsov Artem
#pragma once

#include <stdexcept>
#include <vector>

template <typename T>
struct Node {
  T key;
  size_t height;

  Node<T>* left;
  Node<T>* right;

  explicit Node(const T& keyValue, size_t heightVal = 0)
      : key{keyValue}, height{heightVal}, left{nullptr}, right{nullptr} {}

  ~Node() {
    delete left;
    delete right;
  }
};

template <typename T>
class avlTree {
 private:
  Node<T>* mRoot;
  size_t mSize;

 public:
  avlTree() : mRoot{nullptr}, mSize{0} {}
  avlTree(const avlTree& other);
  avlTree(avlTree&& other) noexcept;

  ~avlTree() { delete mRoot; }

  void insert(const T& value);
  void remove(const T& value);
  void clear() noexcept;

  [[nodiscard]] size_t size() const noexcept;
  [[nodiscard]] bool empty() const noexcept;
  [[nodiscard]] bool find(const T& value) const noexcept;
  [[nodiscard]] std::vector<T> getTreeAsVector() const;

  avlTree& operator=(const avlTree& other);
  avlTree& operator=(avlTree&& other) noexcept;

  [[nodiscard]] bool operator==(const avlTree& other) const;
  [[nodiscard]] bool operator!=(const avlTree& other) const;

 private:
  Node<T>* insertNode(Node<T>* node, const T& value);
  Node<T>* balancing(Node<T>* node);
  Node<T>* rightRotate(Node<T>* node);
  Node<T>* leftRotate(Node<T>* node);
  int balanceFactor(Node<T>* node);
  void updHeight(Node<T>* node);
  int heightNode(Node<T>* node);

  Node<T>* removeNode(Node<T>* node, const T& value);
  Node<T>* findMinNode(Node<T>* node) noexcept;
  Node<T>* removeMin(Node<T>* node);

  const Node<T>* findNode(const Node<T>* node, const T& value) const noexcept;
  Node<T>* copyTree(const Node<T>* otherRoot);
  void traverseFillVector(const Node<T>* node, std::vector<T>& values) const;
};

template <typename T>
avlTree<T>::avlTree(const avlTree& other) : avlTree() {
  if (!other.empty()) {
    mRoot = copyTree(other.mRoot);
    mSize = other.mSize;
  }
}

template <typename T>
avlTree<T>::avlTree(avlTree&& other) noexcept
    : mRoot{other.mRoot}, mSize{other.mSize} {
  other.mRoot = nullptr;
  other.mSize = 0;
}

////////////////////// PUBLIC METHODS //////////////////////

template <typename T>
void avlTree<T>::insert(const T& value) {
  mRoot = insertNode(mRoot, value);
}

template <typename T>
void avlTree<T>::remove(const T& value) {
  if (empty()) {
    throw std::logic_error{"Tree is empty"};
  }
  mRoot = removeNode(mRoot, value);
}

template <typename T>
void avlTree<T>::clear() noexcept {
  delete mRoot;
  mRoot = nullptr;
  mSize = 0;
}

template <typename T>
[[nodiscard]] size_t avlTree<T>::size() const noexcept {
  return mSize;
}

template <typename T>
[[nodiscard]] bool avlTree<T>::empty() const noexcept {
  return mRoot == nullptr;
}

template <typename T>
[[nodiscard]] bool avlTree<T>::find(const T& value) const noexcept {
  return findNode(mRoot, value) != nullptr;
}

template <typename T>
[[nodiscard]] std::vector<T> avlTree<T>::getTreeAsVector() const {
  std::vector<T> values;

  if (mSize) {
    values.reserve(mSize);
    traverseFillVector(mRoot, values);
  }

  return values;
}

template <typename T>
avlTree<T>& avlTree<T>::operator=(const avlTree& other) {
  if (&other != this) {
    clear();

    if (!other.empty()) {
      mRoot = copyTree(other.mRoot);
      mSize = other.mSize;
    }
  }

  return *this;
}

template <typename T>
avlTree<T>& avlTree<T>::operator=(avlTree&& other) noexcept {
  if (&other != this) {
    clear();
    mSize = other.mSize;
    mRoot = other.mRoot;
    other.mRoot = nullptr;
    other.mSize = 0;
  }
  return *this;
}

template <typename T>
[[nodiscard]] bool avlTree<T>::operator==(const avlTree& other) const {
  if (mSize != other.mSize) return false;

  auto thisValues = getTreeAsVector();
  auto otherValues = other.getTreeAsVector();

  return thisValues == otherValues;
}

template <typename T>
[[nodiscard]] bool avlTree<T>::operator!=(const avlTree& other) const {
  return !(*this == other);
}

////////////////////// PRIVATE METHODS //////////////////////

template <typename T>
Node<T>* avlTree<T>::insertNode(Node<T>* node, const T& value) {
  if (node == nullptr) {
    ++mSize;
    return new Node<T>(value, 0);
  }

  if (value < node->key)
    node->left = insertNode(node->left, value);
  else if (value > node->key)
    node->right = insertNode(node->right, value);
  else
    return node;

  return balancing(node);
}

template <typename T>
Node<T>* avlTree<T>::balancing(Node<T>* node) {
  updHeight(node);
  int balance = balanceFactor(node);

  if (balance == -2) {
    if (balanceFactor(node->left) > 0) node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance == 2) {
    if (balanceFactor(node->right) < 0) node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

template <typename T>
int avlTree<T>::balanceFactor(Node<T>* node) {
  return (heightNode(node->right) + 1) - (heightNode(node->left) + 1);
}

template <typename T>
Node<T>* avlTree<T>::rightRotate(Node<T>* node) {
  Node<T>* A = node;
  Node<T>* B = node->left;

  A->left = B->right;
  B->right = A;

  updHeight(A);
  updHeight(B);

  return B;
}

template <typename T>
Node<T>* avlTree<T>::leftRotate(Node<T>* node) {
  Node<T>* A = node;
  Node<T>* B = node->right;

  A->right = B->left;
  B->left = A;

  updHeight(A);
  updHeight(B);

  return B;
}

template <typename T>
void avlTree<T>::updHeight(Node<T>* node) {
  int leftHeight(heightNode(node->left));
  int rightHeight(heightNode(node->right));

  node->height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
}

template <typename T>
int avlTree<T>::heightNode(Node<T>* node) {
  return (node != nullptr) ? node->height : -1;
}

template <typename T>
Node<T>* avlTree<T>::removeNode(Node<T>* node, const T& value) {
  if (node == nullptr) return nullptr;

  if (value > node->key) {
    node->right = removeNode(node->right, value);
  } else if (value < node->key) {
    node->left = removeNode(node->left, value);
  } else {
    Node<T>* leftNode = node->left;
    Node<T>* rightNode = node->right;

    node->left = nullptr;
    node->right = nullptr;
    delete node;
    --mSize;

    if (rightNode == nullptr) return leftNode;

    Node<T>* minNode = findMinNode(rightNode);

    minNode->right = removeMin(rightNode);
    minNode->left = leftNode;

    return balancing(minNode);
  }

  return balancing(node);
}

template <typename T>
Node<T>* avlTree<T>::findMinNode(Node<T>* node) noexcept {
  return (node->left) ? findMinNode(node->left) : node;
}

template <typename T>
Node<T>* avlTree<T>::removeMin(Node<T>* node) {
  if (node->left == nullptr) return node->right;

  node->left = removeMin(node->left);

  return balancing(node);
}

template <typename T>
const Node<T>* avlTree<T>::findNode(const Node<T>* node,
                                    const T& value) const noexcept {
  if (node == nullptr) return nullptr;

  if (value > node->key) return findNode(node->right, value);
  if (value < node->key) return findNode(node->left, value);

  return node;
}

template <typename T>
Node<T>* avlTree<T>::copyTree(const Node<T>* otherRoot) {
  if (otherRoot == nullptr) return nullptr;

  Node<T>* node = new Node<T>(otherRoot->key, otherRoot->height);

  node->left = copyTree(otherRoot->left);
  node->right = copyTree(otherRoot->right);

  return node;
}

template <typename T>
void avlTree<T>::traverseFillVector(const Node<T>* node,
                                    std::vector<T>& values) const {
  if (node == nullptr) return;

  traverseFillVector(node->left, values);
  values.emplace_back(node->key);
  traverseFillVector(node->right, values);
}
