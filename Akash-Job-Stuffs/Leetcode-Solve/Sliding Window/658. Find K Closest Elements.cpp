class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int left = 0, right = k;

        // we keep a FIXED size Window of "k" length
        // here, "left" is the Farthest from "x" integer... So, by moving to the Right, if we find that there is No More "right" index that is Closer to "x" then at that Time that Particular Window is our Answer
        while(right<nums.size()){
            // ">=" use kora jabe Nah caz, Test case: [1,2,3,4,5], k=4, x=3 te x theke Both "1" & "5" er Distance "3"... But according Question we have to Choose the minimum which is "1", That's why Only SAME Number (else if condiiton) huilei amra Pointer Move korbo
            if(abs(nums[left]-x) > abs(nums[right]-x)){
                left++;
                right++;
            }
            // Test Case: [1,1,1,10,10,10], k=1, x=9... Answer: [10]... That's why SAME Number hole amra arro Right Side ee Move korbo
            else if(nums[left]==nums[right]){
                left++;
                right++;
            }
            else{
                break;
            }
        }

        vector<int> ans;
        for(int i=left; i<right; i++){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};