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
    int calculatePathSum(TreeNode* root, long long int targetSum) {
        if (root == NULL) return 0;

        int paths = 0;
        if (targetSum == root->val) paths = 1;

        // Recursive calls to find paths that sum up to targetSum in the left and right subtrees
        return paths + calculatePathSum(root->left, targetSum - root->val) + calculatePathSum(root->right, targetSum - root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        // Initialize the total count of paths that sum to targetSum
        int ans = 0;

        // Stack for iterative DFS traversal
        stack<TreeNode*> s;
        s.push(root);

        // Traverse each node and consider it as a starting point for calculating paths
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            if (current != NULL) {
                // For each node, calculate the number of paths that start from that node and sum to targetSum
                ans += calculatePathSum(current, targetSum);

                // Push left and right children to the stack to consider them as potential starting points
                s.push(current->left);
                s.push(current->right);
            }
        }

        return ans;
    }
};