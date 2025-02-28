class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();

        vector<int> ans(len, 0);
        stack<int> myStack;
        
        // Loop TWICE the Size of the Array... As, the Array is Circular
        for(int i=(2*len)-1; i>=0; i--){
            while(!myStack.empty() && myStack.top()<=nums[i%len]){
                myStack.pop();
            }

            if(myStack.empty()){
                ans[i%len] = -1;
            }
            else{
                ans[i%len] = myStack.top();
            }

            myStack.push(nums[i%len]);
        }

        return ans;
    }
};