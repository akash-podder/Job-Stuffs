class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        stack<int> Stack;

        Stack.push(0);

        while(!Stack.empty()){
            int Top = Stack.top();
            Stack.pop();
            visited[Top] = true;

            // we TRAVERSE All the Child Node of "Top"
            for(int i=0;i<rooms[Top].size();i++){
                if(visited[rooms[Top][i]]==false){
                    Stack.push(rooms[Top][i]);
                }
            }
        }

        // Check if EVERY Room is Visited or NOT
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }

        return true;
    }
};