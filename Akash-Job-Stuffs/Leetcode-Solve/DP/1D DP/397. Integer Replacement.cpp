class Solution {
public:
    long long int solve(long long int n, map<long long int, long long int> &cache){
        // Base Case
        if(n==1){
            return cache[n] = 0;
        }

        if(cache[n]){
            return cache[n];
        }

        long long int ans=0;

        // "n" is EVEN
        if(n%2==0){
            ans = 1 + solve(n/2, cache);
        }

        // "n" is ODD
        else{
            long long int minusOne=0, plusOne=0;
            
            // (n-1) case
            if(n>1){
                minusOne = 1 + solve(n-1, cache);
            }

            // (n+1) case
            plusOne = 1 + solve(n+1, cache);

            // we take the Minimum Between this TWO Scenerios
            ans = min(minusOne, plusOne);
        }

        return cache[n] = ans;
    }

    int integerReplacement(int n) {
        // we are taking "long long" for this case --> n = 2147483647
        map<long long int, long long int> cache;

        return solve(n, cache);
    }
};