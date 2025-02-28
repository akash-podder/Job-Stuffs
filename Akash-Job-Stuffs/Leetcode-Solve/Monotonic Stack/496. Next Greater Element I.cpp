class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums2.size(), 0);
        stack<int> myStack;
        map<int, int> Map;

        // we Traverse in Reverse order in "Monotonic Stack" Problems
        for(int j=nums2.size()-1; j>=0; j--){
            // until there is a GREATER Element at the TOP, we Keep POPPING
            while(!myStack.empty() && myStack.top()<=nums2[j]){
                myStack.pop();
            }

            if(myStack.empty()){
                v[j] = -1;
            }
            else{
                v[j] = myStack.top();
            }

            // at last we push the Current Element in Stack
            myStack.push(nums2[j]);
        }

        for(int i=0;i<v.size();i++){
            Map[nums2[i]] = v[i];
        }

        vector<int> ans;
        // here, nums1 ---> is like a QUERY vector... here, Queries are Stored & we have to Find the Next Greater Element of the given Query
        for(int i=0;i<nums1.size();i++){
            ans.push_back(Map[nums1[i]]);
        }

        return ans;
    }
};