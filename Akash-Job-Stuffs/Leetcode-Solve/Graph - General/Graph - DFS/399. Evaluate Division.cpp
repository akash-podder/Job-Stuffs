class Solution {
public:
    double dfs(map<string , vector<pair<string, double>>> &Map, string x, string y, map<string, bool> &visited){
        // Base Condition, if the Traversing Node "x" becomes "y" that means we have found the Equation
        if(x==y){
            return 1;
        }

        visited[x] = true;

        double ans=-1;

        for(auto it: Map[x]){
            if(visited[it.first]==false){
                // if dfs()==-1 --> that means we can not have any "Equation" which can make the "query"
                double dfs_result = dfs(Map, it.first, y, visited);
                
                if(dfs_result!=-1){
                    // we found the Equation, so we Multiply it with the value which is stored in "it.second"
                    ans=(it.second)*dfs_result;
                    break;
                }
            }
        }

        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;

        map<string , vector<pair<string, double>>> Map;

        // for each Equation (a/b) = 5, we store (a->b=5) & (b->a=1/5) in the Map Graph

        for(int i=0;i<equations.size();i++){
            if(Map.find(equations[i][0])!=Map.end()){ // we Found
                Map[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            }
            else{ // Not Found
                vector<pair<string, double>> v;
                v.push_back(make_pair(equations[i][1], values[i]));
                Map[equations[i][0]] = v;
            }

            if(Map.find(equations[i][1])!=Map.end()){ // we Found
                Map[equations[i][1]].push_back(make_pair(equations[i][0], double(1/values[i])));
            }
            else{ // Not Found
                vector<pair<string, double>> v;
                v.push_back(make_pair(equations[i][0], double(1/values[i])));
                Map[equations[i][1]] = v;
            }
        }

        for(int i=0;i<queries.size();i++){
            // Not Found
            if(Map.find(queries[i][0])==Map.end() || Map.find(queries[i][1])==Map.end()){
                ans.push_back(-1);
            }
            else{ // Found
                map<string, bool> visited;
                ans.push_back(dfs(Map, queries[i][0], queries[i][1], visited));
            }
        }

        return ans;
    }
};
