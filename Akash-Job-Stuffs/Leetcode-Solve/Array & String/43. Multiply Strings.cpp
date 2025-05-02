class Solution {
public:
    string addAllNumbers(vector<string> numbers){
        string ans="";
        
        int maxLen=0;

        // cout<<numbers.size()<<endl;
        for(int i=0;i<numbers.size();i++){
            cout<<numbers[i]<<endl;
            int len = numbers[i].size();
            reverse(numbers[i].begin(), numbers[i].end());
            maxLen = max(maxLen, len);
        }

        int index = 0;
        int carry = 0;

        while(index<=maxLen){
            
            int sum=0;
            for(int i=0; i<numbers.size(); i++){
                int len = numbers[i].size();
                if(index<len){
                    int a = (numbers[i][index]-'0');
                    sum+=a;
                }
            }

            int currentMainSum = (sum+carry); // because after adding Previous Carry then we will get "currentMainSum"
            int digit = currentMainSum%10;
            carry = currentMainSum/10;

            ans += char(digit + '0');

            index++;
        }

        reverse(ans.begin(), ans.end());
        string realAns="";
        index=0;
        while(ans[index]=='0'){
            index++;
        }

        for(int i=index;i<ans.size();i++){
            realAns+=ans[i];
        }

        // for Test Case: num1:0 & num2:0 --> Output "0"... if this was Not Added the Answer was Showing Empty String
        if(realAns==""){
            realAns="0";
        }

        return realAns;
    }

    string multiply(string num1, string num2) {
        vector<string> numbers;
        
        int dec=0; // this is to Track Number of ZEROS Not to be Put after Each Step
        
        // in this "For Loop" we Multiply Each Number with Each Number
        for(int i=num1.size()-1;i>=0;i--){
            
            string str="";

            int carry=0;
            
            for(int j=num2.size()-1;j>=0;j--){

                int a=num1[i]-'0';
                int b=num2[j]-'0';
                
                int mul = (a*b)+carry;
                carry = mul/10;
                int digit = mul%10;
                str = char(digit + '0') + str;
            }

            if(carry>0){
                str=char(carry + '0')+str;
            }

            for(int k=0;k<dec;k++){
                str=str+'0';
            }

            // As for Each Iteration we Moving One Decimal to the Left, so we Multiply the dec with 10
            numbers.push_back(str);
            dec++;
        }

        // After all the Multiplication is done we call "addAllNumbers" basically add all the Calculated Numbers
        return addAllNumbers(numbers);
    }
};