class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+((high-mid)/2);

            // Left Side is Sorted, so, we Store/Compare the "Low index's Value" and Move to "Low" to "Right"
            if(nums[low]<=nums[mid]){
                ans=min(ans, nums[low]);
                low=mid+1;
            }

            // Right Side is Sorted, so, we Store/Compare the "Mid's Value" and move the "High" to "Left"
            else{
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }

        return ans;
    }
};