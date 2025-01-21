// Solve-1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        int xor_0_to_n=0;
        for(int i=0;i<=n;i++){
            xor_0_to_n=xor_0_to_n^i;
        }

        int xor_of_nums=0;
        for(int i=0;i<nums.size();i++){
            xor_of_nums=xor_of_nums^nums[i];
        }

        // as we Know, "XOR" with Same Number Cancel out itself, so Only Number will be Left is the "Missing" Number in (0 to N)
        return (xor_0_to_n^xor_of_nums);
    }
};

//////////////////////////////////////////////////////////

// Solve-2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int totalSum=(n*(n+1))/2; // as we Know from (1 to N) the Summation Formula is (n*(n+1))/2
        int arraySum=0;

        for(int i=0;i<nums.size();i++){
            arraySum+=nums[i];
        }

        return (totalSum-arraySum);
    }
};