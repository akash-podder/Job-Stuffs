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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root!=NULL){
            q.push(root);
        }

        //the Flag is for ZigZag Logic
        bool flag=false;
        
        while(!q.empty()){
            //*** this is the Most Important Line, with this "n" size we can Track the "Level" of the BFS... otherwise, we won't be able to determine how many element belongs to SAME Level***
            int len = q.size(); //This Line is Most Important
            
            vector<int> Vec(len);
            
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                
            //this is for ZigZag Logic... if flag=True, then we insert the Elements in Reverse in the Vector
                if(flag){
                    Vec[len-1-i] = node->val;
                }
                else{
                    Vec[i] = node->val;
                }
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }

            //we alternate the Flag, after each traversing each LEVEL
            flag=!flag;

            ans.push_back(Vec);
        }

        return ans;
    }
};