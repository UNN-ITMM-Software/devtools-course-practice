// Copyright 2024 Bakhtiarov Alexander
#ifndef MODULES_BAKHTIAROV_A_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_BAKHTIAROV_A_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <iostream>
#include <ostream>
#include <string>
#include <utility>
template <class T>
class CNode;
template <class T>
class CList;

template <class T>
class CList {
  friend class CNode<T>;

 private:
  CNode<T>* head;
  CNode<T>* tail;

 public:
  CList() : head(nullptr), tail(nullptr) {}

  ~CList() {}

  size_t size() {
    if (head == nullptr) {
      return 0;
    }
    int size = 0;
    CNode<T>* tmp = head;
    for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) {
      ++size;
    }
    return size;
  }

  void push_back(T value) {
    CNode<T>* new_node = new CNode<T>(value);
    if (!isEmpty()) {
      tail->next = new_node;
      tail = new_node;
    } else {
      head = new_node;
      tail = new_node;
    }
  }

  void push_front(T value) {
    CNode<T>* new_node = new CNode<T>(value);
    CNode<T>* tmp = head;
    if (!isEmpty()) {
      head = new_node;
      head->next = tmp;
    } else {
      head = new_node;
      tail = new_node;
    }
  }

  void pop_back() {
    if (head == tail) {
      throw std::logic_error("Head = tail");
    }
    if (isEmpty()) {
      throw std::logic_error("List is empty");
    }
    CNode<T>* tmp = (*this)[size() - 2];
    tmp->del_next();
    tail = tmp;
  }

  void clearHeadAndTail() {
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
      return;
    }
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
  }

  void pop_front() {
    if (head != tail) {
      CNode<T>* tmp = head;
      head = head->next;
      delete tmp;
      tmp = nullptr;
    } else {
      clearHeadAndTail();
    }
  }

  CNode<T>* front() { return head; }

  CNode<T>* back() { return tail; }

  void insert(T _data, int index) {
    if (index < 0) {
      throw std::out_of_range("out of range");
    }
    if (index == 0) {
      push_front(_data);
      return;
    }
    if (index == static_cast<int>(size()) - 1) {
      push_back(_data);
      return;
    }
    if (index >= static_cast<int>(size()) - 1) {
      throw std::out_of_range("out of range");
    }
    CNode<T>* tmp = new CNode<T>(_data);
    CNode<T>* post = (*this)[index];
    CNode<T>* pre = (*this)[index - 1];
    pre->set_next(tmp);
    tmp->set_next(post);
  }

  void erase(int index) {
    if (index < 0) {
      throw std::out_of_range("out of range");
    }
    if (index == 0) {
      pop_back();
      return;
    }
    if (index == static_cast<int>(size()) - 1) {
      pop_back();
      return;
    }
    if (index >= static_cast<int>(size()) - 1) {
      throw std::out_of_range("out of range");
    }
    CNode<T>* del_elem = (*this)[index];
    CNode<T>* pre = (*this)[index - 1];
    CNode<T>* post = (*this)[index + 1];
    pre->set_next(post);
    delete del_elem;
    del_elem = nullptr;
  }

  CNode<T>* operator[](int index) {
    CNode<T>* tmp = head;
    int tmp_index = 0;
    for (; tmp_index < index; tmp = tmp->get_next_node()) {
      ++tmp_index;
    }
    return tmp;
  }

  bool isEmpty() { return head == nullptr; }

  void reverse() {
    CList<T>* temp = new CList<T>();
    for (; !isEmpty();
         temp->push_front(front()->get_data()), this->pop_front()) {
    }
    (*this) = *temp;
  }
};

template <class T>
class CNode {
  friend class CList<T>;

 private:
  T data;
  CNode<T>* next;

 public:
  explicit CNode(T value) {
    data = value;
    next = nullptr;
  }

  ~CNode() {}

  void set_next(CNode<T>* next_node) { next = next_node; }

  CNode<T>* get_next_node() { return next; }

  void set_data(T _data) { data = _data; }

  T get_data() { return data; }

  void print() { std::cout << data; }

  void del_next() {
    delete next;
    next = nullptr;
  }

  void operator=(CNode<T>* node) {
    data = node->get_data();
    next = node->get_next_node();
  }
};

template <class T>
class Stack;

template <class T>
class TQueue_on_list {
 private:
  int size;
  CList<T> data;

 public:
  TQueue_on_list() {
    data = CList<T>();
    size = 0;
  }
  explicit TQueue_on_list(int _size) {
    data = CList<T>();
    _size < 1 ? throw std::string("Negative value") : NULL;
    size = _size;
  }
  void push(T value) {
    if (isFull()) {
      throw std::string("Queue is full");
    }
    data.push_back(value);
  }
  int get_size() { return size; }
  int get_real_size() { return data.size(); }
  void pop() {
    if (!isEmpty()) {
      data.pop_front();
    }
  }
  CNode<T> operator[](int index) { return *data[index]; }
  T front() { return data.front()->get_data(); }
  T back() { return data.back()->get_data(); }
  bool isFull() { return static_cast<int>(data.size()) >= size; }
  bool isEmpty() { return data.size() == 0; }
};

template <class T>
class TQueue_on_list;

template <class T>
class TQueue_insert : public TQueue_on_list<std::pair<T, int>> {
 private:
  int size;
  CList<std::pair<T, int>> data;

 public:
  TQueue_insert() { data = CList<std::pair<T, int>>(); }
  explicit TQueue_insert(int _size) {
    data = CList<std::pair<T, int>>();
    _size < 1 ? throw std::string("Negative value") : NULL;
    size = _size;
  }
  void push(std::pair<T, int> value) {
    if (isFull()) {
      throw std::string("Queue is full");
    }
    int size = data.size();
    if (size == 0) {
      data.push_back(value);
      return;
    }
    CNode<std::pair<T, int>>* tmp = data.front();
    int index = 0;
    for (; tmp != NULL && tmp != nullptr; tmp = tmp->get_next_node()) {
      if (value.first >= tmp->get_data().first) {
        data.insert(value, index);
        return;
      }
      ++index;
    }
    data.push_back(value);
  }
  int get_size() { return size; }
  int get_real_size() { return data.size(); }
  void pop() {
    if (!isEmpty()) {
      data.pop_front();
    }
  }
  CNode<std::pair<T, int>> operator[](int index) { return *data[index]; }
  std::pair<T, int> front() { return data.front()->get_data(); }
  std::pair<T, int> back() { return data.back()->get_data(); }
  bool isFull() { return static_cast<int>(data.size()) >= size; }
  bool isEmpty() { return data.size() == 0; }
};

#endif  // MODULES_BAKHTIAROV_A_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
