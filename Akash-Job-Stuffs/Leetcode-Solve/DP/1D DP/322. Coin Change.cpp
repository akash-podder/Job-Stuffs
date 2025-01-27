class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& cache) {
        if(amount==0) {
            return 0;
        }

        // if cache exists, we Return the cache
        if(cache[amount]!=-1) {
            return cache[amount];
        }

        int Min=INT_MAX; // Min is set to INT_MAX
        for(int i=0;i<coins.size();i++) {
            if(amount>=coins[i]) {
                // if cache doesn't exist, we UPDATE the cache
                if (cache[amount-coins[i]]==-1) {
                    cache[amount-coins[i]]=solve(coins, amount-coins[i], cache);
                }

                // check if the Integer gets OverFlow
                if(cache[amount-coins[i]]!=INT_MAX){
                    Min=min(Min, 1+cache[amount-coins[i]]);
                }
            }
        }
        
        return cache[amount]=Min;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> cache(amount+1, -1);
        int ans = solve(coins, amount, cache);
        return ans==INT_MAX? -1: ans; //if INT_MAX is found then, we can't be made up by any combination of the coins
    }
};