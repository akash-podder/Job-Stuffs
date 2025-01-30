#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,s;

    cin>>s;

    a=s;

    reverse(s.begin(),s.end());

    cout<<s<<endl<<a;

    return 0;
}
