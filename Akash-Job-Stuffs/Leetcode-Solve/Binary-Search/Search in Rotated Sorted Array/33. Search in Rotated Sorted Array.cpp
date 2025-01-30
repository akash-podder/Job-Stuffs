class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+((high-low)/2);
            
            if(nums[mid]==target){
                return mid;
            }

            // ***Rotated Sorted Array te First kaaj "mid" kon pasher SORTED er porse eita check kora***
            // "mid" is In Left Sorted Portion
            else if(nums[low]<=nums[mid]){
                // Now, we check if "target" LIES in SORTED Portion Or Not,
                // if YES, that means we can GO to that Direction... and move "high" to left
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            // "mid" is In Right Sorted Portion
            else{
                // Now, we check if "target" LIES in SORTED Portion Or Not,
                // if YES, that means we can GO to that Direction... and move low to the right
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};