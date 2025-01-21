class Solution {
public:
    bool isSafe(vector<string> &board, int &n, int &row, int &col){
        int i=row;
        int j=col;

        // "LEFT" Direction
        while(j>=0) {
            if(board[row][j]=='Q'){
                return false;
            }
            
            j--;
        }

        // "DIAGONAL UP+LEFT" Direction
        i=row; // Re-initializing (i, j)
        j=col;
        while(i>=0 && j>=0) {
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }

        // "DIAGONAL DOWN-LEFT" Direction
        i=row; // Re-initializing (i, j)
        j=col;
        while(i<n && j>=0) {
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void solve(vector<vector<string>> &ans, int &n, vector<string> &board, int col){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++) {
            // as we are putting Queens in Column from "left to right", so No Need to check if it's SAFE to the RIGHT SIDE Fields
            if(isSafe(board, n, row, col)){
                board[row][col] = 'Q';
                solve(ans, n, board, col+1);
                board[row][col] = '.'; // this is called "Backtracking", after we found the Answer we Simply just Keep the "board" as it was               
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        // Return all the BOARD with the N-Queen Solve
        
        vector<vector<string>> ans;
        vector<string> board;

        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=".";
            }
            board.push_back(temp);
        }

        solve(ans, n, board, 0);

        return ans;
    }
};