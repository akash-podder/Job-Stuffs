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
class Solution {
public:
    int solve(TreeNode* root){
        // Base Case:
        if(root==NULL){
            return 0;
        }

        if(solve(root->left)==-1 || solve(root->right)==-1){
            return -1;
        }

        // A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node "NEVER" Differs by "More than ONE"
        if(abs(solve(root->left)-solve(root->right))>1){
            return -1;
        }

        // we are Adding "1" to Calculate the Height
        return 1+max(solve(root->left), solve(root->right));
    }

    bool isBalanced(TreeNode* root) {
        // we Calulate the Height & Also checking if two subtrees of every node never differs by more than one
        return solve(root)!=-1;
    }
};