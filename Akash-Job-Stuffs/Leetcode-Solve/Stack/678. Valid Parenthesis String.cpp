class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParenthesisStack;
        stack<int> starStack;

        // Edge Case: a '*' that appears before a '(' cannot be used to match a closing ')' that comes before that '('
        // As such, we use Two Stacks
        // 1. To store indices of '('
        // 2. To store indices of '*'

        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                leftParenthesisStack.push(i);
            }
            else if(s[i]=='*'){
                starStack.push(i);
            }
            else{
                // first check if any "(" is available
                if(!leftParenthesisStack.empty()){
                    leftParenthesisStack.pop();
                }
                // second check if any "*" is available
                else if(!starStack.empty()){
                    starStack.pop();
                }
                // else return false
                else{
                    return false;
                }
            }
        }

        // Edge Case: a '*' that appears before a '(' cannot be used to match a closing ')' that comes before that '('
        while(!leftParenthesisStack.empty() && !starStack.empty()){
            // "(" is on the RIGHT Side of the "*", as such it can't be valid
            if(leftParenthesisStack.top()>starStack.top()){
                return false;
            }
            // we POP from Both of the Stack
            else{
                leftParenthesisStack.pop();
                starStack.pop();
            }
        }

        // Now, we check if the Main "(" Stack is Empty or NOT
        if(leftParenthesisStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};