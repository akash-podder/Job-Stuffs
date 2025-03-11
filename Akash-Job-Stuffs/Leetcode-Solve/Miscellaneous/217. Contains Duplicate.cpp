class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> Map;

        for(int i=0;i<nums.size();i++){
            // this means, we have seen the Element, so the Array contains Duplicate
            if(Map[nums[i]]>0){
                return true;
            }

            Map[nums[i]]=1;
        }

        return false;
    }
};