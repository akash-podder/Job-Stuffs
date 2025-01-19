class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int k, int index, vector<int> &temp_v) {
        // Base Case: "temp_v" size is EQUAL to "k"
        if(temp_v.size()==k){
            ans.push_back(temp_v);
            return;
        }

        // "index" is Here to TRACK Upto to WHICH Variable we have TRAVERSED, as [1,2] & [2,1] is Considered as SAME, so we will Start Traversing from "index" in the Next Solve Function
        for(int i=index;i<nums.size();i++){
            temp_v.push_back(nums[i]);
            solve(nums, ans, k, i+1, temp_v);
            
            // After calling "solve" function we just Remove the "Added" Element
            temp_v.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp_v;
        
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }

        solve(nums, ans, k, 0, temp_v);

        return ans;      
    }
};