class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstOccr = -1;
        int lastOccr = -1;
        int n = nums.size();

        int low = 0;
        int high = n-1;

        // First Occurrence
        while(low<=high){
            int mid = low+((high-low))/2;

            if(nums[mid]==target){
                firstOccr=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        // Last Occurrence

        // re-initializing
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = low+((high-low))/2;

            if(nums[mid]==target){
                lastOccr=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        ans.push_back(firstOccr);
        ans.push_back(lastOccr);

        return ans;
    }
};