class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    // we are Storing the Answer in "reverse word"
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
            else{
                temp+=s[i];
            }
        }

        if(temp!=""){
            ans = temp + " " + ans;
            temp = "";
        }
        
        // Removing the last EXTRA SPACE
        if(ans.size()>=0){
            ans.erase(ans.size()-1);
        }

        return ans;
    }
};