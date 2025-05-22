class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length-1;

        int ans = 0;

        while(low<=high){
            int mid  = low + ((high-low)/2);

            if(nums[mid]==target){
                return mid;
            }
            // After the End of the Loop, "low" will be the first index where nums[low] >= target, i.e., the place to insert target
            // this mean Target is on the Right
            else if(nums[mid]<target){
                low = mid+1;
                ans = low;
            }

            // this mean Target is on the Left
            else{
                high = mid-1;
            }
        }


        return ans;
    }
}