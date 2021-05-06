// Copyright 2021 Makarychev Sergey
#include "include/Pqueue.h"

PriorityQueueElem::PriorityQueueElem() : priority(1), elem(1) {}

PriorityQueueElem::PriorityQueueElem(int priority, float elem) {
  if (priority < 0)
      throw "wrong priority";
  this->priority = priority;
  this->elem = elem;
}

bool PriorityQueueElem::operator > (const PriorityQueueElem& e) const {
  return priority > e.priority;
}

bool PriorityQueueElem::operator < (const PriorityQueueElem& e) const {
  return priority < e.priority;
}

bool PriorityQueueElem::operator == (const PriorityQueueElem& e) const {
  return priority == e.priority;
}

PQueue::PQueue(int size) {
  if (size <= 0)
    throw "wrong size";
  this->size = size;
  this->elems.resize(size);
  this->count = 0;
}

PQueue::PQueue(const PQueue& q) {
  size = q.size;
  count = q.count;
  this->elems.resize(q.size);
  if (q.IsEmpty())
    return;
  for (int i = 0; i < q.count; i++)
    elems[i] = q.elems[i];
}

bool PQueue::IsEmpty()const {
  return(count == 0);
}

bool PQueue::IsFull()const {
  return(count == size);
}

void PQueue::Push(PriorityQueueElem q) {
    if (IsFull()) {
        size += 1;
        elems.resize(size);
    }
  if (IsEmpty()) {
    elems[count] = q;
    count++;
    return;
  }
  int i1 = 0;
  int i2 = count - 1;
  int flag = 0;
  while (i1 <= i2) {
    int mid = (i1 + i2) / 2;
    if (elems[mid] == q) {
        i1 = i2 + 1;
        flag = mid;
    } else if (elems[mid] < q) {
        i1 = mid + 1;
        flag = i1;
    } else {
        i2 = mid - 1;
    }
  }

  for (int j = count; j > flag; j--)
    elems[j] = elems[j - 1];
  elems[flag] = q;
  count++;
}

PriorityQueueElem PQueue::Pop() {
  if (IsEmpty())
    throw "queue is empty";
  PriorityQueueElem p = elems[count - 1];
  count--;
  return p;
}

bool PQueue::operator==(const PQueue& pq) const {
  if (size == pq.size) {
    for (int i = 0; i < size; i++) {
      if (elems[i].priority != pq.elems[i].priority
        || elems[i].elem != pq.elems[i].elem)
        return false;
    }
    return true;
  }
  return false;
}

bool PQueue::operator!=(const PQueue& pq) const {
  return !(*this == pq);
}
