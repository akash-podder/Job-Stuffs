/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BASE Case:
        if(root==NULL){
            return NULL;
        }
        // MAIN Base Case:
        if(root==p || root==q){
            return root;
        }

        TreeNode* leftSubTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubTree = lowestCommonAncestor(root->right, p, q);
        
        // if the "Left Side" Returns NULL, that means "MAIN Base Case:" was False, So, our Answer Lies in the "Right Side"
        if(leftSubTree==NULL){
            return rightSubTree;
        }
        // if the "Right Side" Returns NULL, that means "MAIN Base Case:" was False, So, our Answer Lies in the "Left Side"
        else if(rightSubTree==NULL){
            return leftSubTree;
        }
        // BOTH the "Right Side" & "Left Side" is NULL, that means, CURRENT "root" is the "Parent" of them Both
        else{
            return root;
        }
    }
};