class Solution {
public:
    const int MOD = 1000000007;

    int solve(string &s, int index, vector<int> &cache) {
        if (index == s.size()) {
            return 1;
        }

        if (cache[index] != -1) {
            return cache[index];
        }

        long long count = 0;

        // checking if the First Character is '0' or NOT, if '0' we Ommit it
        if (s[index] >= '1' && s[index] <= '9') {
             // *** Think it like TAKE or NOT TAKE ***
            // But here is 2 TAKE Scenerios

            // At Every Index we can Decode in 2-ways...
            // 1st way ---> We Take the Current Char
            // 2nd way ---> We can ONLY TAKE if: COMBINE with the Next Character if these Two characters Form Less than 26


            // Take 1 digit
            count = (count + solve(s, index + 1, cache)) % MOD;

            // Check for 2-digit decode
            if (index + 1 < s.size()) {
                if (s[index] == '1') {
                    if (s[index + 1] == '*') {
                        count = (count + (9LL * solve(s, index + 2, cache)) % MOD) % MOD;
                    }
                    else {
                        count = (count + solve(s, index + 2, cache)) % MOD;
                    }
                }
                else if (s[index] == '2') {
                    if (s[index + 1] == '*') {
                        count = (count + (6LL * solve(s, index + 2, cache)) % MOD) % MOD;
                    }
                    else if (s[index + 1] >= '0' && s[index + 1] <= '6') {
                        count = (count + solve(s, index + 2, cache)) % MOD;
                    }
                }
            }
        }

        // the First Character is '*'
        else if (s[index] == '*') {
            // 1-digit decode: '*' → '1' to '9'
            count = (count + (9LL * solve(s, index + 1, cache)) % MOD) % MOD;

            if (index + 1 < s.size()) {
                if (s[index + 1] == '*') { // '**' → '11' to '19' and '21' to '26'
                    count = (count + (15LL * solve(s, index + 2, cache)) % MOD) % MOD;
                }
                
                else if (s[index + 1] >= '0' && s[index + 1] <= '6') { // '*x' where x ∈ ['0'-'6'] → '1x' and '2x'
                    count = (count + (2LL * solve(s, index + 2, cache)) % MOD) % MOD;
                }
                
                else if (s[index + 1] >= '7' && s[index + 1] <= '9') { // '*x' where x ∈ ['7'-'9'] → only '1x'
                    count = (count + solve(s, index + 2, cache)) % MOD;
                }
            }
        }

        return cache[index] = count;
    }

    int numDecodings(string s) {
        int len = s.size();
        vector<int> cache(len, -1);
        return solve(s, 0, cache);
    }
};
