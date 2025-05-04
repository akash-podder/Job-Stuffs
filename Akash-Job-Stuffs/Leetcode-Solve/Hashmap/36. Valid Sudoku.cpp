class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<9;i++){
            map<char, int> rowMap;
            map<char, int> colMap;
            map<char, int> boxMap;

            // Traversing Each Row
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    // We found same value in the SAME Row, So, return --> false
                    if(rowMap[board[i][j]]==1){
                        return false;
                    }
                    rowMap[board[i][j]]=1;
                }
            }

            // Traversing Each Column
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    // We found same value in the SAME Column, So, return --> false
                    if(colMap[board[j][i]]==1){
                        return false;
                    }
                    colMap[board[j][i]]=1;
                }
            }

            // Traversing Each Box
            for(int j=0;j<9;j++){

                // Did immense Calculation to Traverse & get the Offset for Row & Col 
                int offset_i = (i/3)*3;
                int offset_j = (i%3)*3;

                int curr_i = offset_i + (j/3); 
                int curr_j = offset_j + (j%3);
                
                // cout<<"["<<curr_i<<","<<curr_j<<"] ";

                if(board[curr_i][curr_j]!='.'){
                    // We found same value in the SAME Box, So, return --> false
                    if(boxMap[board[curr_i][curr_j]]==1){
                        return false;
                    }
                    boxMap[board[curr_i][curr_j]]=1;
                }
            }
            
            // cout<<endl;
        }

        // that means, all the Values in row, column & box are Unique. So, it is a Valid Sudoku
        return true;
    }
};