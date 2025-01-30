#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


struct data {
    string st;
    int cost;
    data(string a,int c) {
        st =a;
        cost = c;

    }
};


int sortMethod(data a,data b) {

    if(a.cost==b.cost)
        return a.st<b.st;
    return a.cost<b.cost;

}



int main()
{

    int n,price;
    string str;

    vector<data>v;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>str;

        cin>>price;

        v.push_back(data(str,price));
    }

    sort(v.begin(),v.end(),sortMethod);    // eikane sortMethod() eirokom likha jabe nah... only sortMethod likte hobe


    for(int i=0;i<n;i++)
    {
        cout<<v[i].st<<" "<<v[i].cost<<endl;
    }


    return 0;
}
