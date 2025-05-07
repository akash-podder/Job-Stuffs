class Solution {
public:
    bool isPair(vector<int>& pair1, vector<int>& pair2){
        if(pair1[1]<pair2[0]){
            return true;
        }

        return false;
    }
    
    int solve(vector<vector<int>>& pairs, int index, vector<int> &cache){
        // Base Case
        if(index==pairs.size()){
            return 0;
        }

        if(cache[index]!=-1){
            return cache[index];
        }

        // Take
        int take=1; // as we are Taking the "Current Pair", that's why we start "take=1"
        int maxInLoop=0;
        for(int i=index+1; i<pairs.size(); i++){
            if(isPair(pairs[index], pairs[i])){
                // we take Maximum out of all the combinations
                maxInLoop = max(maxInLoop, solve(pairs, i, cache));
            }
        }

        take = 1 + maxInLoop;

        // Not Take
        int notTake=0;
        notTake = solve(pairs, index+1, cache);


        // we Return the Maximum of Taking the Current Index in the Chain & NOT taking the Current Index in the Chain
        return cache[index] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> cache(pairs.size(), -1);

        // as Pairs can be in Any Order, we have to SORT them first
        sort(pairs.begin(), pairs.end());

        return solve(pairs, 0, cache);
    }
};