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
    void solve(TreeNode* current, int targetSum, vector<vector<int>> &ans, vector<int> &v){
        // Removed this CONDTION as, the targetSum can initially be ZERO
        // if(targetSum<0){
        //     return;
        // }

        // this means we have come to the LEAF NODE of the Tree
        if(current->left==NULL && current->right==NULL){
            cout<<targetSum<<endl;
            targetSum=targetSum-current->val; // we Subtract from the CurrentNode Value
            
            if(targetSum==0){ // check after Minus, it has Become ZERO
                v.push_back(current->val);
                ans.push_back(v);
                v.pop_back();
            }

            return;
        }

        v.push_back(current->val);

        if(current->left!=NULL){
            solve(current->left, targetSum-current->val, ans, v);
        }

        if(current->right!=NULL){
            solve(current->right, targetSum-current->val, ans, v);
        }

        // this like the Backtracking
        v.pop_back();

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        
        if(root!=NULL){
            solve(root, targetSum, ans, v);
        }

        return ans;
    }
};