class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<vector<int>> &ans, vector<int> &v){
        // Base case: if we EXHAUST by Traversing the Whole Array
        if(index==candidates.size()){
            // if "target==0", then we know that the Combination is VALID and we add it to our answer
            if(target==0){
                ans.push_back(v);
            }
            return;
        }

        //Take or Not take theory
        
        // Take ---> Only if "target>=0" after MINUS
        if(target-candidates[index]>=0){
            v.push_back(candidates[index]);
            solve(candidates, index, target-candidates[index], ans, v); // stay in the Same Index
            v.pop_back(); // because as we are Passing by "reference", we have to POP it after we call the "solve" function... THINK, you will understand    
        }
        
        // Not Take --> we always NOT Take, to Traverse
        solve(candidates, index+1, target, ans, v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates, 0, target, ans, v);

        return ans;
    }
};