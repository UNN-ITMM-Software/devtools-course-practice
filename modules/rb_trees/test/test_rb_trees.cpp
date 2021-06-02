// Copyright 2021 Zaitsev Andrey

#include <gtest/gtest.h>

#include <random>
#include <vector>
#include <algorithm>

#include "include/rb_trees.h"

TEST(RBTreeNodeTest, Create_Node_Default_Constructor) {
    ASSERT_NO_THROW(Node());
}

TEST(RBTreeNodeTest, Create_Node_Copy_Constructor) {
    Node node1(5);
    Node node2(node1);

    ASSERT_TRUE(node1 == node2);
}

TEST(RBTreeNodeTest, Assignment_Of_Nodes) {
    Node node1(1), node2(2);

    ASSERT_NO_THROW(node1 = node2);
}

TEST(RBTreeNodeTest, Assignment_Of_Equal_Nodes) {
    Node node(1, BLACK);

    ASSERT_NO_THROW(node = node);
}

TEST(RBTreeNodeTest, Same_Nodes_Are_Equal) {
    Node node1(1), node2(1);

    ASSERT_TRUE(node1 == node2);
}

TEST(RBTreeNodeTest, Different_Nodes_Are_Not_Equal) {
    Node node1(1), node2(2);

    ASSERT_TRUE(node1 != node2);
}

TEST(RBTreeTest, Create_Tree_Default_Constructor) {
    ASSERT_NO_THROW(RBTree());
}

TEST(RBTreeTest, Create_Tree_from_Node) {
    Node *node = new Node();

    ASSERT_NO_THROW(RBTree(node));
}

TEST(RBTreeTest, Create_Tree_from_Vector) {
    std::vector<int> vec = {4, 7, 9};

    ASSERT_NO_THROW(RBTree(vec));
}

TEST(RBTreeTest, Copy_Constructor_Does_Not_Throw_Any_Exceptions) {
    std::vector<int> vec = {0, 1, 2};
    RBTree tree(vec);

    ASSERT_NO_THROW(RBTree(tree));
}

TEST(RBTreeTest, Get_Nodes_Number) {
    Node *node = new Node(5);
    RBTree tree(node);

    ASSERT_EQ(static_cast<unsigned int>(1), tree.getNodesNumber());
}

TEST(RBTreeTest, Can_Find_Existing_Node) {
    std::vector<int> vec = {-24, 45, 16};
    RBTree tree(vec);

    bool is_found = tree.findNode(45);

    ASSERT_TRUE(is_found);
}

TEST(RBTreeTest, Can_Not_Find_Nonexistent_Node) {
    std::vector<int> vec = {-24, 45, 16};
    RBTree tree(vec);

    bool is_found = tree.findNode(10);

    ASSERT_FALSE(is_found);
}

TEST(RBTreeTest, Can_Insert_New_Node) {
    std::vector<int> vec = {0, 1, 2};
    RBTree tree(vec);

    Node *node = new Node(3);

    ASSERT_NO_THROW(tree.insertNode(node));
}

TEST(RBTreeTest, Can_Not_Insert_Existing_Node) {
    std::vector<int> vec = {0, 1, 2};
    RBTree tree(vec);

    Node *node = new Node(1);

    ASSERT_ANY_THROW(tree.insertNode(node));
}

TEST(RBTreeTest, Can_Remove_Existing_Node) {
    std::vector<int> vec = {0, 1, 2};
    RBTree tree(vec);

    ASSERT_NO_THROW(tree.removeNode(1));
}

TEST(RBTreeTest, Can_Not_Remove_Nonexistent_Node) {
    std::vector<int> vec = {0, 1, 2};
    RBTree tree(vec);

    ASSERT_ANY_THROW(tree.removeNode(3));
}

TEST(RBTreeTest, Removing_All_Nodes_In_a_Tree) {
    std::vector<int> vec = {22, 14, 6, -12, 27, 1, -19};
    RBTree tree(vec);

    for (int i : vec)
        tree.removeNode(i);

    ASSERT_EQ(static_cast<unsigned int>(0), tree.getNodesNumber());
}

TEST(RBTreeTest, Removing_All_Nodes_In_a_Tree_Recursion) {
    std::vector<int> vec = {14, 4, 7, -8, 34, 2, -17};
    RBTree tree(vec);

    tree.removingNodes(vec);

    ASSERT_EQ(static_cast<unsigned int>(0), tree.getNodesNumber());
}

TEST(RBTreeTest, Operations_With_Large_Tree) {
    std::vector<int> vec;

    for (int i = -300; i <= 300; ++i)
        vec.emplace_back(i);

    std::default_random_engine reng(0);
    std::shuffle(vec.begin(), vec.end(), reng);

    RBTree tree(vec);

    auto several_tree_operations = [&tree, &vec, &reng] {
        for (int i : vec)
            tree.removeNode(i);
    };

    ASSERT_NO_THROW(several_tree_operations());
}
