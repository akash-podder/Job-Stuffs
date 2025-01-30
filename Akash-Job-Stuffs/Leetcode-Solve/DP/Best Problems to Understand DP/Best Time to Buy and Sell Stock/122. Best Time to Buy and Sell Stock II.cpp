class Solution {
public:
    int solve(vector<int>& prices, int index, bool buy, vector<vector<int>> &dp) {
        // Base Case
        if(index==prices.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit = 0;

        // we CAN Buy
        if(buy==1){
            profit = max(
                -prices[index] + solve(prices, index+1, 0, dp), // we Buy
                0 + solve(prices, index+1, 1, dp) // we SKIP Buy
            );
        }

        // we CAN Sell
        else{
            profit = max(
                prices[index] + solve(prices, index+1, 1, dp), // we Sold
                0 + solve(prices, index+1, 0, dp) // we SKIP Sell
            );
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, dp); // at first we want to Buy
    }
};