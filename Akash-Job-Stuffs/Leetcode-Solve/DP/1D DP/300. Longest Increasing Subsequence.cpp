class Solution {
public:
    int tabulation(vector<int>& nums, int curr_idx, int prev_idx, vector<vector<int>> &dp){
        // BASE CASE
        // if there is NO Element in the Subsequence then, the Length is 0
        for(int j=0;j<=prev_idx;j++){
            dp[0][j] = 0;
        }

        for(int i=0;i<=curr_idx;i++){
            for(int j=0;j<=prev_idx;j++){
                
                int take = 0, not_take=0;
                // we have to Keep TRACK Which was the Last Element we Picked Up in Our SubSequence
                if(j==nums.size() || nums[i]<nums[j]){
                    take = 1 + dp[i][i];
                }

                not_take = 0 + dp[i][j];

                dp[i+1][j] = max(take, not_take);
            }
        }

        return dp[curr_idx+1][prev_idx];
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int prev_idx = len;

        // Right Shift "curr_idx" with 1
        vector<vector<int>> dp(len+1, vector<int>(len+1,-1));
        return tabulation(nums, len-1, prev_idx, dp);
    }
};