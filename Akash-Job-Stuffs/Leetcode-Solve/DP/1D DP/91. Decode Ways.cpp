class Solution {
public:
    int solve(string s, int index, vector<int> &cache){
        // as we are Counting Number of ways we just Return 1, this 1 will denote How Many Times we Hit the Bottom/End of the Recursive Tree. And while Calling the Recursive SOLVE Function we just “Add (+)” with it → ans = ans + solve(s, index+2, cache); → Like this
        if(index==s.size()){
            return 1;
        }

        if(cache[index]!=-1){
            return cache[index];
        }
        
        int count=0;

        // checking if the First Character is '0' or NOT, if '0' we Ommit it
        if(s[index]>='1' && s[index]<='9'){

            // *** Think it like TAKE or NOT TAKE ***
            // But here is 2 TAKE Scenerios

            // At Every Index we can Decode in 2-ways...
            // 1st way ---> We Take the Current Char
            // 2nd way ---> We can ONLY TAKE if: COMBINE with the Next Character if these Two characters Form Less than 26


            // 1st Way ---> Always TAKE
            count=solve(s, index+1, cache);
            

            // 2nd Way... We can Only Take if between (10-26) Range
            // first we check if "(index+1)" Doesn't Exhaust the String
            if(index+1<s.size()){
                // (10-26) --> for these Values
                if(s[index]=='1' || (s[index]=='2' && s[index+1]>='0' && s[index+1]<='6')){
                    count=count+solve(s, index+2, cache);
                }
            }
        }

    
        return cache[index] = count;
    }

    int numDecodings(string s) {
        int len = s.size();
        vector<int> cache(len, -1);

        return solve(s, 0, cache);
    }
};