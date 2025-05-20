class Solution {
    int binarySearch(int[] nums, int target){
        int low = 0;
        int high = nums.length-1;

        while(low<=high){
            int mid = low + ((high-low)/2);

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }

    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        // making sure "nums1" is the Smaller array for better perfomance of Binary Search
        if(nums1.length>nums2.length){
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        Set<Integer> mySet = new HashSet<Integer>();
        for(int i=0; i<nums1.length; i++){
            int target = nums1[i];

            if(binarySearch(nums2, target)!=-1){
                mySet.add(target);
            }
        }

        int[] ans = new int[mySet.size()];

        int count = 0;
        for (int item : mySet) {
            ans[count] = item;
            count++;
        }

        return ans;
    }
}