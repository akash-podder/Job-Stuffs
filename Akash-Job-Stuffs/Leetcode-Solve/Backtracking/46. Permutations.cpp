class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp_v, map<int, bool> &visited) {
        // Base case: the "nums" size is EQUAL to "temp_v"
        if(nums.size()==temp_v.size()){
            ans.push_back(temp_v);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[nums[i]]==false){
                visited[nums[i]]=true;
                temp_v.push_back(nums[i]);
                
                solve(nums, ans, temp_v, visited);
                
                // After calling "solve" function we just "RESET" the Value of "visited" map and also Remove the "Added" Element
                temp_v.pop_back();
                visited[nums[i]]=false;
            }
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp_v;
        map<int, bool> visited;

        solve(nums, ans, temp_v, visited);

        return ans;
    }
};