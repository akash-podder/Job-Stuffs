#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct SortOrder
{
    bool operator()(string first,string second)
    {
        int length1=first.length();
        int length2=second.length();

        if(length1==length2)
        {
            return (first<second);
        }

        return (length1<length2);
    }
};



int main()
{
    set<string,SortOrder>Set;      /* normally "set" ae element gula sorted akare takhe.....but amra jodi nijer ichha moto sort korte chai...taile agge ekta function nite hobe... then sai function aer name "set" declare aer somoy eivabe likte hobe>>> */
    set<string>::iterator it;

    string str;
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>str;
        Set.insert(str);
    }

    for(it=Set.begin();it!=Set.end();it++)
    {
        cout<<*it<<endl;
    }


    return 0;
}
