#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define Max 1e7

vector<int>prime;

void sieve(int n)
{
    int ara[n+1];

    for(int i=0; i<=n; i++)
    {
        ara[i]=1;
    }

    ara[0]=0;
    ara[1]=0;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(ara[i]==1)
        {
            for(int j=2; (j*i)<=n; j++)
            {
                ara[i*j]=0;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(ara[i]==1)
        {
            prime.push_back(i);
        }
    }


}




int main()
{
    map<int,int>Map;
    map<int,int>::iterator it;

    int n;

    int coun;

    cin>>n;

    sieve(n);

    for(int i=0; i<prime.size(); i++)
    {
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            Map[prime[i]]++;
        }

        if(n==1)
        {
            break;
        }
    }


    int c=0;

    for(it=Map.begin(); it!=Map.end(); it++)
    {
        c++;
        if(c==1)
        {
            cout<< it->first <<" ("<< it->second <<") ";
        }

        else
        {
            cout<<" * "<<it->first<<" ("<<it->second<<")";
        }

    }

    Map.clear();

    return 0;
}

