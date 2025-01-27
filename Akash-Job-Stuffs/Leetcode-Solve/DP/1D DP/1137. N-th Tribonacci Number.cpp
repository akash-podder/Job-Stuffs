// Solve - 1
class Solution {
public:
    vector<int> v;
    // as the Constraint says Highest "n"=38
    Solution() : v(38, -1) {}  // Initialize the vector in the constructor

    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }

        // Recursive Solution+Memoization
        if(v[n]==-1){
            v[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        }

        return v[n];
    }
};



// =============================================

// Solve - 2
class Solution {
public:
    int tribonacci(int n) {
        // if we use "Recursion", then --> TLE
        // As such, we have to Store the values in Array
        vector<int> v(38,0); // as, 0 <= n <= 37
        v[0]=0;
        v[1]=1;
        v[2]=1;
        
        for(int i=3;i<n+1;i++){
            v[i] = v[i-1]+v[i-2]+v[i-3];
        }

        return v[n];
    }
};