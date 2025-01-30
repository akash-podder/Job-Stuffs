class Solution {
public:
    void bfs(int start_course, int numCourses, map<int, vector<int>>& Map, vector<vector<bool>>& isReachable){
        vector<bool> visited(numCourses, false);

        queue<int> myQueue;
        myQueue.push(start_course);
        
        while(!myQueue.empty()){
            int len = myQueue.size();

            for(int i=0;i<len;i++){
                int current = myQueue.front();
                myQueue.pop();
                
                // this means we "current" is a child Node of "start_course" & we can go from "start_course" to "current"
                isReachable[start_course][current] = true;
                visited[current] = true;
        
                for (auto x : Map[current]) {
                    if(visited[x]==false){
                        myQueue.push(x);
                        isReachable[start_course][x]=true;
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Imagine if the courses are nodes of a graph. We need to build an array isReachable[i][j].
        // Start a bfs from each course i and assign for each course j you visit isReachable[i][j] = True.
        // Answer the queries from the isReachable array.

        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));

        map<int, vector<int>> Map;


        // at first we create the "Map" for representing the Whole Graph
        for(int i=0;i<prerequisites.size();i++){
            if(Map.find(prerequisites[i][0])!=Map.end()){
                Map[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            else{
                vector<int> temp{prerequisites[i][1]};
                Map[prerequisites[i][0]] = temp;
            }
        }
        
        for(int current=0; current<numCourses; current++){
            bfs(current, numCourses, Map, isReachable);
        }
        
        vector<bool> ans;

        for(int i=0;i<queries.size();i++){
            if(isReachable[queries[i][0]][queries[i][1]]==true){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};