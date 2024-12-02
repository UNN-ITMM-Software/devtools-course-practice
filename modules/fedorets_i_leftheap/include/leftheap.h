// Copyright 2024 Fedorets Ilya

#ifndef MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_
#define MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_

#include <iostream>
#include <algorithm>

class LeftistHeap {
private:
    struct Node {
        int data;
        int rank;
        Node* left;
        Node* right;

        Node(int val) : data(val), rank(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Merge helper function
    Node* merge(Node* h1, Node* h2) {
        // If one heap is empty, return the other
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        // Ensure h1 has smaller root
        if (h1->data > h2->data) {
            std::swap(h1, h2);
        }

        // Merge right subtree
        h1->right = merge(h1->right, h2);

        // Swap children if necessary to maintain leftist property
        if (h1->left == nullptr || 
            (h1->right != nullptr && h1->right->rank > h1->left->rank)) {
            std::swap(h1->left, h1->right);
        }

        // Update rank
        h1->rank = (h1->right ? h1->right->rank : 0) + 1;

        return h1;
    }

    // Recursive delete helper
    void deleteNode(Node* node) {
        if (node == nullptr) return;
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }

public:
    LeftistHeap() : root(nullptr) {}

    // Destructor
    ~LeftistHeap() {
        deleteNode(root);
    }

    // Insert a new element
    void insert(int val) {
        Node* newNode = new Node(val);
        root = merge(root, newNode);
    }

    // Merge with another heap
    void merge(LeftistHeap& other) {
        root = merge(root, other.root);
        other.root = nullptr;
    }

    // Delete minimum element
    int deleteMin() {
        if (root == nullptr) {
            throw std::runtime_error("Heap is empty");
        }

        int minVal = root->data;
        Node* oldRoot = root;
        root = merge(root->left, root->right);
        delete oldRoot;

        return minVal;
    }

    // Check if heap is empty
    bool isEmpty() const {
        return root == nullptr;
    }

    // Peek at minimum element
    int findMin() const {
        if (root == nullptr) {
            throw std::runtime_error("Heap is empty");
        }
        return root->data;
    }
};

#endif MODULES_FEDORETS_I_LEFTHEAP_INCLUDE_LEFTHEAP_H_
