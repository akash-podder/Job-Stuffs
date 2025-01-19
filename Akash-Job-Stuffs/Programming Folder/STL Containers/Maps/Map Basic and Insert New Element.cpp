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

    Map['a']=1;

    Map['b']=2;

    Map['c']=3;

    for(it=Map.begin(); it!=Map.end(); it++)
    {
        //cout<<(*it).first<<" "<<(*it).second<<endl;

        cout<< it->first <<" "<< it->second <<endl;
    }



    Map.insert(pair<char,int>('d',4));    /* Eivabe Map aer vitor new element insert korte hui  */

    it++;

    cout<< it->first <<" "<< it->second <<endl;



    Map.insert(make_pair('e',5));    /* Eivabe oo make_pair dile arr type declare korte hui nah  */

    it++;

    cout<< it->first <<" "<< it->second <<endl;



    return 0;
}
