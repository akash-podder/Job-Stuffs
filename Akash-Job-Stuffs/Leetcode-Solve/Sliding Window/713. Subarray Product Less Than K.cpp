class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int left = 0, right = 0;
        int mul = 1;

        while(right<nums.size()){
            mul = mul*nums[right];

            // if "mul" is Greater Than Equal "k", then we increase the Left Pointer & Shrink the Window
            while(mul>=k){
                // "Left" CAN NOT be Greater than "Right"
                if(left>right){
                    break;
                }
                mul = mul/nums[left];
                left++;
            }
            // New Number of Subarrays Added will be: Length = Right-Left+1
            if(mul<k){
                count = count + (right-left+1);
            }

            right++;
        }

        return count;
    }
};