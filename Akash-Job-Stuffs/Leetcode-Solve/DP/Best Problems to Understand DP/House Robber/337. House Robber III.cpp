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
    int solve(TreeNode* root, map<TreeNode*, int> &cache) {
        // Base Case:
        if(root==NULL){
            return 0;
        }

        // Return cache, if found
        if(cache.find(root)!=cache.end()){
            return cache[root];
        }

        // Either we NOT take the ROOT
        int root_exclude_ans=0+solve(root->left, cache)+solve(root->right, cache);

        // Or else, we take the ROOT
        int root_include_ans=root->val;

        if(root->left!=NULL){
            root_include_ans+=solve(root->left->left, cache);
            root_include_ans+=solve(root->left->right, cache);
        }

        if(root->right!=NULL){
            root_include_ans+=solve(root->right->left, cache);
            root_include_ans+=solve(root->right->right, cache);
        }
        
        return cache[root] = max(root_exclude_ans, root_include_ans);
    }

    int rob(TreeNode* root) {
        map<TreeNode*, int> cache;

        return solve(root, cache);    
    }
};