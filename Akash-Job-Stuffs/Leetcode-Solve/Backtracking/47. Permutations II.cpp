class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> &v, vector<bool> &visited) {
        
        // Base case: the "nums" size is EQUAL to "v", then we add it to answer
        if(v.size()==nums.size()){
            ans.push_back(v);
        }

        map<int, bool> Map; // this is to TRACK at Each Level if any "SAME NUMBER" can not OCCUPY SAME "i'th" index position

        for(int i=0;i<nums.size();i++){
            if(visited[i]==false && Map[nums[i]]==false){
                Map[nums[i]]=true;
                visited[i]=true;
                v.push_back(nums[i]);

                solve(nums, ans, v, visited);

                visited[i]=false;
                v.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        
        solve(nums, ans, v, visited);

        return ans;
    }
};