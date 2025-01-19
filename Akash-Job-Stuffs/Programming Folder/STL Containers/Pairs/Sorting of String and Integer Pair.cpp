#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int sortMethod(pair<string,int> a,pair<string,int> b)
{

    if(a.second==b.second)
    {
        return a.first<b.first;                /*  eikane "first" bolte "string" aer part bujano hochhe... arr "second" bolte pair aer "int part" bujaano hochhe*/
    }

    return a.second<b.second;

}

int main()
{
    vector<pair<string,int>>v;
    vector<pair<string,int>>::iterator v_it;

    int n;

    int value;

    string str;

    cin>>n;


    for(int i=0; i<n; i++)
    {
        cin>>str;
        cin>>value;
        v.push_back(make_pair(str,value));
    }



    sort(v.begin(),v.end(),sortMethod);     /*  eivabe nijer sort method diya sort kora jai  */

    if(!v.empty())
    {
        for(v_it=v.begin(); v_it!=v.end(); v_it++)
        {
            cout<< v_it->first <<" "<< v_it->second <<endl;
        }
    }


    v.clear();



    return 0;
}

