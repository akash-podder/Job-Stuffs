class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // for Array Length = 1
        if(nums.size()==1){
            return 0;
        }

        // if 0th or (n-1)th element is the Peak Element
        if(nums[0]>nums[1]){
            return 0;
        }

        int len=nums.size();
        if(nums[len-1]>nums[len-2]){
            return len-1;
        }

        int low=1;
        int high=nums.size()-2;
        
        while(low<=high){
            int mid = low+((high-low)/2);

            // if mid == peak --> we RETURN the Answer
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            
            // upward slope and search space right side
            else if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            
            // downward slope and search space left side
            else if(nums[mid-1]>nums[mid]){
                high=mid-1;
            }
        }
        
        // dummy return, as there will be a Peak Element
        return -1;
    }
};