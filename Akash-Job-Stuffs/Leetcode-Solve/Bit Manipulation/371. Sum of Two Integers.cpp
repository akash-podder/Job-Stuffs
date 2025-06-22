class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;

        for(int i=0; i<=31; i++){
            // Extracting "i'th" Bit
            int digitA = ((a>>i) & 1);
            int digitB = ((b>>i) & 1);
            
            int add = 0;
            add = (digitA ^ digitB);
            add = add ^ carry;

            // "if any Combination of TWO Variables where the Digit is 1, then the Carry is 1"
            carry = (digitA & digitB) | (digitA & carry) | (digitB & carry);

            // setting "i'th" Bit
            ans = ans | (add<<i); 
        }

        return ans;
    }
};