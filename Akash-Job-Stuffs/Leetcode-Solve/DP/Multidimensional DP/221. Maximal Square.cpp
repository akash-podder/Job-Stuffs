class Solution {
public:
    int solve(vector<vector<char>>& matrix, int &row, int &col, int i, int j, vector<vector<int>> &cache){
        // Base Case: the Cells which are in the Last Row & Last Column we just Check if they are "1", if Yes we Return 1... Because the Maximum Square they can have will be Equal to "1"
        if(i==row-1 || j==col-1){
            if(matrix[i][j]=='1'){
                return 1;
            }
            else{
                return 0;
            }
        }

        // cache
        if(cache[i][j]!=-1){
            return cache[i][j];
        }
        
        int count=0;

        if(matrix[i][j]=='1'){
            // we take Minimum, because among all the THREE Sides, we want to FORM a "SQUARE", if ALL the Side Doesn't Have EQUAL Number of 1, that Means we can not form a SQUARE
            
            count = 1 + min(
                            min(solve(matrix, row, col, i, j+1, cache), // right
                                solve(matrix, row, col, i+1, j, cache) //down
                            ),
                        solve(matrix, row, col, i+1, j+1, cache)); // diagonal
        }

        return cache[i][j] = count;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;

        int row=matrix.size();
        int col=matrix[0].size();

        vector<vector<int>> cache(row, vector<int>(col, -1));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,solve(matrix, row, col, i, j, cache));
            }
        }

        return ans*ans;
    }
};