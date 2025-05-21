class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList();
        Arrays.sort(nums);

        // fixing "i'th" index & then doing Two Pointer Search (similar to Binary Search, But Not Binary Search) with "j" & "k" pointer
        for(int i=0;i<nums.length;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // To avoid "Duplicates" of "i"

            int j = i+1; // Low
            int k = nums.length - 1; // High

            while(j<k){

                int target = nums[i] + nums[j] + nums[k]; // as: nums[i] + nums[j] + nums[k] = 0
                
                if(target<0){
                    j++;
                }
                else if(target>0){
                    k--;
                }
                else{
                    List<Integer> list = new ArrayList();
                    list.add(nums[i]);list.add(nums[j]);list.add(nums[k]);
                    j++;
                    k--;

                    // Only skip duplicates after a valid triplet is found
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;

                    ans.add(list);
                }
            }
        }

        return ans;
    }
}