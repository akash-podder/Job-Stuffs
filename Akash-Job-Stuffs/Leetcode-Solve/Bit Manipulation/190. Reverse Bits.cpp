class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;

        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){ // this is to Extract "i'th" Bit if we see it's "NOT 0 (anything but 0)"
                ans=(ans|(1<<(31-i))); // if i'th bit is "NOT 0" Only Then we Add the 1 in the (31-i)'th bit of our "ans" with "OR" operation, because we want to Reverse it
            }
        }

        return ans;
    }
};