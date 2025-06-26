class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // the Problem Statement can also be seen as we can afford AT MOST "k" zeros in our "subarray (consecutive array)"

        int left = 0, right = 0;
        int zeros = 0;
        int ans = 0;

        while(right<nums.size()){
            if(nums[right]==0) {
                zeros++;
            }

            // Shrinking the Window when Number of "zeros" is greater than "k"
            // OPTIMIZE Solution: instead of doing "while" Loop O(N^2) we just Shrink it Once, because we there is No Need to Shrink the Window Further more, for example: we got ans=5, then if we shrink the window=4, then there is No Point, as we already know At least our Answer is "5", so, we Move Right Pointer with Same Window Size & check in Each Step if our "left" Pointer points to Zero & we decrease "zeros"
            // while(zeros>k){
            if(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }

                left++;
            }

            // taking the MAX of the Answer
            else if(zeros<=k){
                ans = max(ans, right-left+1);
            }

            right++;
        }


        return ans;
    }
};