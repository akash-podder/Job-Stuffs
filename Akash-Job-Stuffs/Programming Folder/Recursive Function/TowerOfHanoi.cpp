#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void PrintPath(int Start, int End)
{
    cout << Start << " ---> " << End << endl;
}

void TowerOfHanoi(int n, int Start, int End)
{
    if (n == 1)
    {
        PrintPath(Start, End);
    }
    else
    {
        int Other = 6 - (Start + End);
        TowerOfHanoi(n - 1, Start, Other);
        PrintPath(Start, End);
        TowerOfHanoi(n - 1, Other, End);
    }
}

int main()
{
    TowerOfHanoi(3, 1, 3);
    return 0;
}