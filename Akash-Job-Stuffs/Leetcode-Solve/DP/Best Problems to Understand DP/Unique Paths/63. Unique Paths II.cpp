class Solution {
public:
    int solve_tabulation(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp){

        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                // there is an Obstacle & there is No path, so we Return 0
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                // if there is No Obstacle in (0,0) we return 1
                else if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    int left=0, up=0;
                    if(i-1>=0) left = dp[i-1][j];
                    if(j-1>=0) up = dp[i][j-1];

                    dp[i][j] = left+up;
                }      
            }
        }

        return dp[row][col];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        return solve_tabulation(obstacleGrid, row-1, col-1, dp);
    }
};