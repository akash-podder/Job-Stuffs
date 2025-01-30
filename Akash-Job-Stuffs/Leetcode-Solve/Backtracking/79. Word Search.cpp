class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int index, int row, int col){
        // Base Case-1
        if(index==word.size()){
            return true;
        }
        // Base Case-2
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()){
            return false;
        }

        bool ans=false;

        if(board[row][col]==word[index] && visited[row][col]==false){
            visited[row][col]=true;

            ans = ans || solve(board, word, visited, index+1, row-1, col); // Left
            ans = ans || solve(board, word, visited, index+1, row+1, col); // Right
            ans = ans || solve(board, word, visited, index+1, row, col-1); // Up
            ans = ans || solve(board, word, visited, index+1, row, col+1); // Down

            visited[row][col]=false; // after Recusrion is Done, we just Simply mark is UNVISITED as such Next iteration we can get it as "false"... this is called Backtracking
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        //The problem can be solved by traversing the grid and performing a depth-first search (DFS) for each possible starting position. At each cell, we check if the current character matches the corresponding character of the word. If it does, we explore all four directions (up, down, left, right) recursively until we find the complete word or exhaust all possibilities.

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board, word, visited, 0, i, j)==true){
                    return true;
                }
            }
        }

        return false;
    }
};