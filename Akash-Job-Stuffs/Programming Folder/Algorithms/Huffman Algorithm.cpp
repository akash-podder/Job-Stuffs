#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int> >pq;
    queue<int>q;
    vector<int>v[90000];
    map<int,string>hc;
    map<int,char>Map;

    char ch;
    int n,i,freq;

    cout<<"how many numbers?\n";
    cin>>n;
    cout<<"enter the character and frequency\n";
    while(n--)
    {
        cin>>ch>>freq;
        Map[freq]=ch;
        pq.push(freq);
    }
    cout<<endl;

    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int sum=a+b;
        v[sum].push_back(a);
        v[sum].push_back(b);
        pq.push(sum);
    }

    q.push(pq.top());
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(i=0; i<v[top].size(); i++)
        {
            if(i==0)
            {
                hc[v[top][i]]=hc[top]+'0';
            }
            else
            {
                hc[v[top][i]]=hc[top]+'1';
            }

            if(v[v[top][i]].size()==0)
            {
                cout<<Map[v[top][i]]<<" "<<hc[v[top][i]]<<endl;
            }

            else
            {
                q.push(v[top][i]);
            }

        }
    }

    return 0;
}

/*
6
a 5
b 9
c 12
d 13
e 16
f 45
*/
