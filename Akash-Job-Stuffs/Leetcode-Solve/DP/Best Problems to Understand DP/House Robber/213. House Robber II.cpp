class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& cache){
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
        
        if(n==1){
            return nums[0];
        }
        
        //Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.

        vector<int> numsN_with_last_index; // (n-1 to 1)
        vector<int> numsN_with_first_index; // (n-2 to 0)

        for(int i=0;i<nums.size();i++){
            if(i==0){
                numsN_with_first_index.push_back(nums[i]);
            }
            else if(i==nums.size()-1){
                numsN_with_last_index.push_back(nums[i]);
            }
            else{
                numsN_with_first_index.push_back(nums[i]);
                numsN_with_last_index.push_back(nums[i]);
            }
        }


        vector<int> cache1(numsN_with_first_index.size(), -1);
        vector<int> cache2(numsN_with_last_index.size(), -1);

        return max(
            solve(numsN_with_first_index, numsN_with_first_index.size()-1, cache1),
            solve(numsN_with_last_index, numsN_with_last_index.size()-1, cache2)
        );
    }
};