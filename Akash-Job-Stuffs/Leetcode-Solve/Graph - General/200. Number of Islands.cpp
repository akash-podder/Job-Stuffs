class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int &row, int &col, vector<vector<int>>& visited){
        // Base Case:
        if(i<0 || j<0 || i>=row || j>=col){
            return;
        }

        if(grid[i][j]=='1' && visited[i][j]==-1){
            visited[i][j] = 1;

            dfs(grid, i+1, j, row, col, visited); // right side
        
            dfs(grid, i-1, j, row, col, visited); // left side

            dfs(grid, i, j-1, row, col, visited); // up side

            dfs(grid, i, j+1, row, col, visited); // down side
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, -1));

        int coun=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                // if current is "1" & NOT Visited, then we increase our "COUN" variable
                if(grid[i][j]=='1' && visited[i][j]==-1){
                    coun++;
                    dfs(grid, i, j, row, col, visited);
                }
            }
        }

        return coun;
    }
};