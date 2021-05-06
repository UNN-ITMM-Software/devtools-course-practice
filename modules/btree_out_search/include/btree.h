  // Copyright 2021 Kuznetsov Nikita

#ifndef MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_
#define MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_

struct tnode {
  int value;
  tnode* left;
  tnode* right;
};

struct tnode* addtree(tnode* tree, int val);
tnode* find(tnode* tree, int val);
#endif  // MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_
