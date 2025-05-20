class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end){
        while(start<=end){
            swap(nums[start], nums[end]);
            start++;
            end--;
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
        reverseArray(nums, 0, len-k-1);
        
        // Reverse --> (len-k) index upto to Last index
        reverseArray(nums, len-k, len-1);

        // Reverse --> 0th to Last index
        reverseArray(nums, 0, len-1);
    }
};