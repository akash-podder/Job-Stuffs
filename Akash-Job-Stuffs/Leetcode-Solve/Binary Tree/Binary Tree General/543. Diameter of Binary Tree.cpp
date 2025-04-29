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
    // GLOBAL VARIABLE to Calculate the Maximum Diameter
    int ans=0;
    
    // this Function will Calculate the Maximum between "ans" & (left+right) SubtreeTree's Height
    // but the Function will Return it's current Height
    int solve(TreeNode* root){
        
        // Base Case: the Height of the Leaf Node is 0
        if(root==NULL){
            return 0;
        }

        int leftTreeHeight = solve(root->left); // this Calculate Height of the Left Sub Tree
        int rightTreeHeight = solve(root->right); // this Calculate Height of the Right Sub Tree

        // As we are Calulating Diameter we have to do "ADD" of the Left & Righ Subtree and Calculate if the Current Addition is Bigger than our "ans"
        int currentDiameter = leftTreeHeight+rightTreeHeight;
        ans = max(ans, currentDiameter);


        // As we are Calculating the Height of the Tree, so we have "ADD" 1 and also take the Maximum Height Between Left & Right Subtree... think it like "DFS"
        // We used it Calculate the Height of Each Individual Node from the Bottom

        return 1 + max(leftTreeHeight, rightTreeHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // the Return value of the Tree's Height is No use for us... We used it Calculate the Height of Each Individual Node from the Bottom
        int treeHeight = solve(root);
        
        // GLOBAL VARIABLE is the Answer
        return ans;
    }
};