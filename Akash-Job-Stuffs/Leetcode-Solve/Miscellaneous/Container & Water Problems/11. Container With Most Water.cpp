class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0; // Left Pointer
        int right=height.size()-1; // Right Pointer

        int ans=0;

        // *** We have to Identify which side has "LESS" value as we will be Moving Towards that Direction, because the AREA will have the Height which has LESS value

        while(left<right){
            int area=0;

            // Left Pointer has LESS Value
            if(height[left]<height[right]){
                area = height[left]*(right-left); // as "Left" Pointer Value is LESS, so the AREA will be the Height of "left"
                ans=max(ans, area);
                left++;
            }

            // Right Pointer has LESS Value
            else{
                area = height[right]*(right-left);
                ans=max(ans, area);
                right--;
            }
        }

        return ans;
    }
};