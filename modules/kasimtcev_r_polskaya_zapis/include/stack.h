// Copyright 2024 Kasimtcev Roman

#ifndef  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_STACK_H_
#define  MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_STACK_H_

#include<string>
#include "include/lex.h"

template <class T>
class TStack {
    T* mem;
    int N;
    int i;
 public:
    explicit TStack(int _N = 100);
    TStack(const TStack& v);
    TStack(TStack&& v) noexcept;
    ~TStack();
    void push(T v);
    T pop();
    TStack& operator=(const TStack& v);
    TStack& operator=(TStack&& v) noexcept;
    bool isEmpty() { return i < 0; }
    bool isFull() { return i >= N - 1; }
};

template<class T>
inline TStack<T>::TStack(int _N) :N(_N) {
    i = -1;
    mem = new T[N];
}

template<class T>
inline TStack<T>::TStack(const TStack& v) {
    N = v.N;
    i = v.i;
    mem = new T[N];
    for (int i = 0; i < N - i; i++)
        mem[i] = v.mem[i];
}

template<class T>
inline TStack<T>::~TStack() {
    delete[] mem;
}

template<class T>
inline void TStack<T>::push(T v) {
    i++;
    mem[i] = v;
}

template<class T>
inline T TStack<T>::pop() {
    T tmp = mem[i];
    i--;
    return tmp;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack& v) {
    if (&v == this)
        return *this;
    N = v.N;
    i = v.i;
    delete[] mem;
    mem = new T[N];
    for (int i = 0; i < N - i; i++)
        mem[i] = v.mem[i];

    return *this;
}

template<class T>
inline TStack<T>& TStack<T>::operator=(TStack&& v) noexcept {
    if (this != &v) {
        if (mem != nullptr) delete [] mem;
        N = v.N;
        i = v.i;
        mem = v.mem;
        v.N = 0;
        v.i = 0;
        v.mem = nullptr;
    }

    return *this;
}

template<class T>
inline TStack<T>::TStack(TStack&& v) noexcept {
    N = v.N;
    i = v.i;
    mem = v.mem;

    v.N = 0;
    v.i = 0;
    v.mem = nullptr;
}

template <class T>
class TQueue {
    T* mem;
    int N;
    int first;
    int last;
 public:
    explicit TQueue(int _N = 100);
    TQueue(const TQueue& v);
    ~TQueue();
    void push(T v);
    T pop();
    bool isFull();
    bool isEmpty();
    int next(int ind) { return (ind + 1) % N; }
};

template<class T>
TQueue<T>::TQueue(const TQueue& v) {
    N = v.N;
    first = v.first;
    last = v.last;
    mem = new T[N];
    for (int i = last; i != first; i = next(i))
        mem[i] = v.mem[i];
    if (!isEmpty())
        mem[first] = v.mem[first];
}

template<class T>
TQueue<T>::~TQueue() {
    delete[] mem;
}

template<class T>
void TQueue<T>::push(T v) {
    last = next(last);
    mem[last] = v;
}

template<class T>
T TQueue<T>::pop() {
    T tmp = mem[first];
    first = next(first);
    return tmp;
}

template<class T>
bool TQueue<T>::isFull() {
    return next(next(last)) == first;
}

template<class T>
bool TQueue<T>::isEmpty() {
    return next(last) == first;
}

template<class T>
TQueue<T>::TQueue(int _N) :N(_N) {
    N = _N;
    mem = new T[N];
    first = 0;
    last = N - 1;
}

#endif  // MODULES_KASIMTCEV_R_POLSKAYA_ZAPIS_INCLUDE_STACK_H_
