#include<iostream>

using namespace std;

int ara[1000];

int Coin_change (int n, int m)
{
    int table[n+1][m];
    for(int i=0; i<=m; ++i)
        table[0][i]=1;
    for(int j=0;j<=n;j++)
        table[j][0]=0;

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            int x=(i-ara[j-1]>=0)?table[i-ara[j-1]][j]:0;
            int y=(j>=1)?table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[n][m];
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; ++i)
        cin>>ara[i];

    cout<<Coin_change(n,m)<<endl;

    return 0;
}

/*2345 9
1 2 5 10 20 50 100 500 1000*/

