// Solve-1
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
    int solve(TreeNode* current, long long int targetSum){
        // Leaf Node
        if(current->left==NULL && current->right==NULL){
            // we found 1 path so we return 1
            if(targetSum-current->val==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int no_of_path=0;
        
        // as "targetSum=0", upto this Node it has 1 Path, so start with no_path_sum=1
        if(targetSum-current->val==0){
            no_of_path=1;
        }

        if(current->left!=NULL){
            no_of_path+=solve(current->left, targetSum-current->val);
        }

        if(current->right!=NULL){
            no_of_path+=solve(current->right, targetSum-current->val);
        }

        return no_of_path;
    }

    int solve2(TreeNode* current, long long int targetSum) {
        if (current == NULL) {
            return 0;
        }

        int no_of_path = 0;

        // as "targetSum=0", upto this Node it has 1 Path, so start with no_path_sum=1
        if (targetSum == current->val) {
            no_of_path = 1;
        }

    
        no_of_path+=solve2(current->left, targetSum-current->val);
        
        no_of_path+=solve2(current->right, targetSum-current->val);

        
        return no_of_path;
    }

    // we Traverse all Node & Treat that Node as the "ROOT" & then, Invoke "solve" Function to get Paths from that Node
    void dfs(TreeNode* current, int targetSum, int &ans) {
        if(current==NULL){
            return;
        }

    // we consider a PARTICULAR Node as a Root Node & we Find Number of Paths where START will be that PARTICULAR NODE
        ans+=solve2(current, targetSum);

        dfs(current->left, targetSum, ans);
        dfs(current->right, targetSum, ans);

        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;

        dfs(root, targetSum, ans);

        return ans;
    }
};


// Solve-2
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