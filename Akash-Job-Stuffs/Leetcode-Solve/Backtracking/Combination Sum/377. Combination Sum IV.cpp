class Solution {
public:
    int solve(vector<int> &nums, int target, vector<int> &cache){
        // Base Case:
        if(target==0){
            return 1;
        }
        
        if(cache[target]!=-1){
            return cache[target];
        }
        
        // as (1, 1, 2) & (2, 1, 1) are counted as different combinations, as such for Each Step we LOOP Over ENTIRE Array, as such we will be taking SAME Element INFINTE Number of Times
        int ans=0;
        for(int i=0;i<nums.size();i++){
            // TAKE ---> we always TAKE
            if(target>=nums[i]){
                ans+=solve(nums, target-nums[i], cache);
            }
            // Otherwise we DON'T TAKE & Don't call Recursion
            else{
                continue;
            }
        }

        return cache[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target+1, -1);

        return solve(nums, target, cache);
    }
};