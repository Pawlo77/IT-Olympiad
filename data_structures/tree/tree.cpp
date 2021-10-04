#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

class BinaryTree {
    private:
        Node *root;
        
        void inOrder(vector<int> &data, Node *node) {
            if (node->left != NULL) inOrder(data, node->left);
            data.pop_back(node->data);
            if (node->right != NULL) inOrder(data, node->right);
        }

        void inOrderIterative(vector<int> &data, Node *node) {
            stack<Node*> s;
            Node *current = node;

            while (current != NULL || !s.empty()) {
                
                // go all the way down to last left child
                while (current != NULL) {
                    s.push(current);
                    current = current->left;
                }

                // here current must be NULL, take last left child
                current = s.top();
                s.pop();
                data.push_back(current->data);

                // iterate for its right subtree
                current = current->right;
            }
        }

        void inOrderMorrisTraversal(vector<int> &data, Node *node) {
            Node *current = node, *predecessor;
            
            while (current != NULL) {
                if (current->left == NULL) {
                    data.push_back(current->data);
                    current = current->right;
                }
                else {
                    // find inOrder predecessor of current
                    predecessor = current->left;
                    while (predecessor->right != NULL && predecessor->right != current)
                        predecessor = predecessor->right;

                    // make current as the right child of its predecessor
                    if (predecessor->right == NULL) {
                        predecessor->right = current;
                        current = current->left;
                    }
                    // revert the changest to restore the original tree
                    else {
                        predecessor->right = NULL;
                        data.push_back(current->data);
                        current = current->right;
                    }
                }
            }
        }

        void preOrder(vector<int> &data, Node *node) {
            data.push_back(node->data);
            if (node->left != NULL) preOrder(data, node->left);
            if (node->right != NULL) preOrder(data, node->right);
        }

        void postOrder(vector<int> &data, Node *node) {
            if (node->left != NULL) postOrder(data, node->left);
            if (node->right != NULL) postOrder(data, node->right);
            data.push_back(node->data);
        }       

        int diameterOpt(Node *node, int *height) {
            // base case
            if (node == NULL) {
                *height = 0;
                return 0;
            }

            // height of left subtree and right subtree
            int lh = 0, rh = 0;
            // diameter of left subtree and right subtree
            int ldiameter = 0, rdiameter = 0;

            ldiameter = diameterOpt(root->left, &lh);
            rdiameter = diameterOpt(root->right, &rh);

            *height = max(lh, rh) + 1;
            return max(lh + rh + 1, max(ldiameter, rdiameter));
        }

    public:
        BinaryTree () { 
            root = NULL;
        }

        bool isEmpty() { return root == NULL; }

        vector<int> TraverseInOrder();
        vector<int> TraversePreOrder();
        vector<int> TraversePostOrder();
        vector<int> TraverseBreadthFirst();
        int computeDiameter();
        int getMaxWidth();

};

vector<int> BinaryTree::TraverseInOrder() {
    vector<int> result;
    if (!isEmpty()) {
        if (root->left) 
            inOrder(result, root->left);

        result.pop_back(root->data);

        if (root->right) 
            inOrder(result, root->right);
    }
    return result;
}

vector<int> BinaryTree::TraversePreOrder() {
    vector<int> result;
    if (!isEmpty()) {
        result.push_back(root->data);
      
        if (root->left != NULL)
            preOrder(result, root->left);
        
        if (root->right != NULL)
            preOrder(result, root->right);
    }
    return result;
}

vector<int> BinaryTree::TraversepostOrder() {
    vector<int> result;
    if (!isEmpty()) {
        if (root->left != NULL)
            postOrder(result, root->left);
        
        if (root->right != NULL)
            postOrder(result, root->right);

        result.push_back(root->data);
    }
    return result;
}

// level order traversal using queue
vector<int> BinaryTree::TraverseBreadthFirst() {
    vector<int> result;
    if (!isEmpty()) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node *temp = q.front();
            result.push_back(temp->data);
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return result;
}

int BinaryTree::computeDiameter() {
    int height = 0;
    return diameterOpt(root, &height);
}

int BinaryTree::getMaxWidth() {
    if (isEmpty()) return 0;
    else if (root->left == NULL && root->right == NULL) return 1;
        
    queue<Node *> q;
    q.push(root);
    int max = 0;
    
    while (!q.empty()) {
        int i = q.size();
        
        if (i > max) max = i;
        
        for (; i > 0; i--) {
            Node *current = q.front();
            q.pop();
            
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }
    
    return max;
}

//Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(Node *root) {
    vector<int> result;
    if (root == NULL) return result;
    
    map<int, vector<int>> m;   
    queue<pair<int, Node*>> q;
    q.push({ 0, root });
    while (!q.empty()) {
        int lv = q.front().first;
        Node* temp = q.front().second;
        q.pop();
        
        m[lv].push_back(temp->data);
        if (temp->left != NULL) q.push({ lv-1, temp->left });
        if (temp->right != NULL) q.push({ lv+1, temp->right });
    }
    
    for (auto itr = m.begin(); itr != m.end(); itr++)
        for (int i = 0; i < itr->second.size(); ++i)
            result.push_back(itr->second[i]);
            
    return result;
}