class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();

        int low=0;
        int high=n-1;

        // we initialize "ans" with LENGTH of the array
        int ans=n;
        
        while(low<=high){
            int mid=low+((high-low)/2);

            if(nums[mid]==target){
                return mid;
            }

            // if "mid" is greater than target, that means we move the "high" pointer to the Right & "mid" COULD be our Answer, so we store it
            else if(target<nums[mid]){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};