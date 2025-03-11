class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int>& temp_v, int index){

        if(index==nums.size()){
            ans.push_back(temp_v);
            return;
        }

        // we Take the Current "index" Element
        temp_v.push_back(nums[index]);
        solve(nums, ans, temp_v, index+1);
        temp_v.pop_back();

        // we DONT Take the Current "index" Element
        solve(nums, ans, temp_v, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp_v;

        solve(nums, ans, temp_v, 0);

        return ans;
    }
};