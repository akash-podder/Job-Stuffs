/*
Approach: 01
Recursive implementation without memoization
*/

#include<bits/stdc++.h>
using namespace std;

int fibonacci_number(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_number(n-1) + fibonacci_number(n-2);
}

int main()
{
    int n, i, j;
    cout<< fibonacci_number(40) << "\n";

    return 0;
}


/*
Approach: 02
Fibonacci Series Recursive implementation with memoization
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[1000];

ll fibonacci_number(ll n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        ll l, r;
        if (fib[n-1] != -1)
            l = fib[n-1];
        else
            l = fibonacci_number(n-1);

        if (fib[n-2] != -1)
            r = fib[n-2];
        else {
            r = fibonacci_number(n-2);
        }

        fib[n] = l+r;
        return fib[n];
    }
}

int main()
{
    int i, j;
    ll n;
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;
    cout<< fibonacci_number(40) << "\n";
    return 0;
}


/*
Approach: 03
Fibonacci Series - bottom-up dp
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int i, j;
    ll n, prev1, prev2, cur;
    cin>> n;
    prev1 = 0;
    prev2 = 1;
    for (i = 2; i <= n; i++) {
        cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
    }
    cout<< cur << "\n";

    return 0;
}




