class Solution {
public:
    bool dfs(int current, map<int, vector<int>> &Map, vector<int> &visited, vector<int> &pathVisited, vector<int> &ans){
        
        visited[current]=1;
        pathVisited[current]=1;
        
        bool flag=true;

        for(int i=0;i<Map[current].size();i++) {
            if(visited[Map[current][i]]==0) {
                flag = flag && dfs(Map[current][i], Map, visited, pathVisited, ans);
            }
            else if(pathVisited[Map[current][i]]==1) {
                return false;
            }
        }

        pathVisited[current]=0;
        ans.push_back(current);
        
        return flag;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> ans;
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        
        bool flag=true;

        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                flag = flag && dfs(i, Map, visited, pathVisited, ans);
            }
        }

        return (flag==true)? ans: vector<int>{};
    }
};