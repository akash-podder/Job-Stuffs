class Solution {
public:
    int trailingZeroes(int n) {
        // Trailing zeroes in a number are created by factors of 10, which are the product of factors 2 and 5. Since there are always more factors of 2 (because most of the numbers are EVEN) than 5 in ( n! ), the number of trailing zeroes is determined by the number of factors of 5. To count the factors of 5, we divide ( n ) by powers of 5 and sum the results.

        int ans=0;

        while(n>0){
            n=(n/5); // Count multiples of 5, 25, 125, etc.
            ans+=n;
        }

        return ans;
    }
};