class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        int row = grid.size();
        int col = grid[0].size();

        int count=0;
        
        // as, grid[i][j] == 1 --> So, we start Counting from "1"... As, this will be used in our Return value
        if(grid[i][j]==1){
            count=1;
        }

        visited[i][j] = true;
        
        // Right
        if(i+1<row){
            if(grid[i+1][j] && visited[i+1][j]==false){
                count += dfs(i+1, j, grid, visited);
            }
        }

        // Left
        if(i-1>=0){
            if(grid[i-1][j] && visited[i-1][j]==false){
                count += dfs(i-1, j, grid, visited);
            }
        }

        // Up
        if(j+1<col){
            if(grid[i][j+1] && visited[i][j+1]==false){
                count += dfs(i, j+1, grid, visited);
            }
        }

        // Down
        if(j-1>=0){
            if(grid[i][j-1] && visited[i][j-1]==false){
                count += dfs(i, j-1, grid, visited);
            }
        }

        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int ans = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j]==false && grid[i][j]==1){
                    ans = max(ans, dfs(i, j, grid, visited));
                }
            }
        }

        return ans;
    }
};