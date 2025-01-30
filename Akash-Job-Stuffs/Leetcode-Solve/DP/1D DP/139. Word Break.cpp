class Solution {
public:
    bool solve(string s, int index, vector<string>& wordDict, vector<int> &cache){
        // Base Case:

        // if we reached to the End that means we can achieve "s" string from the "wordDict"
        if(index==s.size()){
            return true;
        }
        else if(index>s.size()){
            return false;
        }

        if(cache[index]!=-1){
            return cache[index];
        }

        bool ans = false;
        
        // for every "wordDict"'s String, we check, if we can MATCH "s" string's REMAINING String. Remaining String is "TRACKED" by "index" variable
        for(int i=0;i<wordDict.size();i++){
            string curr_str = wordDict[i];

            bool flag=true;
            for(int j=0;j<curr_str.size();j++){
                if(s[j+index]!=curr_str[j]){
                    flag = false; // if "flag" is FALSE means, we Don't have to CALL Recursion as the "ans=false"
                    break;
                }
            }

            if(flag==true){
                // if any of the answer gives "TRUE", then we return true, that's why we use "OR" operand
                ans = ans || solve(s, index+curr_str.size(), wordDict, cache);
            }
        }
        
        return cache[index]=ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<int> cache(len, -1);
        
        return solve(s, 0, wordDict, cache);
    }
};