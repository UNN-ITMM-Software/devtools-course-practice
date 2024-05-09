// Copyright 2024 Sokolova Daria

#ifndef MODULES_SOKOLOVA_D_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_SOKOLOVA_D_QUEUE_INCLUDE_QUEUE_H_

#include <iostream>
#include <stdexcept>

#define DEFAULT_QUEUE_SIZE 10

template <class ValueType>
class  Queue {
 private:
    ValueType* buffer;
    size_t head;
    size_t tail;
    size_t count;
    size_t capacity;

 public:
    explicit Queue(size_t size = DEFAULT_QUEUE_SIZE);
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;


    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const ValueType& element);
    void dequeue();
    const ValueType& front() const;
    const ValueType& back() const;
    size_t size() const;
};


#endif  // MODULES_SOKOLOVA_D_QUEUE_INCLUDE_QUEUE_H_
