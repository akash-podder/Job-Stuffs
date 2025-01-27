class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& cache){
        if(row==0 && col==0){
            return grid[0][0];
        }

        if(cache[row][col]!=-1){
            return cache[row][col];
        }

        // as we are Traversing from END Point, so we can Traverse the Opposite. That means --> (left & up)
        int left=INT_MAX;
        int up=INT_MAX;

        if(row-1>=0)
            left = grid[row][col] + solve(grid, row-1, col, cache);

        if(col-1>=0)
            up = grid[row][col] + solve(grid, row, col-1, cache);

        return cache[row][col] = min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        // as there is No "Uniformity" we can not apply "Greedy", so we have to Try all Paths (DP)
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> cache(row, vector<int>(col, -1));
        return solve(grid, row-1, col-1, cache); // as we are starting from (m-1, n-1) point
    }
};