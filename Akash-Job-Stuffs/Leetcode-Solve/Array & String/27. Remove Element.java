class Solution {
    public int removeElement(int[] nums, int val) {
        int count = 0;

        // chinta koro tumi PT teacher... arr Tomar Mukh er samne Ek er por Ek Student(Numbers) ashtase... tumi tader Filter korba
        for(int i=0; i<nums.length; i++){
            if(nums[i]!=val){
                nums[count] = nums[i];
                count++;
            }
        }

        return count;
    }
}