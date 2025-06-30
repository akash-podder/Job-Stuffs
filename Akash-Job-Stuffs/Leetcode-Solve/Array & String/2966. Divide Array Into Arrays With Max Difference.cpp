class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i=i+3){
            // The difference between any two elements in one array is less than or equal to k
            if((nums[i+1]-nums[i]>k) || (nums[i+2]-nums[i+1]>k) || (nums[i+2]-nums[i]>k)) {
                // Returning "Empty" Array
                return vector<vector<int>>();
            }
            else{
                vector<int> temp {nums[i], nums[i+1], nums[i+2]};
                ans.push_back(temp);
            }
        }

        return ans;
    }
};