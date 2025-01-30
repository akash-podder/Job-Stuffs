class Solution {
public:
    int mySqrt(int x) {

        //use Binary Search
        int low = 0, high = x;
        long long int mid=0, ans=0;

        while(high>=low){
            mid = (high+low)/2;

            if(mid*mid==x){
                return mid;
            }

            else if(mid*mid>x){
                high = mid-1;

                // The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned
                ans=mid-1; // in this case: Mid=3, so we subtract to make it 2
            }

            else if(mid*mid<x){
                low = mid+1;


                // The square root of 6 is 2.4494..., and since we round it down to the nearest integer, 2 is returned
                ans=mid; // in this case: Mid=2, so we don't subtract
            }
        }

        return ans;
    }
};