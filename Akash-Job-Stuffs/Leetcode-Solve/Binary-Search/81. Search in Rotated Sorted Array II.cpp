class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+((high-low)/2);
            
            if(nums[mid]==target){
                return true;
            }

            //*** Condition if nums[low]=nums[mid]=nums[high] are all EQUAL, so we SHRINK the Search Space... this condition is to REMOVE "DUPLICATES"
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue; // don't forget "continue" ***
            }

            // Left Side is Sorted
            if(nums[low]<nums[mid]){
                // if target Lies in the Left Sorted Portion we move the "high" to the Left
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            // Right Sorted Portion
            else{
                // if target Lies in the Right Sorted Portion we move the "low" to the Right
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return false;
    }
};