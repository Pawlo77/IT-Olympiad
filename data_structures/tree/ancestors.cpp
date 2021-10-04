/*
Given a Binary Tree and a key, write a
function that prints all the ancestors of
the key in the given binary tree. 
*/

class Solution{
  private:
    bool search(Node *root, int target, vector<int> &result) {
        if (root == NULL) return 0;
        else if (root->data == target)
            return 1;

        if (search(root->right, target, result) || search(root->left, target, result)) {
            result.push_back(root->data);
            return 1;
        }
        return 0;
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> result;
        search(root, target, result);
        return result;
    }
};