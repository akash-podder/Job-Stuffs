#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int coin[100],n,m;

int coin_change(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(m<=0 && n>=1)
    {
        return 0;
    }

    return coin_change(m-1,n)+coin_change(m,n-coin[m-1]);    /*  coin_change(m-1,n) = eita mane coin take include nah korle jah asbe...  coin_change(m,n-coin[m-1])=eita mane coin take include korle jah asbe  */
}

int main()
{
    int n,m,ans;  /*  Here m=number of coins & n= the value we have to make  */
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>coin[i];
    }
    ans=coin_change(m,n);

    cout<<ans;


    return 0;
}

/*

4
3
1 2 3

ans:4 ways

*/
