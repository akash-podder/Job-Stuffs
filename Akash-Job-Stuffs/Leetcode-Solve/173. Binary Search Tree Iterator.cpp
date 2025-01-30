/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> myStack;

public:
    void push_node_to_stack(TreeNode* root){
        while(root!=NULL){
            myStack.push(root);
            root=root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        push_node_to_stack(root);
    }
    
    int next() {
        if(!myStack.empty()){
            TreeNode* current = myStack.top();
            myStack.pop();

            if(current->right!=NULL){
                push_node_to_stack(current->right); // *** Remember after Pushing "current->right", them we have to push all the "LEFT" element of "current->right" if it exists. That means we have to push "current->right->left", "current->right->left->left" and So on.
            }

            return current->val;
        }
        
        return -1;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */