class Solution {
public:
    int binary_search(vector<int>& stones, int element){
        int len = stones.size();
        int low = 0;
        int high = len-1;

        while(low<=high){
            int mid = low + ((high-low)/2);
            if(stones[mid]==element){
                return mid;
            }
            else if(stones[mid]<element){
                low = mid+1;
            }
            else if(stones[mid]>element){
                high = mid-1;
            }

        }

        return -1;
    }

    bool solve(vector<int>& stones, int index, int k, vector<vector<int>> &cache) {
        
        if(cache[index][k]!=-1){
            return cache[index][k];
        }

        // Base Case: this means we have reached to the END, so return TRUE
        if(index==stones.size()-1){
            return cache[index][k] = true;
        }
        
        int new_element = stones[index] + k;
        // we Finding the NEXT INDEX, as the array is in ascending order so, we use Binary Search
        int next_index = binary_search(stones, new_element); 

        if(next_index!=-1) {
            // now we Try all Combinations for "k-1, k & k+1" units
            
            if(solve(stones, next_index, k, cache) == true || solve(stones, next_index, k+1, cache) == true){
                return cache[index][k] = true;
            }

            // for "k-1" we have to check if it's greater than "1", otherwise if k-1=0 then, we STUCK in INIFINTE Loop
            if((k-1)>1){
                if(solve(stones, next_index, k-1, cache)==true){
                    return cache[index][k] = true;
                }
            }
        }

        // if "next_index" is "-1" OR, the Recursive Function Returned "false" we return "false"
        return cache[index][k] = false;
    }

    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> cache(len, vector<int>(len, -1));

        // as in first jump we start from 0 index & k=1
        return solve(stones, 0, 1, cache);
    }
};