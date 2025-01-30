#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
{
    int i,j,k,n,m[100][100],d,p[100];
    cin>>n;
    for(i=0; i<=n; i++) cin>>p[i];
    for(i=1; i<=n; i++) m[i][i]=0;
    for(d=1; d<n; d++)
    {
        for(i=1; i<=n-d; i++)
        {
            j=i+d;
            k=i;
            m[i][j]=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            for(k=1; k<j; k++)
            {
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout<<"Minimum Operation: "<<m[1][n];
    return 0;
}

/*
4
10 5 20 10 25

Minimum Operation: 3500
*/
