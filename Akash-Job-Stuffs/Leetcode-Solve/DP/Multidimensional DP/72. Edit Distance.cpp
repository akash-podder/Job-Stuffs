class Solution {
public:
    int solve(string word1, string word2, int i1, int i2, vector<vector<int>> &cache){
        // BASE Cases
        // "word1" has ended, so we have to add remaining "i2+1" Number of INSERT Operations for making it into "word2" and Vice-Versa
        if(i1==-1){
            return i2+1;
        }
        if(i2==-1){
            return i1+1;
        }

        if(cache[i1][i2]!=-1){
            return cache[i1][i2];
        }

        int coun=0;
        
        // MATCH ---> So we ZERO + Other Operation is Needed, we move Both Pointers
        if(word1[i1]==word2[i2]){
            coun = solve(word1, word2, i1-1, i2-1, cache); 
        }

        // NO MATCH ---> "1" + Other Operation is Needed
        // we take MIN of all possible three Case Operations
        else{
            coun = min(
                    min(
                        1+solve(word1, word2, i1-1, i2, cache), // Inserted char in word1 string & comparing
                        1+solve(word1, word2, i1, i2-1, cache) // Deleted char in word1 string & comparing
                    ),
                    1+solve(word1, word2, i1-1, i2-1, cache) // Replaced char in word1 string & comparing
                );
        }

        return cache[i1][i2] = coun;
    }

    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> cache(len1, vector<int>(len2, -1));

        return solve(word1, word2, len1-1, len2-1, cache);
    }
};