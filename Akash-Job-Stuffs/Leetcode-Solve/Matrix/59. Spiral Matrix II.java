class Solution {
    public int[][] generateMatrix(int n) {
        int up=0, left=0, down=n-1, right=n-1;

        int[][] ans = new int[n][n];

        int count=1;

        // Don't Forget the "Equal" Sign, otherwise the "Middle" Element won't be Filled for "n = ODD Number"
        while(up<=down && left<=right){
            // Top
            for(int i=left; i<=right; i++){
                ans[up][i] = count;
                count++;
            }
            up++;
            
            // Right
            for(int i=up; i<=down; i++){
                ans[i][right] = count;
                count++;
            }
            right--;

            // Bottom
            for(int i=right; i>=left; i--){
                ans[down][i] = count;
                count++;
            }
            down--;

            // Left
            for(int i=down; i>=up; i--){
                ans[i][left] = count;
                count++;
            }
            left++;
        }

        return ans;
    }
}