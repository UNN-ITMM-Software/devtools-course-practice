// Copyright 2021 Novozhilova Ekaterina

#ifndef MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_
#define MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_

#include <utility>
#include <vector>

class ModifiedStack {
 private:
    std::vector<std::pair<double, double>> mem;
    int last;
    int st_size;

 public:
    explicit ModifiedStack(int _size = 0);
    ModifiedStack(const ModifiedStack &tmp);
    ~ModifiedStack() {}

    ModifiedStack &operator=(const ModifiedStack &tmp);
    bool operator==(const ModifiedStack& tmp) const;
    bool operator!=(const ModifiedStack& tmp) const;

    void pop();
    void push(double el);

    bool isFull() const;
    bool isEmpty() const;

    double getTop() const;
    double getMin() const;
    int getSize() const;
    int getLast() const;
};

#endif  // MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_
