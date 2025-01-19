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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        
        if(root!=NULL)
        {
            q.push(root);
        }

        while(!q.empty()){
            //*** this is the Most Important Line, with this "len" size we can Track the "Level" of the BFS... otherwise, we won't be able to determine how many element belongs to SAME Level***
            int len = q.size(); //This Line is Most Important
            
            vector<int> tempVec;

            for(int i=0;i<len;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                tempVec.push_back(node->val);

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }

            ans.push_back(tempVec);
        }

        return ans;
    }
};