#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int number,power,mod;

    cin>>number>>power>>mod;

    long long int ans=1;

    for(long long int i=1; i<=power; i++)
    {
        ans=((ans%mod)*(number%mod))%mod;
    }

    cout<<ans<<endl;



    return 0;
}
