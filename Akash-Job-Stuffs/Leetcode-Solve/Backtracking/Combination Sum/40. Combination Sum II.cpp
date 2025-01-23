class Solution {
public:
    void solve(vector<int>& candidates, int target, int current_index, vector<vector<int>> &ans, vector<int> &v) {
        // Base Case
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=current_index;i<candidates.size();i++){
            if(i>current_index && candidates[i]==candidates[i-1]) continue; // as the Array is SORTED, we will TAKE Only 1 Element in 1st LEVEL (Recursion Tree's Level), that means, at first when "current_index=0", at the 0th index Level we will Take Only one "2" (when there are Multiple 2's in the Array). while traversing in the 1st LEVEL, if there are Other 2's we will just IGNORE them. then, on th 2nd LEVEL we can again choose 2 if we want
            
            if(candidates[i]<=target){
                v.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i+1, ans, v); // we Take & Move 1 Index Ahead

                v.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        // at first we SORT the Entire "candidates" array, so that SAME Elements will be Side by Side
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, ans, v);

        return ans;
    }
};