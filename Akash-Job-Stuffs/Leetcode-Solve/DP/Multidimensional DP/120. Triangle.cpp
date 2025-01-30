class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& cache){
        // we have reached the BOTTOM
        if(row==triangle.size()-1){
            return triangle[triangle.size()-1][col];
        }

        if(row>triangle.size()-1 || col>triangle[row].size()-1){
            return 0;
        }

        if(cache[row][col]!=-1){
            return cache[row][col];
        }

        // next row's i'th col
        int next_row_i_col = triangle[row][col] + solve(triangle, row+1, col, cache);
        // next row's (i+1)'th col
        int next_row_i_plus_one_col = triangle[row][col] + solve(triangle, row+1, col+1, cache);

        return cache[row][col] = min(next_row_i_col, next_row_i_plus_one_col);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[triangle.size()-1].size(); // we can the "col" size from the "last row"

        vector<vector<int>> cache(row, vector<int>(col, -1));
        //here the "starting point" is Fixed, so we Traverse from Top Point to the Bottom Points
        return solve(triangle, 0, 0, cache);
    }
};