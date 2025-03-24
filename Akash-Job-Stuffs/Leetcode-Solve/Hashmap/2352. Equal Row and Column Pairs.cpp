// Brute Force: 0(n^3)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int row=grid.size();
        int col=grid[0].size();

        int ans=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                bool isEqualRowCol=true;

                for(int x=0;x<col;x++){
                    // the (i,j) Position is Fixed... Now, we Traverse in Both the i'th Row & j'th Column Position... And to Traverse we use "x"
                    if(grid[i][x]!=grid[x][j]){
                        isEqualRowCol=false;
                        break;
                    }
                }

                if(isEqualRowCol) ans++;
            }
        }

        return ans;
    }
};


// Optimal Approach
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

    // Since we need to compare rows and columns, an efficient way to do this is to store all rows in a hash map and then check how many columns match the stored rows.

        int row=grid.size();
        int col=grid[0].size();

        // Store the rows in a hash map:
        //     We iterate over all rows in the grid and store their frequency in a hash map
        //     Why? In order to check if any column matches a stored row.

        int ans=0;
        
        map<vector<int>, int> Map;

        for(int i=0;i<row;i++){
            Map[grid[i]]++;    
        }
        
        // Iterate over columns and check for matches:

        // We extract each column as a vector and check if it exists in our hash map.
        // If any, we add the frequency of that row to our count.

        for(int j=0;j<col;j++){
            vector<int> currentCol;
            for(int i=0;i<row;i++){
                currentCol.push_back(grid[i][j]);
            }

            // this means, if "currentCol" matches to any Previously Stored "rows", that means we Add the "Frequency" in our Answer
            ans+=Map[currentCol];
        }

        return ans;
    }
};