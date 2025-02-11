class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int row=matrix.size();
            int col=matrix[0].size();
    
            // 1. Transponse the Matrix (take Left Tilted Diagonal and then SWAP the Left Bottom Sided portion to the Upper Right Sided portion), that means think the Diagonal as the MIRROR we just Swap those Both side values
    
            for(int i=0;i<row;i++){
                for(int j=i+1;j<col;j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
    
            // 2. Now just REVERSE Each of the Rows
            // for(int i=0;i<row;i++){
            //     reverse(matrix[i].begin(),matrix[i].end());
            // }
            
            // without Built-in Function
            for(int i=0;i<row;i++){
                for(int j=0;j<col/2;j++){
                    swap(matrix[i][j], matrix[i][col-1-j]); // swaping Each Element of a Particular Row
                }
            }
        }
    };