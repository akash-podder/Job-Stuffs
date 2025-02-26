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



// ------------------------TABULATION SOLVE-----------------------

class Solution {
public:
    int tabulation_solve(vector<int>& prices){
        int n = prices.size();

        // 3D Vector --> Because we kept (index, buy, txn_count) & we initialize with 0
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3, 0)));

        // Base Case
        // index==prices.size() then, return 0
        for(int buy=0; buy<2; buy++){
            for(int txn_count=0;txn_count<=2;txn_count++){
                dp[n][buy][txn_count]=0;
            }
        }

        // txn_count==2 then, return 0
        for(int index=0;index<n;index++){
            for(int buy=0; buy<2; buy++){
                dp[index][buy][2]=0;
            }
        }

        int ans=0;

        for(int i=n-1;i>=0;i--){ // prices
            for(int buy=0;buy<=1;buy++){ // Buy or Sell
                for(int txn_count=0;txn_count<=1;txn_count++){ // Max-Count
                    
                    // We can BUY
                    if(buy==true){
                        dp[i][buy][txn_count] = max(
                            // We decide to BUY
                            -prices[i] + dp[i+1][0][txn_count],

                            // We decide to SKIP BUY
                            dp[i+1][1][txn_count]
                        );
                    }

                    // We can SELL
                    else{
                        dp[i][buy][txn_count] = max(
                            // we Decided to SELL, that's Why 1 TRANSACTION is Completed, so we INCREASE the "txn_count" with 1
                            prices[i] + dp[i+1][1][txn_count+1],

                            // we Decided to SKIP SELL
                            dp[i+1][0][txn_count]
                        );
                    }
                }
            }
        }

        // as we called --> solve(prices, 0, true, 0, cache); --> so the value will be "dp[0][true][0]"
        return dp[0][1][0];
    }

    int maxProfit(vector<int>& prices) {
        
        return tabulation_solve(prices);
    }
};