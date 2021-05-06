// Copyright 2021 Novozhilova Ekaterina

#include "include/modified_stack_minimums.h"
#include <vector>
#include <utility>

ModifiedStack::ModifiedStack(int _size) {
    if (_size < 0) {
       throw -1;
    } else {
        st_size = _size;
        last = -1;
        mem.resize(st_size);
    }
}

ModifiedStack::ModifiedStack(const ModifiedStack &tmp) {
    st_size = tmp.st_size;
    last = tmp.last;
    mem.resize(st_size);
    mem = tmp.mem;
}

ModifiedStack& ModifiedStack::operator=(const ModifiedStack &tmp) {
    if (this != &tmp) {
        if (st_size != tmp.st_size) {
            if (st_size != 0) {
                mem.resize(0);
            }
            st_size = tmp.st_size;
            mem.resize(st_size);
        }
        last = tmp.last;
        mem = tmp.mem;
    }
    return *this;
}

bool ModifiedStack::operator==(const ModifiedStack& tmp) const {
    if (st_size != tmp.st_size) {
        return false;
    } else {
        for (int i = 0; i < st_size; i++) {
            if (mem[i] != tmp.mem[i]) {
                return false;
            }
        }
    }
    return true;
}

bool ModifiedStack::operator!=(const ModifiedStack& tmp) const {
    return !this->operator==(tmp);
}

void ModifiedStack::pop() {
    mem[last] = std::pair<double, double>(0.0, 0.0);
    last--;
}

void ModifiedStack::push(double el) {
    if (last == -1) {
        mem[++last] = std::make_pair(el, el);
    } else if (last < st_size - 1) {
        double last_min = mem[last].second;
        if (last_min > el) {
            mem[++last] = std::make_pair(el, el);
        } else if (last_min < el) {
            mem[++last] = std::make_pair(el, last_min);
        }
    } else if (last == st_size - 1) {
        throw -1;
    }
}

bool ModifiedStack::isFull() const {
    if (last == st_size - 1) {
        return true;
    } else {
        return false;
    }
}

bool ModifiedStack::isEmpty() const {
    if (last == -1) {
        return true;
    } else {
        return false;
    }
}

double ModifiedStack::getTop() const {
    return mem[last].first;
}

double ModifiedStack::getMin() const {
    return mem[last].second;
}

int ModifiedStack::getSize() const {
    return st_size;
}

int ModifiedStack::getLast() const {
    return last;
}
