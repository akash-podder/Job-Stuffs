class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int>& v, int index){

        if(index==nums.size()){
            ans.push_back(v);
            return;
        }

        // we Take the Current "index" Element
        v.push_back(nums[index]);
        solve(nums, ans, v, index+1);
        v.pop_back();

        // we DONT Take the Current "index" Element
        solve(nums, ans, v, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(nums, ans, v, 0);

        return ans;
    }
};