#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v;
    int a,b,c,n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }

    cout<<"In which position you want to erase?"<<endl;

    cin>>b;

    v.erase(v.begin()+b);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;


    cout<<"In which position you want to insert?"<<endl;
    cin>>b;

    cout<<"Which number you want to add?"<<endl;
    cin>>c;

    v.insert(v.begin()+b,c);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;

    return 0;
}
