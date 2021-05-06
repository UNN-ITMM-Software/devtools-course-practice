// Copyright 2021 Kirichenko Nikita

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_H_

using key = int64_t;


struct CNode {
    key data;
    CNode *pLeft;
    CNode *pRight;
    int height;
};
class CAvl {
 private:
    CNode* Insert(const key& x, CNode* t);
    CNode* SingleRightRotate(CNode* t);
    CNode* SingleLeftRotate(CNode* t);
    CNode* DoubleLeftRotate(CNode* t);
    CNode* DoubleRightRotate(CNode* t);
    CNode* FindMin(CNode* t);
    CNode* Remove(const key& x, CNode* t);
    int Height(CNode* t);
    CNode *pRoot;
 public:
    CAvl();
    key Find(const key& x);
    void Insert(const key& x);
    void Remove(const key& x);
    key GetRoot() const;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_H_
