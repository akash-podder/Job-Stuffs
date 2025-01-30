class Solution {
public:
    int hammingWeight(int n) {
        int coun=0;
        while(n>0){
            if(n&1){ // checking if the "most" Right bit is "1" or "0"
                coun++;
            }
            n=n>>1; // Right Shifting the Number to move the bits to the Right
        }

        return coun;
    }
};