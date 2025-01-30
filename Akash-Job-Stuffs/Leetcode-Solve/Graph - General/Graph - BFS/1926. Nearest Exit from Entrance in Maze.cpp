class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int row=maze.size();
        int col=maze[0].size();
        queue<pair<int, int>> myQueue;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        myQueue.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        
        int ans=0;

        while(!myQueue.empty()){
            int len = myQueue.size(); // This is the Most important line, we use "len" variable to Track from which part of the "Queue" belongs to SAME Level

            ans++; // Increment step count at each BFS level
            
            for(int l=0;l<len;l++){
                pair<int, int> current = myQueue.front();
                myQueue.pop();

                // UP, DOWN, LEFT, RIGHT
                vector<int> dx = {-1, +1, 0, 0};
                vector<int> dy = {0, 0, -1, +1};

                for(int i=0;i<4;i++){
                    int neighbor_x = current.first+dx[i];
                    int neighbor_y = current.second+dy[i];

                    if(neighbor_x>=0 && neighbor_x<row && neighbor_y>=0 && neighbor_y<col){
                        if(maze[neighbor_x][neighbor_y]=='.' && visited[neighbor_x][neighbor_y]==false){
                            if(neighbor_x==0 || neighbor_x==row-1 || neighbor_y==0 || neighbor_y==col-1){
                                return ans;
                            }
                                
                            myQueue.push({neighbor_x, neighbor_y});
                            visited[neighbor_x][neighbor_y] = true;

                            // N.B.
                            // If you are facing TLE you probably made the same mistake as me. Correct Way: When pushing a coordinate to the queue immediately mark it VISITED
                            // Otherwise if we Mark VISITED hashset after popping from queue. If we implement this way we mistakenly add many duplicate coordinates to the queue. which gives TLE... just THINK
                        }
                    }
                }
            }
        }

        return -1; // if No Path has been found
    }
};