//----------------- Recursive Memoization Solve -------------------
#include <bits/stdc++.h>

bool solve(int index, int k, vector<int> &arr, vector<vector<int>> &cache){

    // Base Case:
    if(k==0) {
        return true;
    }
    if(index==0){
        if(arr[index]==k) {
            return true;
        }
        else {
            return false;
        }
    }
    // Base Case END


    if(cache[index][k] != -1){
        return cache[index][k];
    }

    // TAKE
    bool take = false;
    // we have to check this Condition, otherwise "k" would go to Below Zero, means Negative
    if(k>=arr[index]) {
        take = solve(index-1, k-arr[index], arr, cache);
    }

    // NOT Take
    bool notTake = solve(index-1, k, arr, cache);

    return cache[index][k] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> cache(n, vector<int>(k+1, -1));

    return solve(n-1, k, arr, cache);
}


//----------------- TABULATION SOLVE -------------------
#include <bits/stdc++.h>

bool tabulation(int n, int sum, vector<int> &arr){
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    // Base Case
    for(int index=0; index<n; index++){
        dp[index][0] = 1;
    }

    for(int i=0; i<=sum; i++){
        if(arr[0]==i){
            dp[0][i] = 1;
        }
    }

    for(int index=1; index<n; index++){
        for(int k=0; k<=sum; k++){
            bool take = false;
            // we have to check this Condition, otherwise "k" would go to Below Zero, means Negative
            if(k>=arr[index]) {
                take = dp[index-1][k-arr[index]];
            }

            // NOT Take
            bool notTake = dp[index-1][k];

            dp[index][k] = (take || notTake);
        }
    }

    return dp[n-1][sum];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    return tabulation(n, k, arr);
}