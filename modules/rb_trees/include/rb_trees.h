// Copyright 2021 Zaitsev Andrey

#ifndef MODULES_RB_TREES_INCLUDE_RB_TREES_H_
#define MODULES_RB_TREES_INCLUDE_RB_TREES_H_

#include <vector>
#include <stack>

#define RED true
#define BLACK false

struct Node {
    int value;
    bool color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int _value = 0, bool _color = BLACK, Node* _left = nullptr,
        Node* _right = nullptr, Node* _parent = nullptr);
    Node(const Node& node);

    Node& operator=(const Node& node);

    bool operator==(const Node& node);
    bool operator!=(const Node& node);
};

class RBTree {
    Node* NIL;
    Node* root;
    Node* current;

    unsigned int nodes_number;
    unsigned int counter;

    std::vector<Node*> nodes_ptr;
    std::stack<Node*> node_stack;

    void shuffle_for_insert(Node* node);

    void left_rotate(Node* x);
    void right_rotate(Node* x);

    void transplant(Node* x, Node* y);
    void shuffle_for_remove(Node* node);

    Node* get_minimum(Node* const node);

 public:
    RBTree();
    explicit RBTree(Node* node);
    explicit RBTree(const std::vector<int>& vec);
    RBTree(const RBTree& tree) = default;
    ~RBTree();

    unsigned int getNodesNumber() const;

    bool findNode(const int value);
    void insertNode(Node* node);
    void removeNode(const int value);

    void removingNodes(const std::vector<int>& vec, int i = 0);
};

#endif  // MODULES_RB_TREES_INCLUDE_RB_TREES_H_
