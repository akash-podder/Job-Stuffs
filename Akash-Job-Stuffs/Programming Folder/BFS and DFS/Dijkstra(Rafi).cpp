#include<bits/stdc++.h>
using namespace std;
int cost[1001][1001];
int color[1001];
int dis[1001];
int prent[10001];
int p=0,k=0;
set<int>s;
map<int,vector<int> >m;

void bfs()
{
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++)
    {
        color[*it]=-1;
        dis[*it]=0;
        prent[*it]=*it;
        if(p==0)
        p=*it;
    }
    priority_queue<int>q;
    q.push(p);
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        for(__typeof(m[u].begin())it=m[u].begin();it!=m[u].end();it++)
        {
            if(color[*it]==-1)
            {
                color[*it]=2;
                dis[*it]=dis[u]+cost[u][*it];
                prent[*it]=u;
                q.push(*it);
            }
            else
            {
                if(dis[*it]>dis[u]+cost[u][*it])
               {
                dis[*it]=dis[u]+cost[u][*it];
                prent[*it]=u;
               }
            }
        }
    }
}

void printpath(int n)
{
    if(prent[n]==n)
        {
            k=1;
            return ;
        }
    printpath(prent[n]);
    cout<<prent[n]<<" ";
    k=0;
    return ;
}


int main()
{
    int n,e,a,b,c;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        m[a].push_back(b);
       // m[b].push_back(a);
        cost[a][b]=c;
        s.insert(a);
        s.insert(b);
    }

    cin>>n;

    bfs();
   // for(int i=1;i<=n;i++)
    //{
       // cout<<prent[i]<<endl;
    //}

    cout<<"Path:";

    printpath(n);

    if(k==0)
    {
        cout<<n<<endl;
    }

    else
    {
        cout<<"-1"<<endl;
    }

    cout<<"Distance: "<<dis[n]<<endl;

    return 0;
}

/*
4
1 2 2
1 3 1
2 3 6
3 4 3
4

ans: 4
path: 1 3 4

*/
