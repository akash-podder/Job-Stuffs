class Solution {
    Integer solve(int[] nums, int index, ArrayList<Integer> cache){
        if(index >= nums.length-1){
            return 1;
        }

        if(cache.get(index)!=-1){
            return cache.get(index);
        }

        int curretMaxJump = nums[index];

        for(int i = 1; i<=curretMaxJump; i++){
            // if Only One of the Jumps Return "True" we immediately Return True
            if(solve(nums, index+i, cache)==1){
                cache.set(index, 1);
                return cache.get(index); 
            }
        }

        cache.set(index, 0);
        return cache.get(index);
    }

    public boolean canJump(int[] nums) {
        ArrayList<Integer> cache = new ArrayList<>(Collections.nCopies(nums.length, -1));

        return solve(nums, 0, cache)==1? true:false;
    }
}