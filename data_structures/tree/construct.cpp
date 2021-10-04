/* 
Construct tree from inorder 
and preorder traversals
*/

class Solution{
    private:
    // function assumes that x is in arr
    int search(int arr[], int l, int r, int x) {
        for (; l <= r; l++)
            if (arr[l] == x) 
                return l;
    }
    Node *build(int in[], int pre[], int l, int r, int &preIdx) {
        if (l > r) return NULL;
        
        Node *root = new Node(pre[preIdx++]);
        if (l == r) return root;
        
        int rootIdx = search(in, l, r, root->data);
            
        root->left = build(in, pre, l, rootIdx - 1, preIdx);
        root->right = build(in, pre, rootIdx + 1, r, preIdx);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIdx = 0;
        return build(in, pre, 0, n - 1, preIdx);
    }
};