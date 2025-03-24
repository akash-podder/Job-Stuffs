class Solution {
public:
    vector<pair<int,int>> getAdjacentFreshOrange(int x, int y, vector<vector<int>>& grid, map<pair<int, int>, bool> visited){
        
        int row=grid.size();
        int col=grid[0].size();

        vector<pair<int,int>> adjacentList;

        if(x+1<row && grid[x+1][y]==1) adjacentList.push_back({x+1, y});

        if(x-1>=0 && grid[x-1][y]==1) adjacentList.push_back({x-1, y});

        if(y+1<col && grid[x][y+1]==1) adjacentList.push_back({x, y+1});

        if(y-1>=0 && grid[x][y-1]==1) adjacentList.push_back({x, y-1});
        
        return adjacentList;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int row=grid.size();
        int col=grid[0].size();

        int fresh=0;
        vector<pair<int, int>> rotten;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    rotten.push_back(make_pair(i,j));
                }
            }
        }

        if(fresh==0){
            return 0;
        }

        queue<pair<int, int>> q;
        map<pair<int, int>, bool> visited;
        
        // initially Adding the "First" Level (x,y) Position to "Queue" 
        for(int i=0; i<rotten.size();i++){
            q.push(rotten[i]);
            visited[rotten[i]]=true;
        }

        int level=0;

        while(!q.empty()){
            int len = q.size();

            bool rotted = false; // Track if at least one orange rotted in this step

            for(int l=0;l<len;l++){
                pair<int, int> p = q.front();
                q.pop();

                int x=p.first;
                int y=p.second;

                vector<pair<int, int>> adjacentList = getAdjacentFreshOrange(x, y, grid, visited);

                for(int i=0;i<adjacentList.size();i++){
                    // if it's Not Rotted, then Rot it
                    if(visited[adjacentList[i]]==false){
                        fresh--;
                        visited[adjacentList[i]]=true;
                        q.push(adjacentList[i]);
                        
                        // as Something is Rotted at this Level, so we make rotted=true
                        rotted=true;
                    }
                }
            }

            if(rotted==true) level++; // Only increase time if something rotted... otherwise if we increase "level" at each level, it will Give Wrong Answer, because when are at the "EDGE" of the Grid, this Node will Not have Anyone to ROT, but we are inceasing the Level, As such to avoid this we add this Condition
        }

        
        // If any Fresh Orange is Left we Return -1 otherwise the Answer is "level"
        return fresh>0? -1 : level;
    }
};