class Solution {
public:
    double myPow(double x, int n) {
        // Some Manually Handled Cases
        if(n==0){
            return 1;
        }
        if(x==1){
            return 1;
        }
        if(x==0){
            return 0;
        }
        
        bool sign=true; // if true --> positive number, false --> negative number

        // Manually handled case: otherwise, integer will OVERFLOW when multiplying with "-1", that's why we are taking "long"
        long Pow_N = n;

        if(Pow_N<0){
            sign=false;
            Pow_N=Pow_N*(-1);
        }

        double ans=1; // as we are Multiplying everything with "ans", that's why we keep "ans=1"
        
        while(Pow_N>1){
            if(Pow_N%2==0){ // EVEN
                x=x*x; // if it's even we just SQUARE the Number
                Pow_N=Pow_N/2;
            }
            else{ // ODD
                ans=ans*x; // we just keep the EXTRA "Number" in a variable, example: 4^5 = 4 * 4^4 ---> here, we keep aside the "4" in "ans" variable and remaining (4^4) would go on to the next loop and will Enter the "Even" condition
                Pow_N--;
            }
        }
        
        // *** at the END we just Multiply tge
        ans = ans*x;

        if(sign==false){
            ans=((double)1)/ans;
        }

        return ans;
    }
};