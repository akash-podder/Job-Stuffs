//--------------------Recursive Memoization Solve---------------------

class Solution {
public:
    int solve(vector<int>& nums, int n, int sum, vector<vector<int>>& cache){
        if(sum==0){
            return 1;
        }

        if(cache[n][sum]!=-1){
            return cache[n][sum];
        }

        if(n==0){
            return (nums[n]==sum)? 1:0;
        }

        int not_taken = solve(nums, n-1, sum, cache);
        int taken=0;
        if(nums[n]<=sum){
            taken = solve(nums, n-1, sum-nums[n], cache);
        }

        return cache[n][sum] = (taken || not_taken);
    }
    bool canPartition(vector<int>& nums) {
        // S1+S2 = TotalSum, and S1=S2 (As equal Subset), so, S1+S1= TotalSum,
        // So, S1 = TotalSum/2;
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        if(totalSum%2!=0){
            return false;
        }

        int n=nums.size();
        vector<vector<int>> cache(n, vector<int>((totalSum/2)+1, -1));

        return solve(nums, n-1, totalSum/2, cache);
    }
};


//--------------------TABULATION Solve---------------------
class Solution {
public:
    int solve(vector<int>& nums, int n, int sum, vector<vector<int>>& cache){
        if(sum==0){
            return 1;
        }

        if(cache[n][sum]!=-1){
            return cache[n][sum];
        }

        if(n==0){
            return (nums[n]==sum)? 1:0;
        }

        int not_taken = solve(nums, n-1, sum, cache);
        int taken=0;
        if(nums[n]<=sum){
            taken = solve(nums, n-1, sum-nums[n], cache);
        }

        return cache[n][sum] = (taken || not_taken);
    }
    bool canPartition(vector<int>& nums) {
        // S1+S2 = TotalSum, and S1=S2 (As equal Subset), so, S1+S1= TotalSum,
        // So, S1 = TotalSum/2;
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        if(totalSum%2!=0){
            return false;
        }

        int n=nums.size();
        vector<vector<int>> cache(n, vector<int>((totalSum/2)+1, -1));

        return solve(nums, n-1, totalSum/2, cache);
    }
};