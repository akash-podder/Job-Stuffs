#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

vector<int>graph[100005];
bool visited[100005];

void dfs(int u)
{
    if(visited[u])
    {
        return;
    }
    visited[u] = true;

    for(int i = 0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        dfs(v);
    }
}


int main()
{
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        dfs(1); ///Jodi bole 1 hoche starting node
    }

    return 0;
}
