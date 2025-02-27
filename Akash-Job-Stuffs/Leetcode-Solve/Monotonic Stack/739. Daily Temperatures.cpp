class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(), 0);

        // we have to Store --> (index, value) in a PAIR
        stack<pair<int,int>> myStack;

        // As the Greater Element can be in Right, so we TRAVERSE in Reverse
        for(int i=temperatures.size()-1; i>=0; i--){

            // Until the "myStack's TOP" is LESS than Current Value we POP the TOP Value
            while(!myStack.empty() && myStack.top().second<=temperatures[i]){
                myStack.pop();
            }

            // if Stack is EMPTY that means there is NO Greater Temperature in the Right
            if(myStack.empty()){
                v[i]=0;
            }

            // else ---> we Store the Difference Between TOP's INDEX & Current INDEX
            else{
                v[i]=(myStack.top().first-i);
            }

            // in the END we STORE the Current Index & Value in STACK
            myStack.push(make_pair(i, temperatures[i]));
        }

        return v;
    }
};