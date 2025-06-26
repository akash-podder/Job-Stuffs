class Solution {
public:
    int getNumberOfSubArraysLessThan(vector<int>& nums, int k){
        int count = 0;

        map<int, int> Map;
        int left = 0, right = 0;

        while(right<nums.size()){
            Map[nums[right]]++;

            // Number of "Distinct Number" is greater than "k"
            while(Map.size()>k){
                Map[nums[left]]--;

                if(Map[nums[left]]==0){
                    Map.erase(nums[left]);
                }

                // We Shrink the Window
                left++;
            }

            if(Map.size()<=k){
                // when, we Include One "Element" to our existing Window then we can have "N" (start to finish) Number of Subarrays to our Existing Window... so we ADD "N" to our Current Count
                // here "start to finish" = (right-left+1)
                count = count + (right-left+1);
            }

            // we always move Forward
            right++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // we find (Number of Subarrays <=k) & (Number of Subarrays <=k-1)... And then if Subtract then we get the Exact Number of Subarrays with EXACTLY "k" DIFFERENT Numbers

        int ans = getNumberOfSubArraysLessThan(nums, k) - getNumberOfSubArraysLessThan(nums, k-1);

        return ans;
    }
};