class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 1; // `k` Track rakhbe kon Index ke Next Replace korte hobe... mane, Next kono Different Number Paile amra Kon INDEX ee taar Value Store kore rakhbo sheita Nirdesh kore

        int current = nums[0];
        int count=1; // Count is to Track jano At Most "Twice" hui
        
        for(int i=1;i<nums.length;i++){
            if(nums[i]==current){
                if(count<2){
                    nums[k] = nums[i];
                    k++;
                    count++;
                }
            }
            else{
                nums[k] = nums[i];
                k++;
                count=1;
                current=nums[i];
            }
        }

        return k;
    }
}