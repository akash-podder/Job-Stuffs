// Solution-1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal=prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++){
            profit=max(profit, prices[i]-minVal);
            minVal = min(minVal, prices[i]);
        }

        return profit;
    }
};


////////////////////////////////////////////////////////////////////////

// Solution-2
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
                prices[index], // we Sold, we can't SELL in the FUTURE, that's why NO Recursive Call for the FUTURE... it's the MAIN Difference between Normal "Buy and Sell-1" vs "Buy and Sell-2"
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