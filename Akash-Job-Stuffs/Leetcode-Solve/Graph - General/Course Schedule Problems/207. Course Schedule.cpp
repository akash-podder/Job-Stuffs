class Solution {
public:
    bool dfs(int current, map<int, vector<int>> &Map, vector<int> &visited, vector<int> &pathVisited){
        bool ans=true;

        visited[current]=1;
        pathVisited[current]=1;

        for(int j=0;j<Map[current].size();j++) {
            if(visited[Map[current][j]]==0) {
                // all the Child Node Must Not contain any Cycle... That's why "&& (AND) Operation"
                ans = ans && dfs(Map[current][j], Map, visited, pathVisited);
            }
            
            // if we Encounter a "pathVisited" State (==1) That means there is a Cycle
            else if(pathVisited[Map[current][j]]==1) {
                return false; // cycle Detected
            }
        }

        pathVisited[current]=0;
        
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> Map;

        for(int i=0;i<prerequisites.size();i++){
            if(Map.find(prerequisites[i][0])!=Map.end()){
                Map[prerequisites[i][0]].push_back(prerequisites[i][1]);
            } 
            else{
                vector<int> temp{prerequisites[i][1]};
                Map[prerequisites[i][0]] = temp;
            }
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i, Map, visited, pathVisited)==false){
                    return false;
                }
            }
        }

        return true;
    }
};