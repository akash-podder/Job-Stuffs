// SOLVE-1
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



// SOLVE-2
class Solution {
public:
    void solve(vector<int> &nums, int k, int index, vector<vector<int>> &ans, vector<int> &v){
        if(index==nums.size()){
            if(k==0){
                ans.push_back(v);
            }
            return;
        }

        // Take
        if(k>0){
            v.push_back(nums[index]);
            solve(nums, k-1, index+1, ans, v); // we Take the current element & move to the Next Index & REDUCE "k" with "-1"
            v.pop_back();
        }

        // NOT Take (we Always Not Take)
        solve(nums, k, index+1, ans, v); // we Only Move to the Next Index

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }

        solve(nums, k, 0, ans, v);

        return ans;
    }
};