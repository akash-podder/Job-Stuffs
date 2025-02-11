class Solution {
    public:
        int solve(string &s, int index, vector<int> &cache){
            if(index==s.size()){
                return 1; // as we are Counting Number of ways we just Return 1, this 1 will denote How Many Times we Hit the Bottom/End of the Recursive Tree. And while Calling the Recursive SOLVE Function we just “Add (+)” with it → ans = ans + solve(s, index+2, cache); → Like this
            }
    
            if(cache[index]!=-1){
                return cache[index];
            }
    
            // if character is "0" We just Ommit it
            if(s[index]=='0'){
                return 0;
            }
    
            // At Every Index we can Decode in 2-ways 
            // 1st way ---> We Take the Current Char
            // 2nd way ---> we can COMBINE with the Next Character if these Two characters Form Less than 26
            
            int ans=0;
    
            // 1st Way
            ans = solve(s, index+1, cache);
    
            // 2nd Way... first we check if "(index+1)" Doesn't Exhaust the String
            if(index+1<s.size()) {
                // (10-26) --> for these Values
                if(s[index]=='1' || (s[index]=='2' && s[index+1]>='0' && s[index+1]<='6')){
                    ans = ans + solve(s, index+2, cache);
                }
            }
            
    
            return cache[index] = ans;
        }
    
    
        int numDecodings(string s) {
            vector<int> cache(s.size(), -1);
    
            return solve(s, 0, cache);
        }
    };