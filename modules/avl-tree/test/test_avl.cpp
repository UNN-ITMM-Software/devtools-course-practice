// Copyright 2021 Kirichenko Nikita

#include <gtest/gtest.h>

#include <vector>

#include "include/avl.h"

const int nLenght = 100000;

TEST(CAvlTest,
    CanCreateDefaultCAvl) {
    CAvl tree;
    ASSERT_EQ(key(), tree.GetRoot());
}

TEST(CAvlTest,
    CanInsertObject) {
    CAvl tree;
    key root = 0;
    tree.Insert(root);
    ASSERT_EQ(root, tree.GetRoot());
}

TEST(CAvlTest,
    CanFindObject) {
    CAvl tree;
    key root = 0;
    tree.Insert(root);
    ASSERT_EQ(root, tree.Find(root));
}

TEST(CAvlTest,
    CanInsertAndFindALotOfObjects) {
    CAvl tree;
    std::vector<int> vKeys = { 2, 4, 6 };

    for (int number : vKeys) {
        tree.Insert(number);
    }

    for (int number : vKeys) {
        ASSERT_EQ(number, tree.Find(number));
    }
}

TEST(CAvlTest,
    CanRemoveObject) {
    CAvl tree;
    std::vector<int> vKeys = { 2, 4, 6, 9, 11, 13 };

    for (int number : vKeys) {
        tree.Insert(number);
    }

    tree.Remove(vKeys[5]);
    ASSERT_EQ(key(), tree.Find(vKeys[5]));
}

TEST(CAvlTest,
    CanRemoveALotOfObjects) {
    CAvl tree;
    std::vector<int> vKeys = { 2, 4, 6, 9, 11, 13, 15, 17, 21, 23, 24 };

    for (int number : vKeys) {
        tree.Insert(number);
    }

    tree.Remove(vKeys[5]);
    ASSERT_EQ(key(), tree.Find(vKeys[5]));

    tree.Remove(vKeys[1]);
    ASSERT_EQ(key(), tree.Find(vKeys[1]));

    tree.Remove(vKeys[6]);
    ASSERT_EQ(key(), tree.Find(vKeys[6]));

    tree.Remove(vKeys[2]);
    ASSERT_EQ(key(), tree.Find(vKeys[2]));

    ASSERT_EQ(vKeys[0], tree.Find(vKeys[0]));
    ASSERT_EQ(vKeys[3], tree.Find(vKeys[3]));
    ASSERT_EQ(vKeys[4], tree.Find(vKeys[4]));
    ASSERT_EQ(vKeys[7], tree.Find(vKeys[7]));
    ASSERT_EQ(vKeys[8], tree.Find(vKeys[8]));
    ASSERT_EQ(vKeys[9], tree.Find(vKeys[9]));
}

TEST(CAvlTest,
    CanRemoveAllTree) {
    CAvl tree;
    std::vector<int> vKeys = { 2, 4, 6 };

    for (int number : vKeys) {
        tree.Insert(number);
    }

    for (int number : vKeys) {
        tree.Remove(number);
    }

    ASSERT_EQ(key(), tree.GetRoot());
}

TEST(CAvlTest,
    CanInsertObjectsAscending) {
    CAvl tree;

    for (uint32_t i = 0; i < nLenght; i++) {
        tree.Insert(i);
        ASSERT_EQ(i, tree.Find(i));
    }
}

TEST(CAvlTest,
    CanInsertObjectsDescending) {
    CAvl tree;

    for (uint32_t i = nLenght; i != 0; i--) {
        tree.Insert(i);
        ASSERT_EQ(i, tree.Find(i));
    }
}

TEST(CAvlTest,
    CanInsertObjectWithDLRotate) {
    CAvl tree;

    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(7);
    tree.Insert(9);
    tree.Insert(8);
    ASSERT_EQ(8, tree.Find(8));
}

TEST(CAvlTest,
    CanInsertObjectWithDRRotate) {
    CAvl tree;

    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(3);
    tree.Insert(1);
    tree.Insert(2);
    ASSERT_EQ(2, tree.Find(2));
}

TEST(CAvlTest,
    CanRemoveObjectsAscending) {
    CAvl tree;

    for (uint32_t i = 0; i != nLenght; i++) {
        tree.Insert(i);
    }

    for (uint32_t i = 0; i != nLenght; i++) {
        tree.Remove(i);
        ASSERT_EQ(key(), tree.Find(i));
    }
}

TEST(CAvlTest,
    CanRemoveObjectsDescending) {
    CAvl tree;

    for (uint32_t i = 0; i != nLenght; i++) {
        tree.Insert(i);
    }

    for (uint32_t i = nLenght; i != 0; i--) {
        tree.Remove(i);
        ASSERT_EQ(key(), tree.Find(i));
    }
}

TEST(CAvlTest,
    CanRemoveRoot) {
    CAvl tree;

    for (uint32_t i = 0; i != nLenght; i++) {
        tree.Insert(i);
    }

    key nRoot = tree.GetRoot();
    tree.Remove(nRoot);
    ASSERT_EQ(key(), tree.Find(nRoot));
}

TEST(CAvlTest,
    CanRemoveNonexistRootChild) {
    CAvl tree;
    tree.Insert(0);
    tree.Remove(0);
    ASSERT_EQ(0, tree.Find(0));
    ASSERT_EQ(key(), tree.Find(-1));
}

TEST(CAvlTest,
    CanRemoveNonexistObject) {
    CAvl tree;

    for (uint32_t i = 0; i != nLenght; i++) {
        tree.Insert(i);
    }

    key nRoot = tree.GetRoot();
    tree.Remove(-1);
    for (uint32_t i = 0; i != nLenght; i++) {
        ASSERT_EQ(i, tree.Find(i));
    }
    ASSERT_EQ(key(), tree.Find(-1));
}
