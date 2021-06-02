// Copyright 2021 Kirichenko Nikita

#include <random>
#include <algorithm>

#include "include/avl.h"

using std::max;

CNode* CAvl::Insert(const key& x, CNode* t) {
    if (t == nullptr) {
        t = new CNode;
        t->data = x;
        t->height = 0;
        t->pLeft = t->pRight = nullptr;
    } else if (x < t->data) {
        t->pLeft = Insert(key(x), t->pLeft);
        if (Height(t->pLeft) - Height(t->pRight) == 2) {
            if (x < t->pLeft->data) {
                t = SingleRightRotate(t);
            } else {
                t = DoubleRightRotate(t);
            }
        }
    } else if (x > t->data) {
        t->pRight = Insert(key(x), t->pRight);
        if (Height(t->pRight) - Height(t->pLeft) == 2) {
            if (x > t->pRight->data) {
                t = SingleLeftRotate(t);
            } else {
                t = DoubleLeftRotate(t);
            }
        }
    }

    t->height = max(Height(t->pLeft), Height(t->pRight)) + 1;
    return t;
}

CNode* CAvl::SingleRightRotate(CNode* t) {
    CNode *u = t->pLeft;
    t->pLeft = u->pRight;
    u->pRight = t;
    t->height = max(Height(t->pLeft), Height(t->pRight)) + 1;
    u->height = max(Height(u->pLeft), t->height) + 1;
    return u;
}

CNode* CAvl::SingleLeftRotate(CNode* t) {
    CNode *u = t->pRight;
    t->pRight = u->pLeft;
    u->pLeft = t;
    t->height = max(Height(t->pLeft), Height(t->pRight)) + 1;
    u->height = max(Height(t->pRight), t->height) + 1;
    return u;
}

CNode* CAvl::DoubleLeftRotate(CNode* t) {
    t->pRight = SingleRightRotate(t->pRight);
    return SingleLeftRotate(t);
}

CNode* CAvl::DoubleRightRotate(CNode* t) {
    t->pLeft = SingleLeftRotate(t->pLeft);
    return SingleRightRotate(t);
}

CNode* CAvl::FindMin(CNode* t) {
    if (t->pLeft == nullptr) {
        return t;
    } else {
        return FindMin(t->pLeft);
    }
}

CNode* CAvl::FindMax(CNode* t) {
    if (t->pRight == nullptr)
        return t;
    else
        return FindMax(t->pRight);
}

CNode* CAvl::Remove(const key& x, CNode* t) {
    CNode *temp;

    if (t == nullptr) {
        return nullptr;
    } else if (x < t->data) {
        t->pLeft = Remove(x, t->pLeft);
    } else if (x > t->data) {
        t->pRight = Remove(x, t->pRight);
    } else if (t->pLeft && t->pRight) {
        temp = FindMin(t->pRight);
        t->data = temp->data;
        t->pRight = Remove(t->data, t->pRight);
    } else {
        temp = t;
        if (t->pLeft == nullptr) {
            t = t->pRight;
        } else if (t->pRight == nullptr) {
            t = t->pLeft;
        }
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->height = max(Height(t->pLeft), Height(t->pRight)) + 1;

    if (Height(t->pLeft) - Height(t->pRight) == 2) {
        if (Height(t->pLeft->pLeft) - Height(t->pLeft->pRight) == 1) {
            return SingleRightRotate(t);
        } else {
            return DoubleRightRotate(t);
        }
    } else if (Height(t->pRight) - Height(t->pLeft) == 2) {
        if (Height(t->pRight->pRight) - Height(t->pRight->pLeft) == 1) {
            return SingleLeftRotate(t);
        } else {
            return DoubleLeftRotate(t);
        }
    }
    return t;
}

int CAvl::Height(CNode* t) {
    return (t == nullptr ? -1 : t->height);
}

CAvl::CAvl() {
    pRoot = nullptr;
}

void CAvl::Insert(const key& x) {
    pRoot = Insert(x, pRoot);
}

void CAvl::Remove(const key& x) {
    pRoot = Remove(x, pRoot);
}

key CAvl::Find(const key & x) {
    CNode* t = this->pRoot;
    while (t != nullptr) {
        if (x < t->data) {
            t = t->pLeft;
        } else if (x > t->data) {
            t = t->pRight;
        } else if (x == t->data) {
            return (t->data);
        }
    }
    return key();
}

key CAvl::GetRoot() const {
    if (pRoot) {
        return pRoot->data;
    } else {
        return key();
    }
}

key CAvl::FindMin() {
    CNode* t = FindMin(pRoot);
    return t->data;
}

key CAvl::FindMax() {
    CNode* t = FindMax(pRoot);
    return t->data;
}
