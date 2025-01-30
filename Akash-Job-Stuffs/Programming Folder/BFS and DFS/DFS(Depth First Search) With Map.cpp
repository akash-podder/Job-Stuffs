#include<bits/stdc++.h>

using namespace std;

int color[100001],parent[100001];

map<int, vector<int> >Map;

void DFS(int current)
{
    color[current]=1;
    for(__typeof(Map[current].begin()) it=Map[current].begin(); it!=Map[current].end(); it++)
    {
        if(color[*it]==0)
        {
            parent[*it]=current;
            DFS(*it);
        }
    }

    cout<<current<<endl;
}

int main()
{
    int n,e,a,b;

    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        Map[a].push_back(b);
        Map[b].push_back(a);
    }

    for(int i=0; i<n; i++)
    {
        if(color[i]==0)
        {
            DFS(i);
        }
    }


    return 0;
}
