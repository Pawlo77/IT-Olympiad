void calculate(Node *root, int k, vector<int> &result) {
    if (root == NULL) return;
    else if (k == 0) {
        result.push_back(root->data);
        return;
    }
    
    calculate(root->left, k - 1, result);
    calculate(root->right, k - 1, result);
}

// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> result;
    calculate(root, k, result);
    return result;
}