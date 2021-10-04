// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);
    
    Node *current = root;
    while (current->data != key) {
        if (current->data > key) {
            if (current->left != NULL)
                current = current->left;
            else {
                current->left = new Node(key);
                break;
            }
        }       
        else {
            if (current->right != NULL)
                current = current->right;
            else {
                current->right = new Node(key);
                break;
            }
        }
    }
    
    return root;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    if (root == NULL) return root;
    
    if (X < root->data)
        root->left = deleteNode(root->left, X);
    else if (X > root->data)
        root->right = deleteNode(root->right, X);
    else {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        Node *temp = root->right;
        while (temp->right != NULL)
            temp = temp->right;
        root->data = temp->data;
        root->right = deleteNode(root->right, root->data);
        
        return root;    
    }
}

// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    if (root->left == NULL) return root->data;
    return minValue(root->left);
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL) return;
    
    if (root->key == key) {
        if (root->left != NULL) {
            Node *current = root->left;
            while (current->right != NULL) 
                current = current->right;
            pre = current;
        }
        if (root->right != NULL) {
            Node *current = root->right;
            while (current->left != NULL)
                current = current->left;
            suc = current;
        }
    }
    else {
        if (root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
}

bool isBSTUtil(Node *root, int min, int max) {
        if (root == NULL) 
            return 1;
        
        if (root->data < min || root->data > max)
            return 0;
            
        return
            isBSTUtil(root->left, min, root->data - 1) &&
            isBSTUtil(root->right, root->data + 1, max);
    }
//Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) 
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

//Function to find the lowest common ancestor in a BST. 
// in case of BST it is first node n such as n1 < n->data < n2
// assumption: n1 and n2 are in the BST 
Node* LCA(Node *root, int n1, int n2)
{
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);
    return root;
}

// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    if (x->right != NULL) {
        x = x->right;
        while (x->left != NULL)
            x = x->left;
        return x;
    }
    
    Node *succ = NULL;
    while (root != NULL) {
        if (root->data < x->data)
            root = root->right;
        else if (root->data > x->data) {
            succ = root;
            root = root->left;
        }
        else    
            break;
    }
    return succ;
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node* root, int k) {
    Node *current = root;
    
    while (current != NULL) {
        if (current->left == NULL) {
            if (--k == 0) return current->data;
            current = current->right;
        }
        else {
            Node *pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
                
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            else {
                if (--k == 0) return current->data;
                pre->right = NULL;
                current = current->right;
            }
        }
    }
    return -1;
}

/* merge two bfs */
void inOrder(Node *root, vector<int> &v) {
    if (root != NULL) {
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
}

//Function to return a list of integers denoting the node 
//values of both the BST in a sorted order.
vector<int> merge(Node *root1, Node *root2) {
    vector<int> result;
    stack<Node *> s1, s2;

    while (root1 != NULL || !s1.empty() || root2 != NULL || !s2.empty()) {
        if (root1 != NULL || root2 != NULL) {
            if (root1 != NULL) {
                s1.push(root1);
                root1 = root1->left;
            }
            if (root2 != NULL) {
                s2.push(root2);
                root2 = root2->left;
            }
        }
        else {
            // if one of trees run out of data
            if (s1.empty()) {
                while (!s2.empty()) {
                    root2 = s2.top(); s2.pop();
                    root2->left = NULL;
                    inOrder(root2, result);   
                }
                return result;
            }
            if (s2.empty()) {
                while (!s1.empty()) {
                    root1 = s1.top(); s1.pop();
                    root1->left = NULL;
                    inOrder(root1, result);
                }
                return result;
            }
            
            root1 = s1.top(); 
            root2 = s2.top();
            
            if (root1->data < root2->data) {
                s1.pop(); root2 = NULL;
                result.push_back(root1->data);
                root1 = root1->right;
            }
            else {
                s2.pop(); root1 = NULL;
                result.push_back(root2->data);
                root2 = root2->right;
            }
        }
    }

    return result;
}

// 2 nodes in bst were swapped, fix the order
bool check(Node* current, Node* prev, Node** s1, Node** s2, Node** s3) {
    if (prev != NULL && current != NULL) {
        if (prev->data > current->data) {
            if (*s1 == NULL) {
                *s1 = prev;
                *s2 = current;
            }
            else *s3 = current;
        }
    }
    return *s3 == NULL ? 0: 1;
}
void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void correctBST( struct Node* root )
    {
        stack<Node *> s;
        Node *current = root, *prev = NULL, *s1 = NULL, *s2 = NULL, *s3 = NULL;
        
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            
            current = s.top(); s.pop();
            if (check(current, prev, &s1, &s2, &s3)) break;
            prev = current;
            current = current->right;
            
        }
        
        if (s1 != NULL) {
            if (s3 != NULL)
                swap(&(s1->data), &(s3->data));
            else {
                swap(&(s1->data), &(s2->data));
            }
        }
    }

int ceil(Node* root, int i) {
    if (root == NULL) return -1;
    if (root->data == i) return root->data;
    if (root->data < i) return ceil(root->right, i);
 
    int ceil = Ceil(root->left, i);
    return (ceil >= i) ? ceil: root->data;
}

Node* sorted_dll_to_bst(Node **headRef, int n) {
    if (n <= 0) return NULL;

    Node* left = sorted_dll_to_bst(headRef, n/2);
    Node* root = *headRef;
    root->left = left;
    *headRef = (*headRef)->right;
    root->right = sorted_dll_to_bst(headRef, n - n/2 - 1);
    return root;
}

// return 1 if there are 2 nodes in BST that adds up exacly to target
bool isPairPresent(struct Node *root, int target) {
    stack<Node*> s;
    vector<int> v;
    
    Node* current = root;
    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
            
        current = s.top(); s.pop();
        v.push_back(current->data);
        current = current->right;
    }
    
    auto start = v.begin(), end = v.end() - 1;
    int sum;
    while (start != end) {
        sum = *start + *end;
        if (sum == target) return 1;
        else if (sum > target) end--;
        else start++;
    }
    return 0;
}
