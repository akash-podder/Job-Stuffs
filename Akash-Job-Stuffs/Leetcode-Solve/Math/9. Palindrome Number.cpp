class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        long long int current_x=x;
        long long int rev_x=0;

        while(x>0){
            int digit=x%10;
            rev_x=(rev_x*10)+digit;

            x=x/10;
        }

        if(rev_x==current_x){
            return true;
        }
        else{
            return false;
        }
    }
};