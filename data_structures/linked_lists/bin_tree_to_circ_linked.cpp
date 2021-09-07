#include <iostream>
using namespace std;

/*
Given a Binary Tree,
convert it into a Circular 
Doubly Linked List (In-Place)
traversing tree method - InOrder
*/

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *concatenate(Node *leftL, Node *rightL) {
    if (leftL == NULL) return rightL;
    if (rightL == NULL) return leftL;
    
    Node *leftLast = leftL->left;
    Node *rightLast = rightL->left;
    
    leftL->left = rightLast;
    rightLast->right = leftL;
    rightL->left = leftLast;
    leftLast->right = rightL;
    
    return leftL;
}

//Function to convert binary tree into circular doubly linked list.
Node *bTreeToCList(Node *root) {
    if (root == NULL) return NULL;
    
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);
    
    root->right = root->left = root;
    
    return concatenate(concatenate(left, root), right);
}