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
    bool solve(TreeNode* root, TreeNode* subRoot) {
        // Base Case
        if(subRoot==NULL && root==NULL){
            return true;
        }
        else if(root==NULL){
            return false;
        }
        else if(subRoot==NULL){
            return false;
        }
        // Base Case END


        if(root->val==subRoot->val){
            // both "Left" & "Right" Subtree have to be Equal that's why we use "&&" Operation
            return solve(root->left, subRoot->left) 
                        && 
                    solve(root->right, subRoot->right);
        }
        
        return false;
    }

    bool dfs_for_traversal(TreeNode* root, TreeNode* subRoot) {
        // Base Case
        if(root==NULL){
            return false;
        }

        bool ans=false;

        // if we pass the "root" & "subRoot" it will point to Different Location, that's why we use "newRoot" & "newSubRoot"
        TreeNode* newRoot = root;
        TreeNode* newSubRoot = subRoot;

        if(newRoot->val==newSubRoot->val){
            ans = solve(newRoot, newSubRoot);
        }

        // if we get True, we Return TRUE all Together and No Need to Traverse Further
        if(ans==true){
            return true;
        }
        
        // this is used for just Traversing, if One of the Side Gives "true" Answer we Return True
        return dfs_for_traversal(root->left, subRoot) || dfs_for_traversal(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs_for_traversal(root, subRoot);
    }
};