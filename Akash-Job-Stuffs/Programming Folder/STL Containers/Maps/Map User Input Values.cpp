#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int>Map;
    map<char,int>::iterator it;

    int n;

    int value;

    char key;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>key>>value;

        Map[key]=value;
    }

    for(it=Map.begin(); it!=Map.end(); it++)
    {
        //cout<<(*it).first<<" "<<(*it).second<<endl;

        cout<< it->first <<" "<< it->second <<endl;
    }




    return 0;
}
