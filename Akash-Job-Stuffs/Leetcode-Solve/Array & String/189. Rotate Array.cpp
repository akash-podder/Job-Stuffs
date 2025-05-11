class Solution {
public:
void reverse_array(vector<int>& nums, int start, int end){
    int len = end - start;
    
    for(int i=start; i<=start+(len/2); i++){
        swap(nums[i], nums[start+end-i]);
    }
}

void rotate(vector<int>& nums, int k) {
    int len = nums.size();        
    k = k%len;

    // Edge Case: if k=0, then No Rotation Call is Needed
    if(k==0){
        return;
    }

    // 3 steps --> Reverse the 2 Halves, then Reverse the Whole Array
    
    // Reverse --> 0th index upto (len-k) index
    reverse_array(nums, 0, len-k-1);
    
    // Reverse --> (len-k) index upto to Last index
    reverse_array(nums, len-k, len-1);

    // Reverse --> 0th to Last index
    reverse_array(nums, 0, len-1);
}
};