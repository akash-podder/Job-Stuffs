// Method-1: Sort + TWO Pointers (Similar to Binary Search)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;

        // 1. at first we sort
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.size()-1;

        // 2. Approach similar to Binary Search
        while(low<high){
            int sum = nums[low] + nums[high];
            // a) if the SUM is Equal to "k" then we Shrink the Space by Moving Both Pointers in-wards
            if(sum == k){
                ans++;
                low++;
                high--;
            }
            // b) if the SUM is Less than "k" then that means we need BIGGER Number from the Left Side, we move Low Pointer to the Right
            else if(sum<k){
                low++;
            }
            else{
                high--;
            }
        }

        return ans;
    }
};


// Method-2: HashMap
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;

        unordered_map<int, int> Map;

        for(int i=0;i<nums.size();i++){
            // Previously Encountered (k-nums[i]) "element" that's why we increase the Answer and as we are using "k-nums[i]" & "nums[i]" we are Decreasing it
            if(Map[k-nums[i]]>0){
                ans++;
                Map[k-nums[i]]--;
            }
            else{
                Map[nums[i]]++;
            }
        }

        return ans;
    }
};