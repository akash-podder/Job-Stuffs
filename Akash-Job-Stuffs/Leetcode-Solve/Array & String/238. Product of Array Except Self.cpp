// User function Template for Java
class Solution {
    public static int[] productExceptSelf(int nums[]) {
        int len = nums.length;
        int[] prefix = new int[len];
        int[] postfix = new int[len];
        
        int[] ans = new int[len];

        // we calculate "prefix_mul" & "postfix_mul" for Each of the Index
        // the Answer would be simply for Each of the Index (i) the ---> (i-1) index's Prefix Mul * (i+1) index's Postfix Mul
        prefix[0] = 1;
        for(int i=1;i<len;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        postfix[len-1] = 1;
        for(int i=len-2;i>=0;i--){
            postfix[i] = postfix[i+1] * nums[i+1];
        }

        for(int i=0;i<len;i++){
            ans[i] = prefix[i] * postfix[i];
        }

        return ans;
    }
}