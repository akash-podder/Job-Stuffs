class Solution {
public:
    int solve(vector<int>& prices, int index, bool buy, int transaction, vector<vector<vector<int>>> &dp) {
        // Base Case
        if(index==prices.size() || transaction==2){
            return 0;
        }

        if(dp[index][buy][transaction]!=-1){
            return dp[index][buy][transaction];
        }

        int profit = 0;

        // we CAN Buy
        if(buy==1){
            profit = max(
                -prices[index] + solve(prices, index+1, 0, transaction, dp), // we Buy
                0 + solve(prices, index+1, 1, transaction, dp) // we SKIP Buy
            );
        }

        // we CAN Sell
        else{
            profit = max(
                prices[index] + solve(prices, index+1, 1, transaction+1, dp), // we Sold --> 1 Transaction Complete
                0 + solve(prices, index+1, 0, transaction, dp) // we SKIP Sell
            );
        }

        return dp[index][buy][transaction] = profit;
    }

    int maxProfit(vector<int>& prices) {
        // 3D Vector --> Because we kept (index, buy, transaction_count)
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(prices, 0, 1, 0, dp); // at first we want to Buy
    }
};