#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    getline(cin,s);            /*   Eivabe jekono string aer number ke int array te newa jabe....  eita UVA aer maximum GCD aer input eivabe newa jai...*/

    stringstream f(s);

    int ara[1000];
    int n,coun=0;

    while(f>>n)
    {
        ara[coun++]=n;
    }

    for(int i=0;i<coun;i++)
    {
        cout<<ara[i]<<endl;
    }

    return 0;
}
