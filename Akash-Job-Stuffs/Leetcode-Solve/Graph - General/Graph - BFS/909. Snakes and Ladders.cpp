class Solution {
public:
    pair<int, int> getRowCol(int curr, int n){
        int r = (curr - 1) / n;  // 0-based row index
        int c = (curr - 1) % n;  // 0-based column index

        if (r % 2 == 1) {
            c = n - 1 - c;  // Reverse columns for odd rows
        }
        r = n - 1 - r;  // Convert to correct row index from Top to Down
        
        return make_pair(r, c);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> myQueue;
        vector<bool> visited(n*n+1, false);
        
        myQueue.push(1);
        visited[1] = true;

        int coun=0;
        while(!myQueue.empty()) {
            coun++;

            int len = myQueue.size(); // this is to Track UPTO which Element in the Queue belongs to SAME Level

            for(int l=0;l<len;l++){
                int curr = myQueue.front();
                myQueue.pop();
                cout<<curr<<endl;
                for (int i = 1; i <= 6 && curr + i <= n * n; i++) {
                    int newNeighbor=curr+i;
                    
                    // Transform "newNeighbor" to NEW Board Position after Climbing a Ladder or Snake
                    pair<int, int> p = getRowCol(newNeighbor, n);
                    if(board[p.first][p.second]!=-1){
                        // Note that you only take a snake or ladder at most once per dice roll. So, we Transform the newNeighbor Value 1 time... that's why we CAN NOT assign --> visited[newNeighbor]=true... It may be Possible that Current "newNeighbor" Can go to DESITNATION BEFORE Transforming to board[row][col] with "newNeighbor"
                        newNeighbor = board[p.first][p.second];
                    }
                    
                    // this means we have reached to the END
                    if( newNeighbor == (n*n) ){
                        return coun;
                    }

                    // If NOT Visited we Mark the Place as Visited
                    if(visited[newNeighbor]==false){
                        visited[newNeighbor]=true;
                        myQueue.push(newNeighbor);
                    }
                }
            }
        }

        return -1;
    }
};