#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[100];
    int a=0,b=1;
    int Max=-1;

    cin>>n;

    vector<int>v(n,1);

    //cout<<v.size()<<" "<<v[0]<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ara[j]<ara[i])
            {
                if(v[i]<v[j]+1)
                {
                    v[i]=v[j]+1;
                }

            }
        }
    }

    sort(v.begin(),v.end());
    cout<<v[n-1]<<endl;

    return 0;
}

/*
7
3 4 -1 0 6 2 3

ans:4
*/





/*
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[100],Max=INT_MIN;

    int a=0,b=1;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
    }

    while(a!=n-2 && b!=n-1)
    {
        if(a==b)
        {
            a=0;
            b++;
        }

        if(ara[a]<ara[b])
        {
            ara[b]=ara[a]+1;

            a++;

            if(ara[b]>Max)
            {
                Max=ara[b];
            }
        }

        else
        {
            a++;
        }
    }

    cout<<Max<<endl;

    return 0;
}
*/
