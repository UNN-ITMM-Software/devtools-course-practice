// Copyright 2024 Skotin Alexander

#ifndef DEVTOOLS_COURSE_PRACTICE_MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_H_
#define DEVTOOLS_COURSE_PRACTICE_MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_H_

#include <functional>
#include <stdexcept>
#include <vector>

template <typename KeyType, typename ValueType>
struct Node {
    ValueType value;
    Node<KeyType, ValueType>* next;

    Node(const KeyType& key, const ValueType& value,
        Node<KeyType, ValueType>* next = nullptr)
        : key(key), value(value), next(next) {}
};

template <typename KeyType, typename ValueType>

class HashMap {
 public:
    HashMap();
    ~HashMap();

    void insert(const KeyType& key, const ValueType& value);
    ValueType find(const KeyType& key) const;
    void remove(const KeyType& key);
    void clear();
    bool empty() const;
    size_t getSize() const;

 private:
    Node<KeyType, ValueType>** table;
    size_t capacity;
    size_t size;
    static const size_t defaultCapacity = 16;

    size_t hashFunction(const KeyType& key) const;
};

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap() : capacity(defaultCapacity), size(0) {
    table = new Node<KeyType, ValueType>* [capacity]();
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap() {
    clear();
    delete[] table;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::insert(const KeyType& key,
    const ValueType& value) {
    size_t index = hashFunction(key);
    Node<KeyType, ValueType>* newNode = new Node<KeyType,
        ValueType>(key, value);

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node<KeyType, ValueType>* temp = table[index];
        while (temp->next != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp->key == key) {
            temp->value = value;
            delete newNode;
        } else {
            temp->next = newNode;
        }
    }
    ++size;
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::find(const KeyType& key) const {
    size_t index = hashFunction(key);
    Node<KeyType, ValueType>* temp = table[index];

    while (temp != nullptr) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    throw std::out_of_range("Key not found");
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::remove(const KeyType& key) {
    size_t index = hashFunction(key);
    Node<KeyType, ValueType>* temp = table[index];
    Node<KeyType, ValueType>* prev = nullptr;

    while (temp != nullptr && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    if (prev == nullptr) {
        table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    --size;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::clear() {
    for (size_t i = 0; i < capacity; ++i) {
        Node<KeyType, ValueType>* temp = table[i];
        while (temp != nullptr) {
            Node<KeyType, ValueType>* next = temp->next;
            delete temp;
            temp = next;
        }
        table[i] = nullptr;
    }
    size = 0;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::empty() const {
    return size == 0;
}

template <typename KeyType, typename ValueType>
size_t HashMap<KeyType, ValueType>::getSize() const {
    return size;
}

template <typename KeyType, typename ValueType>
size_t HashMap<KeyType, ValueType>::hashFunction(const KeyType& key) const {
    return std::hash<KeyType>{}(key) % capacity;
}

#endif  // DEVTOOLS_COURSE_PRACTICE_MODULES_SKOTIN_A_HASHMAP_INCLUDE_HASHMAP_H_
