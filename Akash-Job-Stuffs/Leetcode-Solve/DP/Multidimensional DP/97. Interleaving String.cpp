class Solution {
public:
    bool solve(string s1, string s2, string s3, int i1, int i2, int i3, vector<vector<vector<int>>> &cache){
        // if(i1>=s1.size() && i2>=s2.size() && i3>=s3.size()){
        //     return true;
        // }

        // Base case:
        //base cases lies in the way you check whether the characters of s2 or s1 match s3 when one of them has been fully consumed
        if(i1>=s1.size()){
            for(int i=i2;i<s2.size();i++){
                if(s2[i]!=s3[i3++]){
                    return false;
                }
            }

            return true;
        }
        else if(i2>=s2.size()){
            for(int i=i1;i<s1.size();i++){
                if(s1[i]!=s3[i3++]){
                    return false;
                }
            }

            return true;
        }
        // Base case End

        if(cache[i1][i2][i3]!=-1){
            return cache[i1][i2][i3];
        }

        bool ans=false;
        if(s1[i1]==s3[i3] && s2[i2]==s3[i3]){
            ans = 
                (solve(s1, s2, s3, i1+1, i2, i3+1, cache) 
                || solve(s1, s2, s3, i1, i2+1, i3+1, cache));
        }
        else if(s1[i1]==s3[i3]){
            ans = solve(s1, s2, s3, i1+1, i2, i3+1, cache);
        }
        else if(s2[i2]==s3[i3]){
            ans = solve(s1, s2, s3, i1, i2+1, i3+1, cache);
        }
        else{
            ans=false; // "s3" character didn't match anyone, so we RETURN "false"
        }

        return cache[i1][i2][i3] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> cache(s1.size(), vector<vector<int>>(s2.size(), vector<int>(s3.size(), -1)));

        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        return solve(s1, s2, s3, 0, 0, 0, cache);
    }
};