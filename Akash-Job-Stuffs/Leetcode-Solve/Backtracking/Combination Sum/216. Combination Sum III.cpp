class Solution {
public:
    void solve(vector<int> &nums, int k, int n, int index, vector<vector<int>> &ans, vector<int> &v){
        // Base Case:
        if(index==nums.size()){
            // if Both the Conditions are fulfilled then we push it to "ans"
            if(n==0 && k==0){
                ans.push_back(v);
            }
            return;
        }

        // TAKE
        if(n>=nums[index]){
            v.push_back(nums[index]);
            solve(nums, k-1, n-nums[index], index+1, ans, v); // as we at MOST Take One Number At Most Once, so we increase the Index Number... as we TOOK the Number so we Decrease "k" to "k-1" & also Decrease "n-nums[index]"
            v.pop_back();
        }


        // NOT TAKE --> we always Not Take
        solve(nums, k, n, index+1, ans, v); // as we DIDN'T TAKE the Number so we DON'T Decrease "k" to "k-1", we just Increase "index+1"

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> v;

        solve(nums, k, n, 0, ans, v);

        return ans;
    }
};