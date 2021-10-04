#include <bits/stdc++.h>

using namespace std;

// single threaded binary tree node
// to transfer it to doubly threaded binary 
// tree add bool leftThread
struct Node {
    int data;
    Node *left, *right;
    bool rightThread;
};

Node *leftMost(Node *node) {
    if (node == NULL) return NULL;

    while (node->left != NULL)
        node = node->left;
    return node;
}

void inOrder(vector<int> &data, Node *root) {
    Node *current = leftMost(root);

    while (current != NULL) {
        data.push_back(current->data);

        if (current->rightThread) 
            current = current->right;
        else
            current = leftMost(current->right);
    }
}