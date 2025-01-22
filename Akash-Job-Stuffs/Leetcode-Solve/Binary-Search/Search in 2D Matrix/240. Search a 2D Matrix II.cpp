class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        // observe Only in the "Top-Right" Corner of the Matrix, we can see that, the LEFT Side values are all LESS than "Top-Right" value & DOWN Side all values are Greater than "Top-Right" value. using This Property we will move to Left or Down Direction

        int start_x=0;
        int start_y=col-1;

        while(start_x<row && start_y>=0){
            if(matrix[start_x][start_y]==target){
                return true;
            }
            else if(matrix[start_x][start_y]<target){
                // Move Down
                start_x++;
            }
            else if(matrix[start_x][start_y]>target){
                // Move Left
                start_y--;
            }
        }

        return false;
    }
};