class Solution {
public:
    int countPrimes(int n) {
        // Sieve of Eratosthenes
        int count=0;
        
        // Case for: n=0 and n=1, cause otherwise I am declaring a "isPrime" vector with Size "n"... if n=0 then isPrime[0] will give Null Pointer Execption
        if(n<=2){
            return 0;
        }

        vector<bool> isPrime(n, 1);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i*i<n; i++) {
            if (isPrime[i]) {
                // Mark multiples of i as not prime
                for (int j = i*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(isPrime[i]==1){
                count++;
            }
        }


        return count;
    }
};