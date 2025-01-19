class Solution {
public:
    map<int, vector<char>> Map = {
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };
    
    void solve(string digits, int n, string str, vector<string> &ans){
        //BASE Case: End of Traversing "digits" String, so we just Put the String in the "ans" vector
        if(n==digits.size()){
            ans.push_back(str);
            return;
        }

        int x = digits[n]-'0';
        for(int i=0;i<Map[x].size();i++){
            solve(digits, n+1, str+Map[x][i], ans);
            // cout<<Map[x][i]<<" ";
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;

        if(digits.size()==0) { // Case: "" ---> ans: []
            return ans;
        }

        // we Generate Every Possible case with RECURSION
        solve(digits, 0, "", ans);

        return ans;
    }
};