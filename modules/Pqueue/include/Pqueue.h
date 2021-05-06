// Copyright 2021 Makarychev Sergey
#ifndef MODULES_PQUEUE_INCLUDE_PQUEUE_H_
#define MODULES_PQUEUE_INCLUDE_PQUEUE_H_

#include <vector>

struct PriorityQueueElem {
  int priority;
  float elem;
  PriorityQueueElem();
  PriorityQueueElem(int priority, float elem);

  bool operator > (const PriorityQueueElem& e) const;
  bool operator < (const PriorityQueueElem& e) const;
  bool operator == (const PriorityQueueElem& e) const;
};

class PQueue {
 private:
  int size;
  int count;
  std::vector<PriorityQueueElem> elems;
 public:
  explicit PQueue(int size = 10);
  PQueue(const PQueue& q);
  bool IsEmpty()const;
  bool IsFull()const;
  void Push(PriorityQueueElem q);
  PriorityQueueElem Pop();
  bool operator == (const PQueue& pq) const;
  bool operator != (const PQueue& pq) const;
};

#endif  // MODULES_PQUEUE_INCLUDE_PQUEUE_H_
