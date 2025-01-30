class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0, sum=0;

        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1){
                sum+=1;
            }
            sum+=digits[i]+carry;
            if(sum>9){
                digits[i]=sum-10;
                carry=1;
            }
            else{
                digits[i]=sum;
                carry=0;
            }
            sum=0;
        }

        //cases like: [9], [9, 9] etc.
        if(carry>0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};