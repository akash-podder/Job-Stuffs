class Solution {
public:
    void solve(vector<string> &ans, int n, int len, int open, int close, string temp){
        // Base case:
        if(len==(2*n)){
            ans.push_back(temp);
            return;
        }

        // we track if Number of "open" parenthesis is Equal to "n", as we can't have more than that number of Brackets
        if(open<n){
            solve(ans, n, len+1, open+1, close, temp+"(");
        }

        // N.B.: we track if Number of "close" parenthesis is Less than Equal to current "open", because we can't have MORE "close" parenthesis than "open" parenthesis at any Given STAGE
        if(close<open){
            solve(ans, n, len+1, open, close+1, temp+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        solve(ans, n, 0, 0, 0, "");

        return ans;
    }
};