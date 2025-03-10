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
        // we Skip UNTIL we get DIFFERENT Element than the Current Element
        if(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        solve(nums, ans, temp_v, index+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp_v;

        // we have to SORT to keep Track if it's Duplicate Element OR Not
        sort(nums.begin(), nums.end());

        solve(nums, ans, temp_v, 0);

        return ans;
    }
};