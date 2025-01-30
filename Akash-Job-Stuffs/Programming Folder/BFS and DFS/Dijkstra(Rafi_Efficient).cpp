#include<bits/stdc++.h>
using namespace std;
#define me boss
#define ll long long int
int vis[555],dis[555],cost[555][555];
vector<int>graph[1001];

struct priority
{
    bool operator () (const int&a, const int&b)
    {
        return dis[a] > dis[b];
    }

};

void bfs(int start)
{
    vis[start]=1;
    dis[start]=0;
    priority_queue<int,vector<int>,priority>q;
    q.push(start);
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            if(vis[graph[u][i]]==0)
            {
                vis[graph[u][i]]=1;
                dis[graph[u][i]]=max(dis[u],cost[u][graph[u][i]]);
                q.push(graph[u][i]);
            }
            else if(dis[graph[u][i]]>max(dis[u],cost[u][graph[u][i]]))
            {
                dis[graph[u][i]]=max(dis[u],cost[u][graph[u][i]]);
                q.push(graph[u][i]);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        int n,m,a,b,c,s;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph[a].push_back(b);
            graph[b].push_back(a);
            if(cost[a][b]==0)
            {
                cost[a][b]=c;
                cost[b][a]=c;
            }
            else
            {
                cost[a][b]=min(cost[a][b],c);
                cost[b][a]=min(cost[a][b],c);
            }
        }
        cin>>s;
        memset(dis,-1,sizeof(dis));
        printf("Case %d:\n",j+1);
        bfs(s);
        for(int i=0; i<n; i++)
        {
            if(dis[i]==-1)
                printf("Impossible\n");
            else
                printf("%d\n",dis[i]);
            graph[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));
    }

    return 0;
}
