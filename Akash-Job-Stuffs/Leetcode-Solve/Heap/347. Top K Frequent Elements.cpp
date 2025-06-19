class Solution {
public:
    // using "Bucket Sort" to Solve the Problem
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqMap;

        // Define map with descending key order
        map<int, vector<int>, greater<int>> Bucket;

        for(int i=0;i<nums.size();i++){
            freqMap[nums[i]]++; // At first we are Counting Frequency
        }

        // Each of the Frequency is a Bucket... and then we map each Number to it's Frequency
        // here, "key" = Frequency, "value" = nums in Array
        for(auto x: freqMap){
            Bucket[x.second].push_back(x.first);
        }

        vector<int> ans;
        // we Traverse each of the "Frequency Bucket" to get "k" Most Frequent Element
        for(auto x: Bucket){
            vector<int> v = x.second;
            for(int i=0; i<v.size(); i++){
                if(k==0){
                    break;
                }
                ans.push_back(v[i]);
                k--;
            }
        }

        return ans;
    }
};