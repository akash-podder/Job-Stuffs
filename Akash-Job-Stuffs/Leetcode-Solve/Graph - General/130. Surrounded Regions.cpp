class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>> &visited, int row, int col, int i, int j){
        if(i<0 || i>=row || j<0 || j>=col){
            return;
        }

        if(board[i][j]=='O' && visited[i][j]==-1){
            visited[i][j] = 1;
        
            dfs(board, visited, row, col, i-1, j); // up
            dfs(board, visited, row, col, i+1, j); // down
            dfs(board, visited, row, col, i, j-1); // left
            dfs(board, visited, row, col, i, j+1); // right
        }
    }

    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, -1));

        // Theory: we just MARK the OUTSIDE 4 BOARDERS (left, right, up, down) and the Connected Areas with "visited=1", Rest of the '0' will be Converted to 'X'

        for(int i=0;i<row;i++){
            // Left Column
            if(board[i][0]=='O'){
                dfs(board, visited, row, col, i, 0);
            }

            // Right Column
            if(board[i][col-1]=='O'){
                dfs(board, visited, row, col, i, col-1);
            }
        }

        for(int j=0;j<col;j++){
            // Top Row
            if(board[0][j]=='O'){
                dfs(board, visited, row, col, 0, j);
            }

            // Bottom Row
            if(board[row-1][j]=='O'){
                dfs(board, visited, row, col, row-1, j);
            }
        }

        // Theory: we just MARK the OUTSIDE 4 BOARDERS (left, right, up, down) and the Connected Areas with "visited=1", Rest of the '0' will be Converted to 'X'
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O' && visited[i][j]==-1){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};