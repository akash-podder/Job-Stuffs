class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count=0;
        stack<int> myStack;

        unordered_map<int, vector<int>> Map;
        unordered_map<int, set<int>> realMap;

        unordered_map<int, bool> visited;

        for(int i=0; i<connections.size(); i++){
            Map[connections[i][0]].push_back(connections[i][1]);
            Map[connections[i][1]].push_back(connections[i][0]);

            // we just "Reverse" the Connections as "Final Destination" is "0"
            // here, Normal Connection Represents from "1st -> 2nd Element" of the Array
            realMap[connections[i][1]].insert(connections[i][0]);
        }

        myStack.push(0);
        visited[0] = true;

        while(!myStack.empty()){
            int top = myStack.top();
            myStack.pop();                
            
            for(auto item: Map[top]){
                if(visited[item]==false){
                    myStack.push(item);
                    visited[item] = true;
                    
                    // Now, we check if the Connection is present in "RealConnection"
                    // Direction is Opposite, so we increase our "Count"
                    if(realMap[top].find(item)==realMap[top].end()){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};