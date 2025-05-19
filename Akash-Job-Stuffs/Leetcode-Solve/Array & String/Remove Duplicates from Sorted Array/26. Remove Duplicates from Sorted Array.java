class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 1; // `k` Track rakhbe kon Index ke Next Replace korte hobe... mane, Next kono Different Number Paile amra Kon INDEX ee taar Value Store kore rakhbo sheita Nirdesh kore
        
        int current = nums[0]; // As we have to Keep Track of Duplciate Elements

        for(int i=1;i<nums.length;i++){
            // Duplicate Element so, we Skip it
            if(nums[i]==current){
                continue;
            }
            else{
                nums[k] = nums[i];
                k++;
                current = nums[i]; // Updating the "current" Variable
            }
        }

        return k;
    }
}