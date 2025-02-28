class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int len=nums.size();

        vector<int> ans(len, 0);
        stack<int> myStack;

        // for Monotonic Stack we always TRAVERSE in REVERSE       
        for(int i=len-1; i>=0; i--){

            // Until the TOP is Greater than CURRENT_ELEMENT we keep POPPING
            while(!myStack.empty() && myStack.top()<=nums[i]){
                myStack.pop();
            }

            if(myStack.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = myStack.top();
            }

            // *** we Always PUSH the CURRENT ELEMENT in Stack
            myStack.push(nums[i]);
        }

        return ans;
    }
};