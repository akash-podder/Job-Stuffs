#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int getAns(vector<int> weight, vector<int> value, int n, int currWeight, vector<vector<int>>& cache) {
    // if curr==-1, that means that we have Traversed all the Elements, and Total Profit will be 0 in this case
    if(n==-1){
        return 0;
    }

    if(cache[n][currWeight]!=-1){
        return cache[n][currWeight];
    }

    if(weight[n]<=currWeight){
        // Max between Take & Not Take;
        cache[n][currWeight] = max(
            value[n]+getAns(weight, value, n-1, currWeight-weight[n], cache), //take
            0 + getAns(weight, value, n-1, currWeight, cache) // NOT take
        );
        return cache[n][currWeight];
    }

    // weight[curr] > currWeight
    else{
        cache[n][currWeight] = 0 + getAns(weight, value, n-1, currWeight, cache); // NOT take
        return cache[n][currWeight];
    }
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> cache (n, vector<int>(maxWeight+1, -1)); // two Changing Variable of this DP is "maxWeight (as we are subtracting from it)" & "n (item)as we are iterating"
	return getAns(weight, value, n-1, maxWeight, cache);
}

int main(){
    int t;
    cin>>t;
    
    while (t--)
    {
        int n, maxWeight;
        cin >> n;
        vector<int> weight;
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            weight.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }
        cin >> maxWeight;
        cout << knapsack(weight, value, n, maxWeight)<<endl;
    }

    return 0;
}

/*
1
4
1 2 4 5
5 4 8 6
5

Output: 13



10
1
6 
1 
78
7
6 5 1 5 6 5 9 
5 3 4 9 6 1 1 
63
7
1 5 6 9 7 9 7 
1 7 1 5 1 7 7 
37
1
3 
4 
13
1
7 
1 
1
1
10 
8 
85
3
7 6 9 
3 3 5 
51
1
9 
6 
52
1
1 
4 
53
9
3 9 3 8 8 7 9 5 10 
5 1 6 10 1 6 3 7 5 
83

Output:
1
29
28
4
0
8
11
6
4
44
*/