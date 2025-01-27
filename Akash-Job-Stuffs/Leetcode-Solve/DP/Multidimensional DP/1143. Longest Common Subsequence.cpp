class Solution {
public:
    int solve(string text1, string text2, int i1, int i2, vector<vector<int>> &dp){
        if(i1==0 || i2==0){
            return dp[i1][i2]=0;
        }

        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        // MATCH ---> we "+1" plus call Recursively
        if(text1[i1-1]==text2[i2-1]){
            return dp[i1][i2] = 1 + solve(text1, text2, i1-1, i2-1, dp);
        }

        // NOT MATCH ---> we take the MAX of decreasing the "i1" pointer & "i2" pointer
        else{
            return dp[i1][i2] = 0 + max(solve(text1, text2, i1, i2-1, dp), solve(text1, text2, i1-1, i2, dp));
        }
    }

    int tabulation(string text1, string text2, int i1, int i2, vector<vector<int>> &dp){
        // Base Cases
        for(int x=0;x<=i2;x++){
            dp[0][x] = 0;
        }

        for(int x=0;x<=i1;x++){
            dp[x][0] = 0;
        }

        for(int k=1;k<=i1;k++){
            for(int j=1;j<=i2;j++){
                // MATCH ---> we "+1" plus call Recursively
                if(text1[k-1]==text2[j-1]){
                    dp[k][j] = 1 + dp[k-1][j-1];
                }

                // NOT MATCH ---> we take the MAX of decreasing the "i1(k)" pointer & "i2(j)" pointer
                else{
                    dp[k][j] = 0 + max(dp[k][j-1], dp[k-1][j]);
                }
            }    
        }

        return dp[i1][i2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();

        // we shifted Everything to 1-index Right
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, -1));

        return tabulation(text1, text2, s1, s2, dp);
    }
};