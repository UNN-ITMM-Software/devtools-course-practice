// Copyright 2024 Borisov Saveliy

#pragma once

#include <string>
#include <algorithm>

template<class T>
class Stack {
 private:
    int top = -1;
    T* pMem;
    int size;

    void oversize() {
        T* tmpMem = new T[size * 2];
        std::copy(pMem, pMem + size, tmpMem);
        delete[] pMem;
        this->pMem = tmpMem;
        size *= 2;
    }

 public:
    explicit Stack(int sz = 1) {
        size = sz;

        if (sz <= 0) {
            throw std::string("Stack size should be greater than zero");
        } else {
            pMem = new T[size];
        }
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
    }

    T pop() {
        if (isEmpty())
            throw std::string("Stack is empty");
        return pMem[top--];
    }

    T show_top() const {
        if (isEmpty())
            throw std::string("Stack is empty");
        return pMem[top];
    }

    ~Stack() {
        delete[] pMem;
    }
};
