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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // traversing using BFS
        queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);
        }

        while(!q.empty()){
            //*** this is the Most Important Line, with this "n" size we can Track the "Level" of the BFS... otherwise, we won't be able to determine how many element belongs to SAME Level***
            int len = q.size(); //This Line is Most Important

            for(int i=0;i<len;i++){
                TreeNode* current = q.front();
                q.pop();

                //the Last Node in the Queue is the "Right" Most Node in that BFS Level
                if(i==len-1){
                    ans.push_back(current->val);
                }

                if(current->left!=NULL){
                    q.push(current->left);
                }
                if(current->right!=NULL){
                    q.push(current->right);
                }
            }
        }

        return ans;
    }
};