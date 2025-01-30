class Solution {
public:
    int uniquePaths(int m, int n) {
        // initialized everything with "-1"
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return solve(m-1, n-1, cache);
    }

    int solve(int m, int n, vector<vector<int>>& cache){
        // this means, we have Reached the (0, 0) point, thats why we return "1"
        if(m==0 && n==0){
            return 1;
        }

        // this means, we couldn't Reach (0, 0) point so, we return "0"
        if(m<0 || n<0){
            return 0;
        }

        // check if cache exists
        if(cache[m][n]!=-1){
            return cache[m][n];
        }

        int left=0;
        int up=0;
        
        left=solve(m-1, n, cache);
        up=solve(m, n-1, cache);

        // updating the Cache
        return cache[m][n] = left+up;
    }
};