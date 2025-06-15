class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;

        int count = 0;

        // skipping WhiteSpace or Leading Zero
        while(s[count]==' '){
            count++;
            if(count>=s.size()){
                break;
            }
        }

        bool isZero = false;
        while(s[count]=='0'){
            isZero = true;
            count++;
            if(count>=s.size()){
                break;
            }
        }

        int mul = 1;
        if(count<s.size()){
            if(s[count]=='+'){
                if(isZero) return 0;
                mul = 1;
                count++;
            }
            else if(s[count]=='-'){
                if(isZero) return 0;
                mul = -1;
                count++;
            }
        }

        for(int i=count; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                // case to fit 32-Bit Integer
                if(ans*mul>INT_MAX) return INT_MAX;
                if(ans*mul<INT_MIN) return INT_MIN;
                
                ans = (ans*10) + (s[i]-'0');
            }
            else{
                break;
            }
        }

        // case to fit 32-Bit Integer
        if(ans*mul>INT_MAX) return INT_MAX;
        if(ans*mul<INT_MIN) return INT_MIN;

        return ans * mul;
    }
};