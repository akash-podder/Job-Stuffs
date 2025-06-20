class KthLargest {
    PriorityQueue<Integer> pq;
    int kGlobal; // to know the "k" value as it is local in "Constructor"

    public KthLargest(int k, int[] nums) {
        // Min Heap
        // we are using "Min Heap" because as such the "k'th" largest element will be in the TOP of the Heap, as "k'th" Largest means that there (k-1) Larger values in the "Heap".
        pq = new PriorityQueue<Integer>();
        kGlobal = k;

        for(int i=0;i<nums.length;i++){
            if(pq.size()<k){
                pq.add(nums[i]);
            }
            else{
                // if it's more than "k" element we Pop the MINIMUM element from the "Top"
                if(pq.peek()<nums[i]){
                    pq.poll();
                    pq.add(nums[i]);
                }
            }
        }
    }
    
    public int add(int val) {
        int k = kGlobal;

        if(pq.size()<k){
            pq.add(val);
        }
        else{
            // if it's more than "k" element we Pop the MINIMUM element from the "Top"
            if(pq.peek()<val){
                pq.poll();
                pq.add(val);
            }
        }

        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */