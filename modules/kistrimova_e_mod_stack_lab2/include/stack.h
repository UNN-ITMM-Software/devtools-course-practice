// Copyright 2024 Kistrimova Ekaterina

#pragma once

#include <stdexcept>
#include <utility>
#include <algorithm>

template<class T>
class Stack {
 private:
    int top = -1;
    T* pMem;
    T* minMem;
    int size;

    void oversize() {
        T* tmpMem = new T[size * 2];
        std::copy(pMem, pMem + size, tmpMem);
        delete[] pMem;
        this->pMem = tmpMem;

        T* tmpMinMem = new T[size * 2];
        std::copy(minMem, minMem + size, tmpMinMem);
        delete[] minMem;
        this->minMem = tmpMinMem;

        size *= 2;
    }

 public:
    explicit Stack(int sz = 1) {
        size = sz;

        if (sz <= 0) {
            throw std::invalid_argument("Invalid stack size");
        } else {
            pMem = new T[size];
            minMem = new T[size];
        }
    }

    Stack(const Stack& other) {
        top = other.top;
        size = other.size;
        pMem = new T[size];
        std::copy(other.pMem, other.pMem + size, pMem);
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] pMem;
            top = other.top;
            size = other.size;
            pMem = new T[size];
            std::copy(other.pMem, other.pMem + size, pMem);
        }
        return *this;
    }

    Stack(Stack&& other) noexcept {
        pMem = nullptr;
        size = 0;
        swap(*this, other);
    }

    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            delete[] pMem;
            pMem = nullptr;
            size = 0;
            swap(*this, other);
        }
        return *this;
    }

    int current_size() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }

    void push(const T& value) {
        if (isFull())
            oversize();
        pMem[++top] = value;
        if (top == 0 || value < minMem[top - 1]) {
            minMem[top] = value;
        } else {
            minMem[top] = minMem[top - 1];
        }
    }

    T pop() {
        if (isEmpty())
            throw std::logic_error("Stack is empty");
        top--;
        return pMem[top + 1];
    }

    T getMin() const {
        if (isEmpty())
            throw std::logic_error("Stack is empty");
        return minMem[top];
    }

    T show_top() const {
        if (isEmpty())
            throw std::logic_error("Stack is empty");
        return pMem[top];
    }

    bool operator==(const Stack& other) const {
        if (top != other.top)
            return false;
        if (show_top() != other.show_top())
            return false;
        for (int i = 0; i <= top; ++i) {
            if (pMem[i] != other.pMem[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Stack& other) const {
        return !(*this == other);
    }

    friend void swap(Stack& lhs, Stack& rhs) noexcept {
        std::swap(lhs.top, rhs.top);
        std::swap(lhs.size, rhs.size);
        std::swap(lhs.pMem, rhs.pMem);
    }

    ~Stack() {
        delete[] pMem;
    }
};
