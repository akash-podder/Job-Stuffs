class Solution {
public:
    const int MOD = 1e9 + 7; // Define MOD
    
    int solve(vector<int>& arr, int index, int parity, vector<vector<int>> &cache) {
        // Base Case
        if(index==arr.size()){
            return 0;
        }

        if(cache[index][parity]!=-1){
            return cache[index][parity];
        }

        int count=0;
        
        int current_parity = parity;
        int new_parity = (parity+arr[index]) % 2;

        // ODD
        if(new_parity==1){
            // as it is ODD, we PLUS 1 with our Answer
            count = (1 + solve(arr, index+1, new_parity, cache))%MOD;
        }

        // EVEN
        else{
            // as it is EVEN, we ADD ZERO to our Answer
            count = (0 + solve(arr, index+1, new_parity, cache))%MOD;
        }

        return cache[index][current_parity] = count;
    }

    int numOfSubarrays(vector<int>& arr) {
        //  "sum" parameter can take large values, leading to excessive state space in the 2D dp table & giving TLE...Instead of tracking the absolute sum, let's focus only on whether the sum is odd or even—which limits our state space to just two values (0 for even, 1 for odd)

        // Parity = 0 => Even
        // Parity = 1 => Odd
        vector<vector<int>> cache(arr.size(), vector<int>(2, -1));

        int count=0;
        
        for(int i=0;i<arr.size();i++){
            count=(count+solve(arr, i, 0, cache))%MOD; // Start with sum = 0 (even)
        }

        return count;
    }
};



//-------------------- solution with SUM & get TLE-------------------
class Solution {
public:
    int solve(vector<int>& arr, int index, int sum, map<pair<int, int>, int> &cache) {
        // Base Case
        if(index==arr.size()){
            return 0;
        }

        if(cache.find(make_pair(index,sum))!=cache.end()){
            return cache[make_pair(index, sum)];
        }

        int count=0;
        
        int new_sum=sum+arr[index];

        // ODD
        if(new_sum%2==1){
            // as it is ODD, we PLUS 1 with our Answer
            count = 1 + solve(arr, index+1, new_sum, cache);
        }

        // EVEN
        else{
            // as it is EVEN, we Don't ADD anything to our Answer
            count = 0 + solve(arr, index+1, new_sum, cache);
        }

        return cache[make_pair(index, sum)] = count;
    }

    int numOfSubarrays(vector<int>& arr) {
        map<pair<int, int>, int> cache;

        int count=0;
        
        for(int i=0;i<arr.size();i++){
            count+=solve(arr, i, 0, cache);
        }

        return count;
    }
};