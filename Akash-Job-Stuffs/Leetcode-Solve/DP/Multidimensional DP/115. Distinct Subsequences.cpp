class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &cache){
        // Base Case-1: this means all the Characters Matched
        if(j==t.size()){
            return 1;
        }
        // Base Case-2: this means string "s" got exhausted and all the Characters Didn't match
        if(i==s.size()){
            return 0;
        }

        if(cache[i][j]!=-1){
            return cache[i][j];
        }

        int ans = 0;

        // Take
        // if the Characters Matched we increase Both Pointers
        if(s[i]==t[j]){
            ans += solve(s, t, i+1, j+1, cache);
        }

        // Not Take
        // the Characters NOT Matched, we increase only "s" Strings Pointer
        ans += solve(s, t, i+1, j, cache);

        return cache[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> cache(s.size() + 1, vector<int>(t.size() + 1, -1));

        return solve(s, t, 0, 0, cache);
    }
};