class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        // this is to Keep TRACK which row & col should be ZERO
        vector<int> row_zero(row, -1);
        vector<int> col_zero(col, -1);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    row_zero[i]=0; // we are STORING which row & col should be ALL ZERO
                    col_zero[j]=0;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(row_zero[i]==0 || col_zero[j]==0){ // if Either the value is ZERO that means that Particular CELL Should Be ZERO
                    matrix[i][j]=0;
                }
            }
        }
    }
};