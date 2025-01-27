class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& cache) {
        if(n<0){
            return 0;
        }

        if(n==0){
            return nums[0];
        }
        
        if(cache[n]!=-1){
            return cache[n];
        }

        int taken = nums[n] + solve(nums, n-2, cache);
        int not_taken = solve(nums, n-1, cache);

        return cache[n] = max(taken, not_taken);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        return solve(nums, n-1, cache);
    }
};