/* check if S is a subtree of T */

class Solution
{
  private:
    bool check(Node *T, Node *S) {
        if (T == NULL && S == NULL)
            return 1;
        else if (T == NULL || S == NULL)
            return 0;
        
        return T->data == S->data && check(T->left, S->left) 
               && check(T->right, S->right);
    }
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        if (T == NULL || S == NULL) return 0;
        
        if (check(T, S))
            return 1;
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};