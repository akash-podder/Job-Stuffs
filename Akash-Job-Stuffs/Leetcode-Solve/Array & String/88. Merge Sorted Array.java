class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index = m + n -1;
        
        int i = m-1;
        int j = n-1;

        // As, we have to Merge the Sorted Array "In-Place", that's why we Traverse from the Last, as "nums1" Element in the Last has 0's in it
        while(i>=0 && j>=0){

            // As we are Sorting from the Last, so, the LARGER Element will be put there First
            if(nums1[i]>=nums2[j]){
                nums1[index] = nums1[i];
                i--;
            }
            else{
                nums1[index] = nums2[j];
                j--;
            }

            // in Both Case we Decrease the "index"
            index--;
        }

        while(i>=0){
            nums1[index] = nums1[i];
            i--;
            index--;
        }

        while(j>=0){
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
}