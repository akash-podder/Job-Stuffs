class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int k, vector<vector<vector<int>>> &dp){
        
        // Base Case: if we Run out of Days OR, the Transaction is Equal to "k", then Profit=0
        if(index==prices.size() || k==0){
            return 0;
        }

        if(dp[index][buy][k]!=-1){
            return dp[index][buy][k];
        }

        int profit=0;

        // Buy=1: You Can Buy
        if(buy==1){
            profit=max(
                -prices[index]+solve(prices, index+1, 0, k, dp), // we Bought
                
                0+solve(prices, index+1, 1, k, dp) // we Skip Buy
            );
        }

        // Buy=0: You Can Sell
        else{
            profit=max(
                prices[index]+solve(prices, index+1, 1, k-1, dp), // we Sold, we Count that Equal "1 Transaction", that's why we Reduce "k-1"
                
                0+solve(prices, index+1, 0, k, dp) // we Skip Sell
            );
        }

        return dp[index][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(prices, 0, 1, k, dp);
    }
};