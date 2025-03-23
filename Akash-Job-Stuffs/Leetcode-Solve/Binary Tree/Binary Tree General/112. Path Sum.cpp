/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return getSum(root, 0, targetSum);
    }

    bool getSum(TreeNode* root, int Current, int targetSum) {
        if (root->left == NULL && root->right == NULL) {
            return targetSum == Current+root->val;
        }
        else {
            Current = Current + root->val;
            bool LEFT = false;
            bool RIGHT = false;
            
            if(root->left!=NULL){
                LEFT = getSum(root->left, Current, targetSum);
            }

            if(root->right!=NULL){
                RIGHT = getSum(root->right, Current, targetSum);
            }
            
            // cout<<"CURRENT:"<<root->val<<" ";
            // cout<<"LEFT:"<<LEFT<<" ";
            // cout<<"RIGHT:"<<RIGHT<<endl;
            
            return LEFT || RIGHT;
        }
    }
};