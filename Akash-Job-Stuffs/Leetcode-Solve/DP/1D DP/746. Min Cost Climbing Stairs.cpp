class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size()+1, -1);

        // we start Traversing "Backward" from "Top of the Floor" to the 0th or 1th step
        return dp(cost.size(), cost, cache);
    }

    int dp(int n, vector<int>& cost, vector<int>& cache) {
        if(n==0 || n==1){
            return 0;
        }

        // we just CACHE the Previous "Recursive" Method, this is DP
        if(cache[n]==-1){
            
            //as we are Traversing "Backward", so, we just MIN from with "(n-1)th & (n-2)th Step"
            cache[n]=min(cost[n-1]+dp(n-1, cost, cache), cost[n-2]+dp(n-2, cost, cache));
        }

        return cache[n];
    }
};