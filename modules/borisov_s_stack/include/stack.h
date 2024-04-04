// Copyright 2024 Borisov Saveliy

#pragma once

template<class T>
class Stack {
private:
    int top;
    T* pMem;
    size_t size;

    void oversize() {
        T* tmpMem = new T[size * 2];
        std::copy(pMem, pMem + size, tmpMem);
        delete[] pMem;
        this->pMem = tmpMem;
        size *= 2;
    }
public:
    Stack(size_t sz = 1) : size(sz), top(-1) {
        if (sz <= 0) {
            throw std::exception("Stack size should be greater than zero");
        } else {
            pMem = new T[size];
        }
    }

    size_t current_size() const {
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
            throw std::exception("Stack is empty");
        return pMem[top--];
    }

    T top() const {
        if (isEmpty())
            throw std::exception("Stack is empty");
        return pMem[top];
    }

    ~Stack() {
        delete[] pMem;
    }
};
