  // Copyright 2021 Kuznetsov Nikita

#include <malloc.h>

#include "include/btree.h"

tnode* addtree(tnode* tree, int val) {
  if (tree == nullptr) {
    tree = new tnode;
    tree->value = val;
    tree->left = tree->right = nullptr;
  } else if (val < tree->value) {
    tree->left = addtree(tree->left, val);
  } else {
    tree->right = addtree(tree->right, val);
  }
  return tree;
}

tnode* find(tnode* tree, int val) {
  if (tree == nullptr) {
    return nullptr;
  }
  if (tree->value == val) {
    return tree;
  }
  if (val <= tree->value) {
    if (tree->left != nullptr) {
      return find(tree->left, val);
    } else {
      return nullptr;
    }
  } else {
    if (tree->right) {
      return find(tree->right, val);
    } else {
      return nullptr;
    }
  }
}
