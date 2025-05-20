class Solution {
    public int majorityElement(int[] nums) {
        int ans=nums[0];
        int count=1;

        //think we are playing a "Kata-Kati" game... where if we Find Different Number,
        //that means, amra jake `majorityElement` dhorsi, sheitar `count` 1 ta kore katbo...
        // katte katte jodi dekhi count=0 huise... taile New ta ke `majorityElement` dhor
        for(int i=1;i<nums.length;i++){
            if(ans==nums[i]){
                count++;
            }
            else{
                count--;
                if(count==0){
                    ans=nums[i];
                    // As we are Updating the "majorityElement" that's why we start from "count=1"
                    count=1;
                }
            }
        }

        return ans;
    }
}