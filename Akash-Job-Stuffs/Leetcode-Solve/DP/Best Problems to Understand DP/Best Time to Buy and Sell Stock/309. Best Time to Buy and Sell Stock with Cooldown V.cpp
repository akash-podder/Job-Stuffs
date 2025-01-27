class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>> &dp){
        // Base Case: if we Ran out of Days then there will be No Profit
        if(index>=prices.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit = 0;
        // if Buy = 1 : we can buy
        if(buy==1){
            profit = max(
                -prices[index] + solve(prices, index+1, 0, dp), // we Bought
                0 + solve(prices, index+1, 1, dp) // we SKIP Buy
            );
        }

        // if Buy = 0 : we can Sell
        else{
            profit = max(
                prices[index] + solve(prices, index+2, 1, dp), // we Sold: as there is a COOLDOWN of 1 Day so, we Move (index+2), as One Transaction is Complete
                0 + solve(prices, index+1, 0, dp) // we SKIP Buy
            );
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        
        return solve(prices, 0, 1, dp);
    }
};