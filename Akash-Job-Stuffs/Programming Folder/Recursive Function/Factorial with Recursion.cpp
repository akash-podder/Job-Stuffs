#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

long long int fact(int n)
{
    if(n==0)
    {
        return 1;
    }

    if(n==1)
    {
        return 1;
    }

    return n*fact(n-1);
}


int main()
{
    int t,n;

    long long int x;

    cout<<"Enter A Number:";

    cin>>n;

    x=fact(n);

    cout<<"Factorial of "<<n<<" is "<<x<<endl;


    return 0;
}
