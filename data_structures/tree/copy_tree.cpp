/* 
Given a special binary tree having random pointers 
along with the usual left and right pointers. Clone the given tree.
*/

class Solution{
    private:
        Node *clone_tree(Node *root, unordered_map<Node*, Node*> &map) {
            if (root != NULL) {
                Node *temp = new Node(root->data);
                map[root] = temp;
                
                temp->left = clone_tree(root->left, map);
                temp->right = clone_tree(root->right, map);
                
                return temp;
            }
            return NULL;
        }
        void clone_random(Node *root, Node *cloned_root, unordered_map<Node*, Node*> &map) {
            if (cloned_root != NULL) {
                cloned_root->random = map[root->random];
                
                clone_random(root->left, cloned_root->left, map);
                clone_random(root->right, cloned_root->right, map);
            }
        }
    
    public:
        /* The function should clone the passed tree and return 
           root of the cloned tree */
        Node* cloneTree(Node* tree)
        {
           unordered_map<Node*, Node*> map;
           
           Node *cloned_root = clone_tree(tree, map);
           clone_random(tree, cloned_root, map);
           
           return cloned_root;
        }
};