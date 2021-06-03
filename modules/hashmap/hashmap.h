// Copyright 2021 Tareev Daniil
#ifndef MODULES_HASHMAP_INCLUDE_HASHMAP_H_
#define MODULES_HASHMAP_INCLUDE_HASHMAP_H_

#include <initializer_list>
#include <functional>
#include <utility>

template<typename Key, typename Value>
class hashnode {
public:
    Key key;
    Value value;
    hashnode* next;

    hashnode(const Key& _key, const Value& _value) : key(_key),
        value(_value),
        next(nullptr) {}
};

template<typename Key = int, typename Value = int>
class hashmap {
    using value_type = hashnode<Key, Value>;
public:
    hashmap() = default;
    explicit hashmap(const int& max_size);
    ~hashmap();
    int max_size() { return _max_size; }
    int size() { return _size; }
    void insert(const Key& key, const Value& value);
    void remove(const Key& key);
    Value operator[](const Key& key);
private:
    int hash(const Key& key) { return std::hash<Key>()(key) % _max_size; }
    int _max_size;
    int _size;
    value_type** _buffer;
};

template <typename Key, typename Value>
hashmap<Key, Value>::hashmap(const int& max_size) :_max_size(max_size),
_size(0) {
    _buffer = new value_type * [max_size];
    for (int i = 0; i < max_size; ++i) {
        _buffer[i] = nullptr;
    }
}

template <typename Key, typename Value>
hashmap<Key, Value>::~hashmap() {
    for (int i = 0; i < _max_size; ++i) {
        auto entry = _buffer[i];
        while (entry != nullptr) {
            auto prev = entry;
            entry = entry->next;
            delete prev;
        }
        _buffer[i] = nullptr;
    }
    delete[] _buffer;
}

template <typename Key, typename Value>
Value hashmap<Key, Value>::operator[](const Key& key) {
    auto hashindex = hash(key);
    auto entry = _buffer[hashindex];

    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return Value();
}

template <typename Key, typename Value>
void hashmap<Key, Value>::insert(const Key& key, const Value& value) {
    auto hashindex = hash(key);
    auto next = _buffer[hashindex];
    value_type* prev = nullptr;

    while (next != nullptr && next->key != key) {
        prev = next;
        next = next->next;
    }

    if (next == nullptr) {
        next = new value_type(key, value);
        if (prev == nullptr) {
            _buffer[hashindex] = next;
        }
        else {
            prev->next = next;
        }
    }
    else {
        next->value = value;
    }

    _size++;
}

template <typename Key, typename Value>
void hashmap<Key, Value>::remove(const Key& key) {
    auto hashindex = hash(key);
    auto entry = _buffer[hashindex];
    value_type* prev = nullptr;

    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }

    if (entry == nullptr) {
        return;
    }
    else {
        if (prev == nullptr) {
            _buffer[hashindex] = entry->next;
        }
        else {
            prev->next = entry->next;
        }
        delete entry;
    }
    _size--;
}

#endif  // MODULES_HASHMAP_INCLUDE_HASHMAP_H_