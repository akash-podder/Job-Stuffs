class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();

        vector<bool> visited(n+1, false);
        stack<int> Stack;
        
        int coun=0;
        
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                coun++;
                Stack.push(i);
                visited[i]=true;

                while(!Stack.empty()){
                    int Top = Stack.top();
                    Stack.pop();

                    for(int j=1;j<=n;j++){
                        // as "isConnected" is 0-based Index
                        if(j!=Top && visited[j]==false && isConnected[Top-1][j-1]==1){
                            Stack.push(j);
                            visited[j]=true;
                        }
                    }
                }
            }
        }

        return coun;
    }
};