#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int len,i,t;
    string a,a1,a2;
    cin>>t;

    while(t--)
    {
        cin>>a;

        len=a.length();

        a1=a.substr(0,len/2);

        if(len%2==0)
        {
        a2=a.substr(len/2,len);
        }

        else if(len%2!=0)
        {
        a2=a.substr(((len/2)+1),len);
        }

        sort(a1.begin(),a1.end());  /*Sorting na kolre "abbaab" and "Rotor" aer jonno true hobe nha*/
        sort(a2.begin(),a2.end());

        if(a1==a2)
        {
            cout<<"YES"<<endl;
        }

        else
        {
            cout<<"NO"<<endl;

        }

    }

    return 0;
}
